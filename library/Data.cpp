#include "Arduino.h"
#include "Data.h"

//コンストラクタ
Data::Data()
{
    this->id = 000;
    this->nameFirst = "null";
    this->nameLast = "null";
    this->situate = "null";
    this->link = "null";
    this->department = "null";
}

// setter
void Data::setId(byte value)
{
    this->id = value;
}
void Data::setNameFirst(String value)
{
    this->nameFirst = value;
}
void Data::setNameLast(String value)
{
    this->nameLast = value;
}
void Data::setSituate(String value)
{
    this->situate = value;
}
void Data::setLink(String value)
{
    this->link = value;
}
void Data::setDepartment(String value)
{
    this->department = value;
}
void Data::setAll(byte id, String nameFirst, String nameLast, String situate, String link, String department)
{
    this->id = id;
    this->nameFirst = nameFirst;
    this->nameLast = nameLast;
    this->situate = situate;
    this->link = link;
    this->department = department;
}

// getter
byte Data::getId()
{
    return this->id;
}
String Data::getNameFirst()
{
    return this->nameFirst;
}
String Data::getNameLast()
{
    return this->nameLast;
}
String Data::getSituate()
{
    return this->situate;
}
String Data::getLink()
{
    return this->link;
}
String Data::getDepartment()
{
    return this->department;
}

//初期化
void Data::formatData()
{
    this->id = 000;
    this->nameFirst = "null";
    this->nameLast = "null";
    this->situate = "null";
    this->link = "null";
    this->department = "null";
}