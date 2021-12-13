#pragma once
#include <iostream>
#include "../HeThong/DeThi/DeThi.cpp"
using namespace std;

class TrangChu
{  
    public:
        static void HienThiNhiemVu();
        static void HienThi();
        
};

class TrangHocSinh
{
    public:
        static void XemThongTinHocSinh(string id);
        static void HienThiNhiemVu();
        static void HienThi(string id);
        static void XemDe(string);
        static void LamDe(string, string);
        static void XemDiemThi(string);
    
};

class TrangGiaoVien
{
    public:
        static void XemThongTinGiaoVien(string id);
        static void HienThiNhiemVu();
        static void HienThi(string id);
        static void HienThiTuyChonDoiVoiHocSinh();
        static void TuyChonDoiVoiHocSinh();
        static void HienThiTuyChonDoiVoiDeThi();
        static void TuyChonDoiVoiDeThi();
        static void XemDe(string id);
};


