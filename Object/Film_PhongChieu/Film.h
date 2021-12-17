#include <iostream>
using namespace std;
class Film
{
protected:
    int _IDFilm;
    string _FilmName;
    string _MainActor;
    string _Category;
    int _MovieDuration;

public:
    Film();
    Film(int, string, string, string, int);
    Film(const Film &);
    ~Film();
    void ShowPhim();
    int IDFilm();
    void IDFilm(int);
    string FilmName(); // Dành cho hàm QLLC
    friend istream &operator>>(istream &, Film &);
    void InsertObjecttoFile(ofstream &);
};