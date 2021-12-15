#include "Date.h"
class Time : public Date
{
private:
    int hh;
    int mm;

public:
    Time();
    Time(int, int, Date);
    Time(int, int, int, int, int);
    Time(const Time &);
    ~Time();
    void ShowTime();
    void ShowDateTime();
    friend ostream &operator<<(ostream &, const Time &);
    friend istream &operator>>(istream &, Time &);
};
