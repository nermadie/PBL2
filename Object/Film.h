#include <iostream>
using namespace std;
class Film
{
private:
    int _IDFilm;
    string _FilmName;
    string _MainActor;
    string _Category;   // Thể loại
    int _MovieDuration; // Phút

public:
    Film();
    Film(int, string, string, string, int);
    ~Film();
    Film(const Film &);
    void ShowPhim();
    int IDFilm();
    void IDFilm(int);
    void FilmName(string);
    void MainActor(string);
    void Category(string);
    void MovieDuration(int);
    friend ostream &operator<<(ostream &, const Film &);
};