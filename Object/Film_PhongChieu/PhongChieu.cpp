#include "PhongChieu.h"
#include <iomanip>
#include <fstream>
PhongChieu::PhongChieu() // Tạo phòng có min ghế và toàn bộ ghế chưa được đặt trước
{
    this->_SLGhe = _MinGhe;
    this->_Ghe = new bool[_SLGhe];
    for (int i = 0; i < _SLGhe; i++)
    {
        *(_Ghe + i) = 1;
    }
}

PhongChieu::PhongChieu(int id, bool *g, int sl)
{
    this->_IDPhongChieu = id;
    this->_Ghe = g;
    this->_SLGhe = sl;
}
PhongChieu::PhongChieu(const PhongChieu &pc)
{
    this->_IDPhongChieu = pc._IDPhongChieu;
    this->_Ghe = pc._Ghe;
    this->_SLGhe = pc._SLGhe;
}
PhongChieu::~PhongChieu()
{
    delete[] this->_Ghe;
}

int PhongChieu::IDPhongChieu()
{
    return _IDPhongChieu;
}
void PhongChieu::IDPhongChieu(int value)
{
    this->_IDPhongChieu = value;
}
void PhongChieu::ShowPhongChieu()
{
    cout << "\t\t\t\t| " << setw(8) << right << this->_IDPhongChieu << "       ";
    int soluonggheconlai = 0;
    for (int i = 0; i < this->_SLGhe; i++)
    {
        if (*(this->_Ghe + i) == 1)
            soluonggheconlai++;
    }
    cout << "| " << setw(10) << right << soluonggheconlai << "         ";
    cout << "|   " << setw(9) << right << this->_SLGhe << "          |" << endl;
}
istream &operator>>(istream &in, PhongChieu &pc)
{
    int check = 1;
    cout << "Nhap so luong ghe: ";
    while (check)
    {
        in >> pc._SLGhe;
        if (pc._SLGhe > pc._MaxGhe)
        {
            cout << "1 phong chi chua toi da " << pc._MaxGhe << " ghe! Moi ban nhap lai: ";
        }
        else if (pc._SLGhe < pc._MinGhe)
        {
            cout << "1 phong phai co toi thieu " << pc._MinGhe << " ghe! Moi ban nhap lai: ";
        }
        else
            check = 0;
    }
    pc._Ghe = new bool[pc._SLGhe];
    for (int i = 0; i < pc._SLGhe; i++)
    {
        *(pc._Ghe + i) = 1;
    }
    return in;
}
const PhongChieu &PhongChieu::operator=(const PhongChieu &pc)
{
    this->_IDPhongChieu = pc._IDPhongChieu;
    this->_SLGhe = pc._SLGhe;
    this->_Ghe = new bool[this->_SLGhe];
    for (int i = 0; i < this->_SLGhe; i++)
    {
        *(this->_Ghe + i) = *(pc._Ghe + i);
    }
    return *this;
}
void PhongChieu::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDPhongChieu << '|';
    for (int i = 0; i < _SLGhe; i++)
    {
        FileOut << *(_Ghe + i);
    }
    FileOut << '|';
    FileOut << _SLGhe;
}