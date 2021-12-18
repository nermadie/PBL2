#pragma once
#include <iostream>
#include <conio.h>
#include "../KhachHang/DSAccount.cpp"
#include "../QuanLy/AccountQL/DSAccountQL.cpp"
#include "../MucLuc/MucLuc.cpp"
#include <string.h>
using namespace std;

class SignIn
{
public:
    static void DangNhapQuaSoLanQuyDinh();
    static int DangNhap();
};
