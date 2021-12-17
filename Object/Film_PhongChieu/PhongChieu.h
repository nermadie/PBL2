#include <iostream>
using namespace std;
class PhongChieu
{
private:
    int _IDPhongChieu;
    int _SLGhe;
    const int _MaxGhe = 40;
    const int _MinGhe = 10;

public:
    PhongChieu();
    PhongChieu(int, int);
    PhongChieu(const PhongChieu &);
    ~PhongChieu();
    void ShowPhongChieu();
    int IDPhongChieu();
    void IDPhongChieu(int);
    friend istream &operator>>(istream &, PhongChieu &);
    const PhongChieu &operator=(const PhongChieu &);
    void InsertObjecttoFile(ofstream &);
};