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

//描写パターン1
void Screen::designPart1()
{

}
//描写パターン2
void Screen::designPart2()
{
    
}
//描写パターン3
void Screen::designPart3()
{
    
}
//画面初期化
void Screen::initScreen()
{
    epd.ClearFrame();
}

//画面の適用
void Screen::applyScreen()
{
    epd.DispalyFrame();
}
