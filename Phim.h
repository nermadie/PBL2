#include "Date.h"
#include <iostream>
using namespace std;
class Film
{
    private:
        int _IDP;
        string _FilmName;
        string _MainActor;
        string _Category; // Thể loại
        string _MovieDuration; // Phút
        Date _MeettingDay;
    public:
        Film(int, string , string , string , string , Date);
        ~Film();
        Film(const Film&);
        void ShowPhim();
        int IDP();
        void IDP(int);
        string FilmName();
        void FilmName(string);
        string MainActor();
        void MainActor(string);
        string Category();
        void Category(string);
        string MovieDuration();
        void MovieDuration(string);
        void MeetingDay(Date);
        friend ostream& operator<<(ostream&, const Film&);
};