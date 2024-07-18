#include <LilyGo_RGBPanel.h>
#include <lvgl.h>
#include <LV_Helper.h>
#include <ui.h>
#include <TFT_eSPI.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <time.h>

#include "credential.h" // Make sure to include your credentials here

LilyGo_RGBPanel panel;
TFT_eSPI tft = TFT_eSPI();

// Define the time zone
const char* ntpServer = "pool.ntp.org";
const char* timeZone = "AST-3";

SemaphoreHandle_t mutex;
TaskHandle_t updateTimeTaskHandle = NULL;
unsigned long previousMillis = 0;
const long interval = 1000; // interval at which to update time (milliseconds)
const long ntpSyncInterval = 60000; // interval at which to sync with NTP server (milliseconds)
unsigned long previousNtpMillis = 0;
unsigned long previousMoonUpdateMillis = 0; // timestamp for the last moon update

// Function declarations
void connectToWiFi();
void updateTime(void * parameter);
void updateUILabels(String formattedTime, String ampm, String formattedDate);
void updateMoonData();
String getMoonPhase(double age);
int getMoonImageIndex(double age);

extern const lv_img_dsc_t *ui_imgset_moon_[30];

void setup(void)
{
    Serial.begin(115200); // Ensure this matches the baud rate in your serial monitor

    // Connect to WiFi
    connectToWiFi();

    // Initialize NTP client
    configTzTime(timeZone, ntpServer);

    // Initialize T-RGB, if the initialization fails, false will be returned.
    if (!panel.begin()) {
        while (1) {
            Serial.println("Error, failed to initialize T-RGB");
            delay(1000);
        }
    }

    // Call lvgl initialization
    beginLvglHelper(panel);
    ui_init();
    lv_task_handler();

    panel.setBrightness(16);

    // Create mutex
    mutex = xSemaphoreCreateMutex();

    // Create task to update time every second
    xTaskCreate(updateTime, "UpdateTime", 8192, NULL, 1, &updateTimeTaskHandle);

    // Update moon data initially
    updateMoonData();
}

void loop()
{
    lv_task_handler();
    delay(5); // Ensure lv_task_handler is called frequently
}

void connectToWiFi() {
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi...");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
}

void updateTime(void * parameter) {
    for (;;) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;

            time_t now;
            struct tm timeinfo;
            time(&now);
            localtime_r(&now, &timeinfo);

            int hours = timeinfo.tm_hour;
            int minutes = timeinfo.tm_min;
            int seconds = timeinfo.tm_sec;

            String ampm = "AM";
            if (hours >= 12) {
                ampm = "PM";
                if (hours > 12) hours -= 12;
            } else if (hours == 0) {
                hours = 12;
            }

            char timeStr[9];
            snprintf(timeStr, sizeof(timeStr), "%02d:%02d:%02d", hours, minutes, seconds);

            char dateStr[11];
            strftime(dateStr, sizeof(dateStr), "%d-%b-%y", &timeinfo);

            if (xSemaphoreTake(mutex, portMAX_DELAY)) {
                updateUILabels(String(timeStr), ampm, String(dateStr));
                xSemaphoreGive(mutex);
            }

            // Call updateMoonData every minute
            if (currentMillis - previousMoonUpdateMillis >= 60000) {
                previousMoonUpdateMillis = currentMillis;
                updateMoonData();
            }
        }

        if (currentMillis - previousNtpMillis >= ntpSyncInterval) {
            previousNtpMillis = currentMillis;
            configTzTime(timeZone, ntpServer);
            Serial.println("Synced with NTP server");
        }

        // Add a delay to ensure this task runs every second
        vTaskDelay(interval / portTICK_PERIOD_MS);
    }
}

void updateUILabels(String formattedTime, String ampm, String formattedDate) {
    lv_label_set_text(ui_Label_time, formattedTime.c_str());
    lv_label_set_text(ui_Label_ampm, ampm.c_str());
    lv_label_set_text(ui_Label_date, formattedDate.c_str());
}

void updateMoonData() {
    // Ensure WiFi is connected
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("WiFi not connected. Cannot fetch moon data.");
        return;
    }

    // Sync time with NTP server to ensure it is set correctly
    configTzTime(timeZone, ntpServer);
    delay(1000); // Wait a moment to ensure time is synced

    // Get the current date and time
    time_t now;
    struct tm timeinfo;
    time(&now);
    localtime_r(&now, &timeinfo);

    // Ensure the timeinfo structure is properly populated
    if (timeinfo.tm_year < (2023 - 1900)) { // Check if the year is valid
        Serial.println("Time not set correctly.");
        return;
    }

    // Format the date and time as required by the URL
    char dateStr[25];
    if (strftime(dateStr, sizeof(dateStr), "%Y-%m-%dT%H:%M", &timeinfo) == 0) {
        Serial.println("Failed to format date string.");
        return;
    }
    
    String url = "https://svs.gsfc.nasa.gov/api/dialamoon/";
    url += dateStr;

    // Print the URL for debugging
    Serial.print("Fetching moon data from URL: ");
    Serial.println(url);

    WiFiClientSecure client;
    client.setInsecure();  // Disable SSL certificate verification

    HTTPClient http;
    http.begin(client, url);
    int httpCode = http.GET();
    
    if (httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        Serial.println("Moon data fetched:");
        Serial.println(payload);
        
        DynamicJsonDocument doc(2048);
        deserializeJson(doc, payload);
        
        double age = doc["age"].as<double>();
        
        Serial.printf("Moon age: %.3f\n", age);
        
        if (xSemaphoreTake(mutex, portMAX_DELAY)) {
            String moonPhase = getMoonPhase(age);
            lv_label_set_text(ui_Label_phase, moonPhase.c_str());
            int imageIndex = getMoonImageIndex(age);
            lv_img_set_src(ui_Img_moon, ui_imgset_moon_[imageIndex]);
            xSemaphoreGive(mutex);
        }
        
    } else {
        Serial.printf("Failed to fetch moon data, error: %d\n", httpCode);
    }
    
    http.end();
}

String getMoonPhase(double age) {
    if (age >= 0 && age < 1.845) return "New Moon";
    else if (age >= 1.845 && age < 7.3825) return "Waxing Crescent";
    else if (age >= 7.3825 && age < 11.585) return "First Quarter";
    else if (age >= 11.585 && age < 15.775) return "Waxing Gibbous";
    else if (age >= 15.775 && age < 18.195) return "Full Moon";
    else if (age >= 18.195 && age < 22.765) return "Waning Gibbous";
    else if (age >= 22.765 && age < 26.3825) return "Last Quarter";
    else return "Waning Crescent";
}

int getMoonImageIndex(double age) {
    return (int)(age / 29.53 * 30); // Map the age to one of the 30 images
}
