#pragma once
#include "HocSinh.h"

HocSinh::HocSinh()
{
    this->id = "";
    this->ten = "";  
    this->tuoi = 0;
    this->gioiTinh = 0;
    this->matKhau = "";
    this->chucvu = 0;
}

HocSinh::HocSinh(string id, string ten, int tuoi, bool gioiTinh, string matKhau)
{
    this->id = id;
    this->ten = ten;
    this->tuoi = tuoi;
    this->gioiTinh = gioiTinh;
    this->matKhau = matKhau;
    this->chucvu = 0;
}

HocSinh::HocSinh(const HocSinh& x)
{
    this->id = x.id;
    this->ten = x.ten;
    this->tuoi = x.tuoi;
    this->gioiTinh = x.gioiTinh;
    this->matKhau = x.matKhau;
    this->chucvu = 0;
}

HocSinh::~HocSinh()
{
    
}