#include "Phim.h"

Film::Film(int _IDP, string _FilmName, string _MainActor, string _Category, string _MovieDuration, Date _MeettingDay)
{
    this->_IDP = _IDP;
    this->_FilmName = _FilmName;
    this->_MainActor = _MainActor;
    this->_Category = _Category;
    this->_MovieDuration = _MovieDuration;
    this->_MeettingDay = _MeettingDay;
}
Film::~Film(){}

Film::Film(const Film& f)
{
    this->_IDP = f._IDP;
    this->_FilmName = f._FilmName;
    this->_MainActor = f._MainActor;
    this->_Category = f._Category;
    this->_MovieDuration = f._MovieDuration;
    this->_MeettingDay = f._MeettingDay;
}

int Film::IDP()
{
    return _IDP;
}
void Film::IDP(int value)
{
    this->_IDP = value;
}
string Film::FilmName()
{
    return _FilmName;
}
void Film::FilmName(string value)
{
    this->_FilmName = value;
}
string Film::MainActor()
{
    return _MainActor;
}
void Film::MainActor(string value)
{
    this->_MainActor = value;
}
string Film::Category()
{
    return _Category;
}
void Film::Category(string value)
{
    this->_Category = value;
}
string Film::MovieDuration()
{
    return _MovieDuration;
}
void Film::MovieDuration(string value)
{
    this->_MovieDuration = value;
}
void Film::MeetingDay(Date value)
{
    this->_MeettingDay = value;
}

void Film::ShowPhim()
{
    cout << "Ma phim: " << this->_IDP;
    cout << "Ten phim: " << this->_FilmName;
    cout << ", Cac dien vien chinh: " << this->_MainActor;
    cout << ", The loai: " << this->_Category;
    cout << ", Thoi luong phim: " << this->_MovieDuration;
    cout << ", Ngay phat hanh: ";
    _MeettingDay.ShowDate();
}

ostream& operator<<(ostream& o, const Film& f)
{
    o << "Ma phim: " << f._IDP;
    o << ", Ten phim: " << f._FilmName;
    o << ", Cac dien vien chinh: " << f._MainActor;
    o << ", The loai: " << f._Category;
    o << ", Thoi luong phim: " << f._MovieDuration;
    o << ", Ngay phat hanh: ";
    Date temp = f._MeettingDay;
    temp.ShowDate();
    return o;
}
