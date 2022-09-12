#ifndef SCREEN_h
#define SCREEN_h

#include "Arduino.h"

class Screen
{
public:
    Screen();
    Epd epd;

    //setter
    void setIntervalTime(byte setTime);
    

    //getter
    byte getIntervalTime();    

    //描写パターン
    void designPart1();
    void designPart2();
    void designPart3();

    //画面初期化
    void initScreen();

    //描写適用
    void applyScreen();

private:
    byte intervalTime; //画面の切り替えタイムを設定
    bool screenRedesignOk;
};
#endif