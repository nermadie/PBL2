#include "LichChieu.h"
#include <fstream>
#include <iomanip>
LichChieu::LichChieu()
{
    this->_Ghe = nullptr;
    this->_SLGhe = 0;
}
LichChieu::LichChieu(int idf, int idp, Ca c, bool *ghe, int soluong)
{
    this->_IDPhim = idf;
    this->_IDPhong = idp;
    this->_ThoiGian = c;
    this->_Ghe = ghe;
    this->_SLGhe = soluong;
}
LichChieu::LichChieu(const LichChieu &nv)
{
    this->_IDPhim = nv._IDPhim;
    this->_IDPhong = nv._IDPhong;
    this->_ThoiGian = nv._ThoiGian;
    this->_Ghe = nv._Ghe;
    this->_SLGhe = nv._SLGhe;
}
LichChieu::~LichChieu()
{
    delete[] this->_Ghe;
}
int LichChieu::IDPhim()
{
    return this->_IDPhim;
}
int LichChieu::IDPhong()
{
    return this->_IDPhong;
}
Ca LichChieu::ThoiGian()
{
    return this->_ThoiGian;
}
void LichChieu::ShowLichChieu()
{
    cout << _IDPhim << '|';
    cout << _IDPhong << "|";
    cout << _ThoiGian;
    for (int i = 0; i < _SLGhe; i++)
    {
        cout << *(this->_Ghe + i);
    }
    cout << "|";
    cout << _SLGhe;
}
ostream &operator<<(ostream &o, const LichChieu &nv) // Tương tự hàm ShowNV
{
    return o;
}

istream &operator>>(istream &in, LichChieu &nv)
{
    return in;
}
void LichChieu::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDPhim << '|';
    FileOut << _IDPhong << "|";
    _ThoiGian.InsertObjecttoFile(FileOut);
    for (int i = 0; i < _SLGhe; i++)
    {
        FileOut << *(this->_Ghe + i);
    }
    FileOut << "|";
    FileOut << _SLGhe;
}