#pragma once
#include <iostream>
using namespace std;
#include <windows.h>
#include "../QuanLy/Application/QuanLyAll.cpp"
#include "../KhachHang/MuaVe.cpp"
#include "../KhachHang/ChangePass.cpp"
void TextColor(int x)
{
     HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(color, x);
}
void InLine(int n)
{
     for (int i = 0; i < n; i++)
          cout << "=";
}

void MenuKhachHang()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -KHACH HANG-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Mua ve                               \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Doi mat khau                         \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuMuaVe()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -MUA VE-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Danh sach lich chieu hien co         \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Danh sach lich chieu theo ngay       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Danh sach phim hien co               \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Danh sach lich chieu theo phim       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Mua ve xem phim                      \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Xem lich su mua ve                   \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                7.Quay Lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                8.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLy()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Quan ly nhan vien                    \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Quan ly phim                         \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Quan ly khach hang                   \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Quan ly lich chieu                   \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Quan ly phong chieu                  \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Quan ly doanh thu                    \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                7.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyNhanVien()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY NHAN VIEN-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Danh sach nhan vien                  \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Them nhan vien                       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Xoa nhan vien                        \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Sua thong tin nhan vien              \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Tim kiem nhan vien theo ID           \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                7.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyPhim()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY PHIM-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Danh sach phim                       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Them phim                            \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Xoa phim                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Sua thong tin phim                   \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Tim kiem phim theo IDPhim            \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                7.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyKhachHang()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY KHACH HANG-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Danh sach khach hang                 \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Tim kiem khach hang theo ID          \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyLichChieu()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY LICH CHIEU-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Danh sach lich chieu                 \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Them lich chieu                      \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Xoa lich chieu                       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Sua thong tin lich chieu             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyPhongChieu()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY PHONG CHIEU-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Danh sach phong chieu                \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Them phong chieu                     \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Xoa phong chieu                      \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Sua thong tin phong chieu            \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                6.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyDoanhThu()
{
     system("cls");
     TextColor(12);
     cout << "\n\n\t\t\t\t\t\t     -QUAN LY PHONG CHIEU-";
     TextColor(14);
     cout << "\n\t\t\t _______________________________________________________________________";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                1.Tong doanh thu                       \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                2.Thong ke phim an khach               \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                3.Thong ke khung gio an khach          \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                4.Quay lai                             \t\t|";
     cout << "\n\t\t\t|"
          << "                                                       \t\t|";
     cout << "\n\t\t\t|"
          << "                5.Thoat                                \t\t|";
     cout << "\n\t\t\t|_______________________________________________________________________|";
}

void PhanMoDau()
{
     system("cls");
     TextColor(12);
     cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     cout << ("\t\t               De tai: QUAN LY RAP CHIEU PHIM");
     cout << endl;
     cout << ("\t\t               Giao vien huong dan: Phan Thanh Tao");
     cout << endl;
     cout << ("\t\t               Ho ten sinh vien 1: Nguyen Duc Manh"
              "    Lop: 20TCLC_Nhat1");
     cout << endl;
     cout << ("\t\t               Ho ten sinh vien 2: Tran Nhat Minh"
              "    Lop: 20TCLC_Nhat1");
     cout << endl;
     cout << ("\t\t               Nhom: 9");
     cout << endl;
     TextColor(14);
     cout << ("\t\t               ==========================================================");
     cout << endl;
     TextColor(3);
     cout << endl;
     cout << "\t\t\t\t      *********************************************" << endl;
     cout << "\t\t\t                  CHUONG TRINH QUAN LY RAP CHIEU PHIM          " << endl;
     cout << "\t\t\t\t      *********************************************" << endl;
     system("pause");
}

void MenuChinh1(int username)
{
MenuKhachHang:
     MenuKhachHang();
     int chon;
     cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
     cin >> chon;
     while (chon < 0 || chon > 3)
     {
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> chon;
     }
     switch (chon)
     {
     case 1:
     {
          system("cls");
     Muave:
          MenuMuaVe();
          int a;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> a;
          while (a < 0 || a > 8)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> a;
          }
          switch (a)
          {
          case 1:
               system("cls");
               cout << "Danh sach lich chieu hien co: ";
               cout << endl;
               MuaVe::XemDanhSachLichChieuHienCo();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto Muave;
               break;
          case 2:
               system("cls");
               cout << "Danh sach lich chieu theo ngay: ";
               cout << endl;
               MuaVe::XemDanhSachLichChieuTheoNgay();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto Muave;
               break;
          case 3:
               system("cls");
               cout << "Danh sach phim hien co: ";
               cout << endl;
               MuaVe::XemDanhSachPhimHienCo();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto Muave;
               break;
          case 4:
               system("cls");
               cout << "Danh sach lich chieu theo phim: ";
               cout << endl;
               MuaVe::XemDanhSachLichChieutheoPhim();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto Muave;
               break;
          case 5:
               system("cls");
               cout << "Mua ve xem phim: ";
               cout << endl;
               MuaVe::MuaVeXemPhim(username);
               system("pause");
               fflush(stdin);
               goto Muave;
               break;
          case 6:
               system("cls");
               cout << "Xem lich su mua ve: ";
               cout << endl;
               MuaVe::XemLichSuMuaVe(username);
               cout << endl;
               system("pause");
               fflush(stdin);
               goto Muave;
               break;
          case 7:
               goto MenuKhachHang;
               break;
          case 8:
               exit(0);
               break;
          }
     }
     case 2:
          system("cls");
          cout << "Doi pass";
          cout << endl;
          ChangePass::DoiMatKhau(username);
          system("pause");
          fflush(stdin);
          goto MenuKhachHang;
          break;
     case 3:
          exit(0);
          break;
     }
}

void MenuChinh2()
{
MenuQuanLy:
     MenuQuanLy();
     int chon;
     cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
     cin >> chon;
     while (chon < 0 || chon > 7)
     {
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> chon;
     }
     switch (chon)
     {
     case 1:
     {
          system("cls");
     MenuQuanLyNhanVien:
          MenuQuanLyNhanVien();
          int a;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> a;
          while (a < 0 || a > 7)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> a;
          }
          switch (a)
          {
          case 1:
               system("cls");
               cout << "Danh sach nhan vien";
               cout << endl;
               QuanLyNhanVien::DanhSachNhanVien();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyNhanVien;
               break;
          case 2:
               system("cls");
               cout << "Them nhan vien";
               cout << endl;
               QuanLyNhanVien::ThemNhanVien();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyNhanVien;
               break;
          case 3:
               system("cls");
               cout << "Xoa nhan vien";
               cout << endl;
               QuanLyNhanVien::XoaNhanVien();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyNhanVien;
               break;
          case 4:
               system("cls");
               cout << "Sua thong tin nhan vien";
               cout << endl;
               QuanLyNhanVien::SuaThongTinNhanVien();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyNhanVien;
               break;
          case 5:
               system("cls");
               cout << "Tim kiem nhan vien";
               cout << endl;
               QuanLyNhanVien::TimKiemNhanVienTheoID();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyNhanVien;
               break;
          case 6:
               goto MenuQuanLy;
               break;
          case 7:
               exit(0);
               break;
          }
     }
     case 2:
     {
          system("cls");
     MenuQuanLyPhim:
          MenuQuanLyPhim();
          int b;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> b;
          while (b < 0 || b > 7)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> b;
          }
          switch (b)
          {
          case 1:
               system("cls");
               cout << "Danh sach phim";
               cout << endl;
               QuanLyPhim::DanhSachPhim();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhim;
               break;
          case 2:
               system("cls");
               cout << "Them phim";
               cout << endl;
               QuanLyPhim::ThemPhim();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhim;
               break;
          case 3:
               system("cls");
               cout << "Xoa phim";
               cout << endl;
               QuanLyPhim::XoaPhim();
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhim;
               break;
          case 4:
               system("cls");
               cout << "Sua thong tin phim";
               cout << endl;
               QuanLyPhim::SuaThongTinPhim();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhim;
               break;
          case 5:
               system("cls");
               cout << "Tim kiem phim";
               cout << endl;
               QuanLyPhim::TimKiemPhimTheoIDPhim();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhim;
               break;
          case 6:
               goto MenuQuanLy;
               break;
          case 7:
               exit(0);
               break;
          }
     }
     case 3:
     {
          system("cls");
     MenuQuanLyKhachHang:
          MenuQuanLyKhachHang();
          int c;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> c;
          while (c < 0 || c > 4)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> c;
          }
          switch (c)
          {
          case 1:
               system("cls");
               cout << "Danh sach khach hang";
               cout << endl;
               QuanLyKhachHang::DanhSachKhachHang();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyKhachHang;
               break;
          case 2:
               system("cls");
               cout << "Tim kiem khach hang";
               cout << endl;
               QuanLyKhachHang::TimKiemKhachTheoIDKhachHang();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyKhachHang;
               break;
          case 3:
               goto MenuQuanLy;
               break;
          case 4:
               exit(0);
               break;
          }
     }
     case 4:
     {
          system("cls");
     MenuQuanLyLichChieu:
          MenuQuanLyLichChieu();
          int d;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> d;
          while (d < 0 || d > 6)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> d;
          }
          switch (d)
          {
          case 1:
               system("cls");
               cout << "Danh sach lich chieu";
               cout << endl;
               QuanLyLichChieu::DanhSachLichChieu();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyLichChieu;
               break;
          case 2:
               system("cls");
               cout << "Them lich chieu";
               cout << endl;
               QuanLyLichChieu::ThemLichChieu();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyLichChieu;
               break;
          case 3:
               system("cls");
               cout << "Xoa lich chieu";
               cout << endl;
               QuanLyLichChieu::XoaLichChieu();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyLichChieu;
               break;
          case 4:
               system("cls");
               cout << "Sua lich chieu";
               cout << endl;
               QuanLyLichChieu::SuaThongTinLichChieu();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyLichChieu;
               break;
          case 5:
               goto MenuQuanLy;
               break;
          case 6:
               exit(0);
               break;
          }
     }
     case 5:
     {
          system("cls");
     MenuQuanLyPhongChieu:
          MenuQuanLyPhongChieu();
          int e;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> e;
          while (e < 0 || e > 6)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> e;
          }
          switch (e)
          {
          case 1:
               system("cls");
               cout << "Danh sach phong chieu";
               cout << endl;
               QuanLyPhongChieu::DanhSachPhongChieu();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhongChieu;
               break;
          case 2:
               system("cls");
               cout << "Them phong chieu";
               cout << endl;
               QuanLyPhongChieu::ThemPhongChieu();
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhongChieu;
               break;
          case 3:
               system("cls");
               cout << "Xoa phong chieu";
               cout << endl;
               QuanLyPhongChieu::XoaPhongChieu();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhongChieu;
               break;
          case 4:
               system("cls");
               cout << "Sua phong chieu" << endl;
               QuanLyPhongChieu::SuaThongTinPhongChieu();
               cout << endl;
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyPhongChieu;
               break;
          case 5:
               goto MenuQuanLy;
               break;
          case 6:
               exit(0);
               break;
          }
     }
     case 6:
     {
          system("cls");
     MenuQuanLyDoanhThu:
          MenuQuanLyDoanhThu();
          int f;
          cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
          cin >> f;
          while (f < 0 || f > 5)
          {
               cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
               cin >> f;
          }
          switch (f)
          {
          case 1:
               system("cls");
               cout << "Tong doanh thu";
               cout << endl;
               DoanhThu::TongDoanhThu_Toanbo();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyDoanhThu;
               break;
          case 2:
               system("cls");
               cout << "Thong ke phim an khach";
               cout << endl;
               DoanhThu::ThongKePhimAnKhach();
               cout << endl;
               system("pause");
               fflush(stdin);
               goto MenuQuanLyDoanhThu;
               break;
          case 3:
               system("cls");
               cout << "Thong ke khung gio an khach";
               cout << endl;
               DoanhThu::ThongKeKhungGio();
               system("pause");
               fflush(stdin);
               goto MenuQuanLyDoanhThu;
               break;
          case 4:
               goto MenuQuanLy;
               break;
          case 5:
               exit(0);
               break;
          }
     }
     case 7:
          exit(0);
          break;
     }
}