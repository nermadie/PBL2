#include "LichChieu.h"
#include <fstream>
#include <iomanip>
LichChieu::LichChieu()
{
}
LichChieu::LichChieu(int idf, int idp, Ca c, int ghecl, int soluongbd, int giave)
{
    this->_IDPhim = idf;
    this->_IDPhong = idp;
    this->_ThoiGian = c;
    this->_GheConLai = ghecl;
    this->_SLGhe = soluongbd;
    this->_GiaVe = giave;
}
LichChieu::LichChieu(const LichChieu &nv)
{
    this->_IDPhim = nv._IDPhim;
    this->_IDPhong = nv._IDPhong;
    this->_ThoiGian = nv._ThoiGian;
    this->_GheConLai = nv._GheConLai;
    this->_SLGhe = nv._SLGhe;
    this->_GiaVe = nv._GiaVe;
}
LichChieu::~LichChieu()
{
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
int LichChieu::GheConLai()
{
    return this->_GheConLai;
}
int LichChieu::SLGhe()
{
    return this->_SLGhe;
}
int LichChieu::GiaVe()
{
    return this->_GiaVe;
}
void LichChieu::IDPhim(int value)
{
    this->_IDPhim = value;
}
void LichChieu::IDPhong(int value)
{
    this->_IDPhong = value;
}
void LichChieu::ThoiGian(Ca value)
{
    this->_ThoiGian = value;
}
void LichChieu::GheConLai(int value)
{
    this->_GheConLai = value;
}
void LichChieu::SLGhe(int value)
{
    this->_SLGhe = value;
}
void LichChieu::GiaVe(int value)
{
    this->_GiaVe = value;
}
void LichChieu::ShowLichChieu()
{
    cout << "|    " << setw(3) << left << _IDPhong << "   | ";
    _ThoiGian.ShowDate();
    cout << " |   ";
    _ThoiGian.ShowCa();
    cout << "   |           ";
    cout << setw(3) << left << _GheConLai << "          | ";
    cout << setw(6) << left << _GiaVe << " |";
}
bool LichChieu::DateCompare(Date &d)
{
    if (_ThoiGian.Day() == d.Day() && _ThoiGian.Month() == d.Month() && _ThoiGian.Year() == d.Year())
        return 1;
    return 0;
}
bool LichChieu::IDPhimCompare(int &idp)
{
    if (idp == this->_IDPhim)
        return 1;
    return 0;
}
<<<<<<< HEAD

=======
ostream &operator<<(ostream &o, const LichChieu &nv) // Tương tự hàm ShowNV
{
    return o;
}

istream &operator>>(istream &in, LichChieu &nv)
{
    return in;
}
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
void LichChieu::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDPhim << '|';
    FileOut << _IDPhong << "|";
    _ThoiGian.InsertObjecttoFile(FileOut);
    FileOut << _GheConLai << "|";
    FileOut << _SLGhe << "|";
    FileOut << _GiaVe;
}