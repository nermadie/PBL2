#include "Time.h"
Time::Time() {}
Time::Time(int hh, int mm, Date d) :
{
}
Time::Time(int, int, int, int, int);
Time::Time(const Time &);
Time::~Time();
void Time::ShowTime();
void Time::ShowDateTime();
friend ostream &operator<<(ostream &, const Time &);
friend istream &operator>>(istream &, Time &);