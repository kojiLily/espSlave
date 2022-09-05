#include "Arduino.h"
#include "Data.h"
#include "Screen.h"

//コンストラクタ
Screen::Screen()
{
    this->intervalTime=0;
}

// setter
void Screen::setIntervalTime(byte setTime)
{
    this->intervalTime=setTime;
}

// getter
byte Screen::getIntervalTime() 
{
    return this->intervalTime;
}

