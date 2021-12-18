#pragma once
#include "../Object/Account/Account.cpp"
class DSAccount
{
protected:
    Account *_DSAccount;
    int _Quantity;

public:
    DSAccount();
    DSAccount(Account *, int);
    DSAccount(const DSAccount &);
    ~DSAccount();
    int Quantity();
    void AddtotheEnd(Account &);
    int FindUsername(int);
    string GivePass(int);
    void Update(const int &);
};
