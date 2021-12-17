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
    int IDNguoiDung();
    string Password();
    void IDNguoiDung(int);
    void Password(string);
    friend istream &operator>>(istream &, Account &);
    void InsertObjecttoFile(ofstream &);
};