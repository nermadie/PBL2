#pragma once
#include "GiaoVien.h"

GiaoVien::GiaoVien()
{
    this->chucvu = 1;
}

GiaoVien::GiaoVien (string id, string ten, int tuoi, bool gioiTinh, string matKhau)
    : User(id, ten, tuoi, gioiTinh, matKhau)
{
    this->chucvu = 1;
}

GiaoVien::GiaoVien(const GiaoVien& x)
{   
    this->id = x.id;
    this->ten = x.ten;
    this->tuoi = x.tuoi;
    this->gioiTinh = x.gioiTinh;
    this->matKhau = x.matKhau;
    this->chucvu = 1;
}

GiaoVien::~GiaoVien()
{

}

