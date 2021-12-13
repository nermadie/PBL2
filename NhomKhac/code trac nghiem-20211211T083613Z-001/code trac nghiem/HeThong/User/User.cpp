#pragma once
#include "User.h"

User::User()
{
    this->id = "";
    this->ten = "";  
    this->tuoi = 0;
    this->gioiTinh = 0;
    this->matKhau = "";
}

User::User(string id, string ten, string matKhau)
{
    this->id = id;
    this->ten = ten;
    this->matKhau = matKhau;
}

User::User(string id, string ten, int tuoi, bool gioiTinh, string matKhau)
{
    this->id = id;
    this->ten = ten;
    this->tuoi = tuoi;
    this->gioiTinh = gioiTinh;
    this->matKhau = matKhau;
}

User::~User()
{
    
}

string User::getId()
{
    return this->id;
}
        
string User::getTen()
{
    return this->ten;
}

int User::getTuoi()
{
    return this->tuoi;
}
bool User::getGioiTinh()
{
    return this-> gioiTinh;
}

string User::getMatKhau()
{
    return this->matKhau;
}

bool User::getChucVu()
{
    return this->chucvu;
}

void User::setId(string s)
{
    this->id = s;
}

void User::setTen(string s)
{
    this->ten = s;
}

void User::setTuoi(int n)
{
    this->tuoi = n;
}

void User::setGioiTinh(bool x)
{
    this->gioiTinh = x;
}

void User::setMatKhau(string s)
{
    this->matKhau = s;
}

void User::setChucVu(bool cv)
{
    this->chucvu = cv;
}

