#ifndef SCREEN_h
#define SCREEN_h

#include "Arduino.h"

class Screen
{
public:
    Screen();
    Epd epd;
    QRCode qrcode;

    //setter
    void setIntervalTime(byte setTime);
    

    //getter
    byte getIntervalTime();    

    //描写パターン
    void designPart1(Data receive_data);
    void designPart2();
    void designPart3();
    void designQR(int set_x, int set_y, String url);

    //画面初期化
    void initScreen();

    //描写適用
    void applyScreen();

    //バッファ初期化
    void initEpd();

private:
    byte intervalTime; //画面の切り替えタイムを設定
    bool screenRedesignOk;
};
#endif