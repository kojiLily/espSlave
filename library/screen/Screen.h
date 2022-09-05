#ifndef SCREEN_h
#define SCREEN_h

#include "Arduino.h"

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