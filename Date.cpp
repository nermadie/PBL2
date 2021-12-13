#include "Date.h"
Date::Date() {}
Date::Date(int d, int m, int y) : _Day(d), _Month(m), _Year(y) {}
Date::Date(const Date &d)
{
    this->_Day = d._Day;
    this->_Month = d._Month;
    this->_Year = d._Year;
}
Date::~Date() {}
void Date::ShowDate()
{
    if (_Day < 10)
    {
        cout << 0 << _Day << "/";
    }
    else
        cout << _Day << "/";
    if (_Month < 10)
    {
        cout << 0 << _Month << "/";
    }
    else
        cout << _Month << "/";
    cout << _Year;
}
ostream &operator<<(ostream &o, Date &d)
{
    if (d._Day < 10)
    {
        o << 0 << d._Day << "/";
    }
    else
        o << d._Day << "/";
    if (d._Month < 10)
    {
        o << 0 << d._Month << "/";
    }
    else
        o << d._Month << "/";
    o << d._Year;
    return o;
}
istream &operator>>(istream &in, Date &d)
{
    int check;
    char separator;
    int dd, mm, yyyy;
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
    d._Day = dd;
    d._Month = mm;
    d._Year = yyyy;
    return in;
}
