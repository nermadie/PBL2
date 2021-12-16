#pragma once
#include <iostream>
using namespace std;
class Account
{
private:
    int _IDNguoiDung;
    string _Password;

public:
    Account();
    Account(int, string);
    Account(const Account &);
    ~Account();
    void IDNguoiDung(int);
    void Password(string);
    void NewAccount(Account &);
    void InsertObjecttoFile(ofstream &);
};