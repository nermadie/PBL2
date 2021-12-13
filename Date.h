#include <iostream>
using namespace std;
class Date
{
protected:
    int _Day, _Month, _Year;

public:
    Date();
    Date(int, int, int);
    Date(const Date &);
    ~Date();
    void ShowDate();
    friend istream &operator>>(istream &, Date &);
};