#include <esp_now.h>
#include <WiFi.h>
#include "../../library/data/Data.h"
#include "../../library/screen/Screen.h"
#include <SPI.h>
#include "epd2in9b.h"
#include "imagedata.h"
#include "epdpaint.h"

Data main_data;
Screen screen;

void data_receive(const unit8_t *mac, const unit8_t *incomingData, int len)
{
    memcpy(&main_data, incomingData, sizeof(main_data));//データをこっちのDataクラス領域にコピー
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

    main_data.setAll(0, "yamada", "Tarou", "breaking", "github.com", "labor");

    screen.initEpd();
    printdata(main_data);
    screen.initScreen();
    for (int i = 0; i < 300; i += 60)
    {
        screen.designQR(10, i, main_data.getLink());
        screen.designQR(70, i, main_data.getLink());
    }
    screen.applyScreen();
}

void loop()
{
    // none;
}