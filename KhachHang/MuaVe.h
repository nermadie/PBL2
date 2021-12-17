#pragma once
#include "../QuanLy/LichChieu/QLLC.cpp"
#include <iomanip>
void TextColor(int);
void InTienVe(int);
class MuaVe
{
public:
    static void XemDanhSachLichChieuHienCo();
    static void XemDanhSachLichChieuTheoNgay();
    static void XemDanhSachPhimHienCo();
    static void XemDanhSachLichChieutheoPhim();
    static void MuaVeXemPhim(int);
    static void XemLichSuMuaVe(int);
};
