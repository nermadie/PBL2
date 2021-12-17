#include "./KhachHang/MuaVe.h"
// #include "./KhachHang/Register.cpp"
// #include "QuanLy/AccountQL/DSAccount.cpp"
// #include "./DangNhap_DanggKy/SignIn.cpp"
#include "QuanLy/Doanhthu/DoanhThu.h"
#include "./Utilis/Utilis.cpp"
int main()
{
    try
    {
        TextColor(15);
        // SignIn a;
        // Register::NhapThongTinKhachHang();
        // DSAccount temp;
        // Account a(-2, "quanly");
        // temp.AddtotheEnd(a);

        // int id = SignIn::DangNhap();
        // if (id > 0)
        //     MenuKhachHang(id);
        // else
        //     MenuQuanLy();
        MuaVe::MuaVeXemPhim(1);
        MuaVe::XemLichSuMuaVe(1);
        DoanhThu::TongDoanhThu_Toanbo();
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