#pragma once
#include "PhongChieu.h"
#include <iomanip>
#include <fstream>
PhongChieu::PhongChieu() {}

PhongChieu::PhongChieu(int id, int sl)
{
    this->_IDPhongChieu = id;
    this->_SLGhe = sl;
}
PhongChieu::PhongChieu(const PhongChieu &pc)
{
    this->_IDPhongChieu = pc._IDPhongChieu;
    this->_SLGhe = pc._SLGhe;
}
PhongChieu::~PhongChieu()
{
}
int PhongChieu::SLGhe()
{
    return this->_SLGhe;
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
    cout << "\t\t\t\t\t\t| " << setw(8) << right << this->_IDPhongChieu << "       ";
    cout << "|     " << setw(3) << right << this->_SLGhe << "      |" << endl;
}
istream &operator>>(istream &in, PhongChieu &pc)
{
    int check = 1;
    cout << "\t\t\t\t\t\tNhap so luong ghe: ";
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
    return in;
}
const PhongChieu &PhongChieu::operator=(const PhongChieu &pc)
{
    this->_IDPhongChieu = pc._IDPhongChieu;
    this->_SLGhe = pc._SLGhe;
    return *this;
}
void PhongChieu::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _IDPhongChieu << '|';
    FileOut << _SLGhe;
}