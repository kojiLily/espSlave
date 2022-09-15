#ifndef SCREEN_h
#define SCREEN_h

#include "Arduino.h"
#include <SPI.h>
#include "epd2in9b.h"
#include "imagedata.h"
#include "epdpaint.h"
#include "qrcode.h"

class Screen
{
public:
    Screen();

    //setter
    void setIntervalTime(byte setTime);

    //getter
    byte getIntervalTime();    

private:
    byte intervalTime; //画面の切り替えタイムを設定
};
#endif