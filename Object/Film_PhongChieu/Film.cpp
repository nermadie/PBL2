#pragma once
#include "Film.h"
#include <iomanip>
#include <fstream>
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
Film::Film(const Film &f)
{
    this->_IDFilm = f._IDFilm;
    this->_FilmName = f._FilmName;
    this->_MainActor = f._MainActor;
    this->_Category = f._Category;
    this->_MovieDuration = f._MovieDuration;
}
Film::~Film() {}

int Film::IDFilm()
{
    return _IDFilm;
}
void Film::IDFilm(int value)
{
    this->_IDFilm = value;
}
string Film::FilmName()
{
    return this->_FilmName;
}
// void Film::FilmName(string value)
// {
//     this->_FilmName = value;
// }
// void Film::MainActor(string value)
// {
//     this->_MainActor = value;
// }
// void Film::Category(string value)
// {
//     this->_Category = value;
// }
// void Film::MovieDuration(int value)
// {
//     this->_MovieDuration = value;
// }
void Film::ShowPhim()
{
    cout << "\t\t| " << setw(7) << right << this->_IDFilm << " ";
    cout << "| " << setw(40) << left << this->_FilmName;
    cout << "| " << setw(38) << left << this->_MainActor << " ";
    cout << "| " << setw(15) << left << this->_Category;
    cout << "|   " << setw(4) << right << this->_MovieDuration << "\'"
         << "    |" << endl;
}
istream &operator>>(istream &in, Film &p)
{
    int check;
<<<<<<< HEAD
    cout << "\t\t\t\t\t\tNhap ten phim: ";
    char str[100];
    fflush(stdin);
    in.getline(str, sizeof(str)); // Trường hợp đặc biệt
    p._FilmName = str;
    cout << "\t\t\t\t\t\tNhap dien vien chinh: ";
    fflush(stdin);
    in.getline(str, sizeof(str));
    p._MainActor = str;
    cout << "\t\t\t\t\t\tNhap the loai phim: ";
    fflush(stdin);
    in.getline(str, sizeof(str));
    p._Category = str;
    cout << "\t\t\t\t\t\tNhap thoi luong phim: ";
=======
    cout << "Nhap ten phim: ";
    char str[100];
    in.getline(str, sizeof(str)); // Trường hợp đặc biệt
    p._FilmName = str;
    cout << "Nhap dien vien chinh: ";
    fgets(str, 100, stdin);
    in.getline(str, sizeof(str));
    p._MainActor = str;
    cout << "Nhap the loai phim: ";
    fgets(str, 100, stdin);
    in.getline(str, sizeof(str));
    p._Category = str;
    cout << "Nhap thoi luong phim: ";
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
    in >> p._MovieDuration;
    return in;
}
void Film::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDFilm << '|';
    FileOut << _FilmName << '|';
    FileOut << _MainActor << '|';
    FileOut << _Category << '|';
    FileOut << _MovieDuration;
}