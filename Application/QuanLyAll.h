#pragma once
#include "../QuanLy/LichChieu/QLLC.cpp"
#include "../QuanLy/NhanVien/QLNV.cpp"
#include "../QuanLy/KhachHang/QLKH.cpp"
class DoanhThu
{
public:
    static void TongDoanhThu_Toanbo();
    static void ThongKePhimAnKhach();
    static void ThongKeKhungGio();
};

class QuanLyNhanVien
{
public:
    static void DanhSachNhanVien();
    static void ThemNhanVien();
    static void XoaNhanVien();
    static void SuaThongTinNhanVien();
    static void TimKiemNhanVienTheoID();
};

class QuanLyPhim
{
public:
    static void DanhSachPhim();
    static void ThemPhim();
    static void XoaPhim();
    static void SuaThongTinPhim();
    static void TimKiemPhimTheoIDPhim();

};

class QuanLyLichChieu
{
public:
    static void DanhSachLichChieu();
    static void ThemLichChieu();
    static void XoaLichChieu();
    static void SuaThongTinLichChieu();
};

class QuanLyPhongChieu
{
public:
    static void DanhSachPhongChieu();
    static void ThemPhongChieu();
    static void XoaPhongChieu();
    static void SuaThongTinPhongChieu();
};

class QuanLyKhachHang
{
public:
    static void DanhSachKhachHang();
    static void TimKiemKhachTheoIDKhachHang();
};

class QuanLyTaiKhoanMatKhau
{
    static int DangNhap();
    static void DangNhapQuaSoLanQuyDinh(); 
    static void NhapThongTinKhachHang();
};
