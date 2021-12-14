#include <iostream>
// #include "../Library/List/List.cpp"
class PhongChieu;
using namespace std;
class Film
{
private:
    int _IDFilm;
    string _FilmName;
    string _MainActor;
    string _Category;   // Thể loại
    int _MovieDuration; // Phút
    // List<PhongChieu> *_PhongChieu;

public:
    Film();
    Film(int, string, string, string, int);
    ~Film();
    Film(const Film &);
    void ShowPhim();
    int IDFilm();
    void IDFilm(int);
    // void FilmName(string);
    // void MainActor(string);
    // void Category(string);
    // void MovieDuration(int);
    friend istream &operator>>(istream &, Film &);
    void InsertObjecttoFile(ofstream &);
};