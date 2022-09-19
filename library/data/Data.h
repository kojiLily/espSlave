#ifndef DATA_h
#define DATA_h

#include "Arduino.h"

class Data
{
public:
    Data();

    // setter
    void setId(byte value);
    void setNameFirst(String value);
    void setNameLast(String value);
    void setSituate(String value);
    void setLink(String value);
    void setDepartment(String value);
    void setAll(byte id, String nameFirst, String nameLast, String situate, char* link, String department);

    // getter
    byte getId();
    String getNameFirst();
    String getNameLast();
    String getSituate();
    String getLink();
    String getDepartment();

    //初期化
    void formatData();

private:
    byte id;           //管理id
    String nameFirst;  //ファーストネーム
    String nameLast;   //ラストネーム
    String situate;    //"研修中","休憩中など"
    String link;       // linktreeのリンク(https://の部分は不要)
    String department; //部署,(部長、アルバイト、リーダなど)
};
#endif