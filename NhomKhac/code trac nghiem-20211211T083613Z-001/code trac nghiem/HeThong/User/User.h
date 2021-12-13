#pragma once
#include <iostream>
using namespace std;

class User
{
    protected:
        string ten;
        int tuoi;
        string id;
        bool gioiTinh;
        string matKhau;
        bool chucvu; // 0->hocsinh ; 1->giaovien

    public:
        User();
        User(string id, string ten, string matKhau);
        User(string id, string ten, int tuoi, bool gioiTinh, string matKhau);
        ~User();      

        string getId();
        string getTen();
        int getTuoi();
        bool getGioiTinh();
        string getMatKhau();
        bool getChucVu();

        void setId(string);
        void setTen(string);
        void setTuoi(int);
        void setGioiTinh(bool);
        void setMatKhau(string);   
        void setChucVu(bool);
};
