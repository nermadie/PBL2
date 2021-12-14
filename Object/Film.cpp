#include "Film.h"
#include <iomanip>

Film::Film()
{
}

Film::Film(int id, string fn, string ma, string ca, int md)
{
    this->_IDFilm = id;
    this->_FilmName = fn;
    this->_MainActor = ma;
    this->_Category = ca;
    this->_MovieDuration = md;
}
Film::~Film() {}

Film::Film(const Film &f)
{
    this->_IDFilm = f._IDFilm;
    this->_FilmName = f._FilmName;
    this->_MainActor = f._MainActor;
    this->_Category = f._Category;
    this->_MovieDuration = f._MovieDuration;
}

int Film::IDFilm()
{
    return _IDFilm;
}
void Film::IDFilm(int value)
{
    this->_IDFilm = value;
}
void Film::FilmName(string value)
{
    this->_FilmName = value;
}
void Film::MainActor(string value)
{
    this->_MainActor = value;
}
void Film::Category(string value)
{
    this->_Category = value;
}
void Film::MovieDuration(int value)
{
    this->_MovieDuration = value;
}
void Film::ShowPhim()
{
    cout << "+=================================================================+";
    cout << "|                    ** DANH SACH PHIM **                         |";
    cout << "Ma phim: " << this->_IDFilm;
    cout << ", Ten phim: " << this->_FilmName;
    cout << ", Cac dien vien chinh: " << this->_MainActor;
    cout << ", The loai: " << this->_Category;
    cout << ", Thoi luong phim: " << this->_MovieDuration << "\'";
}
