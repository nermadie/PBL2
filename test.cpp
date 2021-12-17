#include "./Application/QuanLyAll.cpp"
#include "./Utilis/Utilis.cpp"
int main()
{
    try
    {
        TextColor(15);
        // QuanLyNhanVien::DanhSachNhanVien();
        // QuanLyNhanVien::SuaThongTinNhanVien();
        // QuanLyNhanVien::TimKiemNhanVienTheoID();
        // QuanLyNhanVien::XoaNhanVien();
        // QuanLyNhanVien::ThemNhanVien();
        // QuanLyPhim::DanhSachPhim();
        // QuanLyPhim::ThemPhim();
        // QuanLyPhim::XoaPhim();
        // QuanLyPhim::SuaThongTinPhim();
        // QuanLyPhim::TimKiemPhimTheoIDPhim();
        // QuanLyLichChieu::ThemLichChieu();
        // QuanLyLichChieu::XoaLichChieu();
        QuanLyLichChieu::SuaThongTinLichChieu();
    }
    catch (const char *msg)
    {
        cout << endl
             << msg;
    }
    catch (string msg)
    {
        cout << endl
             << msg;
    }
    return 0;
}