#include "Account.h"
Account::Account() {}
Account::Account(int id, string p) : _IDNguoiDung(id), _Password(p) {}
Account::Account(const Account &d)
{
    this->_IDNguoiDung = d._IDNguoiDung;
    this->_Password = d._Password;
}
Account::~Account() {}
void Account::IDNguoiDung(int value)
{
    this->_IDNguoiDung = value;
}
void Account::Password(string value)
{
    this->_Password = value;
}
void NewAccount(Account &acc)
{
    string a, b;
    while (1)
    {
        cin >> a;
        cout << "Xac nhan password ban vua nhap: ";
        cin >> b;
        if (a == b)
        {
            cout << "Mat khau da duoc xac nhan!";
            break;
        }
        else
            cout << "Mat khau khong trung khop!!Moi ban nhap lai mat khau: ";
    }
    acc.Password(a);
}
void Account::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDNguoiDung << "|";
    FileOut << _Password;
}