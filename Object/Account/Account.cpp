#pragma once
#include "Account.h"
#include <fstream>
Account::Account() {}
Account::Account(int id, string p) : _IDNguoiDung(id), _Password(p) {}
Account::Account(const Account &d)
{
    this->_IDNguoiDung = d._IDNguoiDung;
    this->_Password = d._Password;
}
Account::~Account() {}
int Account::IDNguoiDung()
{
    return this->_IDNguoiDung;
}
string Account::Password()
{
    return this->_Password;
}
void Account::IDNguoiDung(int value)
{
    this->_IDNguoiDung = value;
}
void Account::Password(string value)
{
    this->_Password = value;
}
istream &operator>>(istream &in, Account &acc)
{
    string a, b;
    while (1)
    {
        in >> a;
        cout << "Xac nhan password ban vua nhap: ";
        in >> b;
        if (a == b)
        {
            cout << "Mat khau da duoc xac nhan!";
            break;
        }
        else
            cout << "Mat khau khong trung khop!!Moi ban nhap lai mat khau: ";
    }
    acc._Password = a;
    return in;
}
void Account::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDNguoiDung << "|";
    FileOut << _Password;
}