#pragma once
#include "Ca.h"
#include <iostream>
using namespace std;
Ca::Ca() {}
Ca::Ca(int day, int month, int year, int time) : Date(day, month, year), _Hour(time) {}
Ca::Ca(const Ca &c)
{
    this->_Day = c._Day;
    this->_Month = c._Month;
    this->_Year = c._Year;
    this->_Hour = c._Hour;
}
Ca::~Ca() {}
int Ca::Day()
{
    return this->_Day;
}
int Ca::Month()
{
    return this->_Month;
}
int Ca::Year()
{
    return this->_Year;
}
int Ca::Hour()
{
    return this->_Hour;
}
void Ca::ShowCa()
{
    if (_Hour < 10)
    {
        cout << 0 << _Hour << ":"
             << "00";
    }
    else
        cout << _Hour << ":"
             << "00";
}
ostream &operator<<(ostream &o, const Ca &c)
{
    if (c._Hour < 10)
    {
        o << 0 << c._Hour << ":"
          << "00";
    }
    else
        o << c._Hour << ":"
          << "00";
    return o;
}
istream &operator>>(istream &in, Ca &c)
{
    int check = 0, hour;
    cout << "Nhap ca (Co cac ca: 8h, 11h, 14h, 17h, 20h, 23h): ";
    while (!check)
    {
        in >> hour;
        if (hour == 8 || hour == 11 || hour == 14 || hour == 17 || hour == 20 || hour == 23)
        {
            check = 1;
            c._Hour = hour;
        }
        else
        {
            cout << "Chi phuc vu cac ca: 8h, 11h, 14h, 17h, 20h, 23h!" << endl;
            cout << "Moi ban nhap lai: ";
        }
    }
    char separator;
    int dd, mm, yyyy;
    check = 0;
    cout << "Nhap ngay/thang/nam: ";
    do
    {
        if (check == 1)
            cout << "Ngay khong hop le, xin moi ban nhap lai :";
        check = 0;
        in >> dd >> separator >> mm >> separator >> yyyy;
        if (yyyy < 0)
            check = 1;
        else if (mm < 1 || mm > 12)
            check = 1;
        else if (mm == 2)
        {
            if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
            {
                if (dd > 29 || dd < 1)
                    check = 1;
            }
            else
            {
                if (dd > 28 || dd < 1)
                    check = 1;
            }
        }
        else if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        {
            if (dd > 31 || dd < 1)
                check = 1;
        }
        else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        {
            if (dd > 30 || dd < 1)
                check = 1;
        }
    } while (check);
    c._Day = dd;
    c._Month = mm;
    c._Year = yyyy;
    return in;
}
bool Ca::operator==(const Ca &c)
{
    return (this->_Day == c._Day &&
            this->_Month == c._Month &&
            this->_Year == c._Year &&
            this->_Hour == c._Hour);
}
void Ca::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _Day << "/";
    FileOut << _Month << "/";
    FileOut << _Year << ":";
    FileOut << _Hour << "|";
}