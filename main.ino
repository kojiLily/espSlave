#include <esp_now.h>
#include <WiFi.h>
#include "library/Data.h"
#include "library/Screen.h"

Data main_data;

void data_receive(const unit8_t *mac, const unit8_t *incomingData, int len)
{
    memcpy(&main_data, incomingData, sizeof(main_data));
}


void setup()
{
    Serial.begin(115200);   //シリアル通信速度設定
    WiFi.mode = (WIFI_STA); // wifi情報を出力

    if (esp_now_init() != ESP_OK)
    {
        Serial.println("ESP-NOW ERROR!!");
    }

    esp_now_register_recv_cb(data_receive); //データを受け取った時に動作する関数を設定
}

void loop()
{
    // none;
}