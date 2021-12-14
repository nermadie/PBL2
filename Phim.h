#include "Date.h"
#include <iostream>
using namespace std;
class Film
{
protected:
    int _IDP;
    string _FilmName;
    string _MainActor;
    string _Category;      // Thể loại
    string _MovieDuration; // Phút
    Date _MeettingDay;

public:
    Film();
    Film(int, string, string, string, string, Date);
    ~Film();
    Film(const Film &);
    void ShowPhim();
    int IDP();
    void IDP(int);
    void FilmName(string);
    void MainActor(string);
    void Category(string);
    void MovieDuration(string);
    void MeetingDay(Date);
    friend ostream &operator<<(ostream &, const Film &);
};