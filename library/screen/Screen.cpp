#include "Arduino.h"
#include "Data.h"
#include "Screen.h"


#define COLORED 0
#define UNCOLORED 1

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
void Screen::designPart1(Data receive_data)
{
    epd.ClearFrame();
    unsigned char image3[230 * 24];
    Paint paint3(image3, 24, 230);
    paint3.Clear(UNCOLORED);
    paint3.SetRotate(ROTATE_270);
    paint3.DrawStringAt(0, 0, receive_data.getNameFirst().c_str(), &Font24, COLORED);
    epd.SetPartialWindowRed(paint3.GetImage(), 10, 0, paint3.GetWidth(), paint3.GetHeight());

    Paint paint4(image3, 24, 230);
    paint4.Clear(UNCOLORED);
    paint4.SetRotate(ROTATE_270);
    paint4.DrawStringAt(0, 0, receive_data.getNameLast().c_str(), &Font24, COLORED);
    epd.SetPartialWindowBlack(paint4.GetImage(), 42, 0, paint4.GetWidth(), paint4.GetHeight());

    Paint paint5(image3, 24, 230);
    paint5.Clear(UNCOLORED);
    paint5.SetRotate(ROTATE_270);
    paint5.DrawStringAt(0, 0, receive_data.getLink().c_str(), &Font24, COLORED);
    epd.SetPartialWindowRed(paint5.GetImage(), 72, 0, paint5.GetWidth(), paint5.GetHeight());
}
//描写パターン2
void Screen::designPart2()
{
    
}
//描写パターン3
void Screen::designPart3()
{
    
}

//描写パターンQR
void Screen::designQR(int set_x, int set_y, String url)
{
    uint8_t qrcodeData[qrcode_getBufferSize(6)];
    qrcode_initText(&qrcode, qrcodeData, 6, ECC_HIGH, url.c_str());

    static unsigned char imageqr[7042];

    Paint paintqr(imageqr, qrcode.size * 2 + 2, qrcode.size * 2 + 2);
    paintqr.Clear(UNCOLORED);
    paintqr.SetRotate(ROTATE_270);

    for (uint8_t y = 0; y < qrcode.size; y++)
    {
        for (uint8_t x = 0; x < qrcode.size; x++)
        {
            if (qrcode_getModule(&qrcode, x, y))
            {
                paintqr.DrawRectangle(2 * x + 1, 2 * y + 1, 2 * x + 2, 2 * y + 2, COLORED);
            }
            else
            {
                paintqr.DrawRectangle(2 * x + 1, 2 * y + 1, 2 * x + 2, 2 * y + 2, UNCOLORED);
            }
        }
    }
    this.epd.SetPartialWindowRed(paintqr.GetImage(), set_x, set_y, paintqr.GetWidth(), paintqr.GetHeight());
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

//バッファ初期化
void Screen::initEpd()
{
    if(epd.Init()!=0)
    {
        Serial.print("e-paper init failded");
        return;
    }
}