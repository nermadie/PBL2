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