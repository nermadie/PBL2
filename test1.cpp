// #include <iostream>
// #include <fstream>
// using namespace std;
// #include <windows.h>
// #include <iomanip>
// #include <string.h>
// #include <conio.h>
// #include "ThongTin.h"

// void TextColor(int x){
//     HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//     SetConsoleTextAttribute( color , x );
// }
// void InLine(int n){
//     for (int i = 0; i < n; i++)
//         cout<<"=";
// }

// void menuchinh()
// {
//     system ("cls"); TextColor(12);
//     cout<<"\n\n\t\t\t\t\t\t\t\t-MENU-"; TextColor(14);
//     cout<<"\n\t\t\t\t\t\t _____________________________________";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t       1.Nhan vien            |";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t       2.Phim                 |";
// 	cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t       3.Khach hang           |";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
//     cout<<"\n\t\t\t\t\t\t|"<<"\t       4.Quan ly              |";
// 	cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
// 	cout<<"\n\t\t\t\t\t\t|"<<"\t       5.Thoat                |";
// 	cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
//     cout<<"\n\t\t\t\t\t\t|_____________________________________|";
// }

// void menuNhanVien()
// {
//     system("cls");TextColor(12);
// 	        cout<<"\n\n\t\t\t\t\t\t     -NHAN VIEN-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Hien Thi Danh Sach Nhan Vien         \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Them Nhan Vien                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Xoa nhan vien                        \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Thay doi thong tin nhan vien theo ID \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                5.Tim kiem nhan vien theo ID           \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                6.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                7.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void menuNhanVienThem()
// {
//     system("cls");TextColor(12);
// 	        cout<<"\n\n\t\t\t\t\t\t     -THEM NHAN VIEN-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Them Nhan Vien vao dau danh sach     \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Them Nhan Vien vao cuoi danh sach    \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Them Nhan Vien vao vi tri bat ki     \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                5.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void menuXoaNhanVien()
// {
//     system("cls");TextColor(12);
// 	        cout<<"\n\n\t\t\t\t\t\t     -XOA NHAN VIEN-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Xoa Nhan Vien o dau danh sach        \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Xoa Nhan Vien o cuoi danh sach       \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Xoa Nhan Vien o vi tri bat ki        \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                5.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void MenuPhim()
// {
//     system("cls");TextColor(12);
// 	        cout<<"\n\n\t\t\t\t\t\t     -NHAN VIEN-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Hien Thi Danh Sach Phim              \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Them Phim                            \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Xoa Phim                             \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Thay doi thong tin Phim theo IDP     \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                5.Tim kiem Phim theo IDP               \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                6.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                7.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void menuThemPhim()
// {
//     system("cls");TextColor(12);
// 	        cout<<"\n\n\t\t\t\t\t\t     -THEM PHIM-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Them Phim vao dau danh sach          \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Them Phim vao cuoi danh sach         \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Them Phim vao vi tri bat ki          \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                5.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void menuXoaPhim()
// {
//     system("cls");TextColor(12);
// 	        cout<<"\n\n\t\t\t\t\t\t     -XOA PHIM-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Xoa Phim o dau danh sach             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Xoa Phim o cuoi danh sach            \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Xoa Phim o vi tri bat ki             \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                5.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void MenuKhachHang()
// {
//     system("cls"); TextColor(12);
//             cout<<"\n\n\t\t\t\t\t\t     -KHACH HANG-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Danh sach lich chieu phim con trong  \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Danh sach ghe ngoi con trong         \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                3.Dat ve xem phim                      \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                4.Dat ghe                              \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                5.Huy dat ve                           \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                6.Huy dat ghe                          \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                7.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                8.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void MenuQuanLy()
// {
//     system("cls"); TextColor(12);
//             cout<<"\n\n\t\t\t\t\t\t     -QUAN LY-"; TextColor(14);
// 		    cout<<"\n\t\t\t _______________________________________________________________________";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                1.Danh sach lich chieu phim da dat     \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                2.Danh sach ghe ngoi da dat            \t\t|";
//             cout<<"\n\t\t\t|"<<"                                                       \t\t|";
//             cout<<"\n\t\t\t|"<<"                3.Danh sach khach da dat ve            \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                4.Quay Lai                             \t\t|";
// 	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                5.Thoat                                \t\t|";
// 		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
// 		    cout<<"\n\t\t\t|_______________________________________________________________________|";
// }

// void menu()
// {
//     int t = 0; string a;
//     Menu:
//     menuchinh();
//     int chon;
//     cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
//     cin >> chon;
//     while(chon < 0 || chon > 5)
//     {
//         cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
//         cin >> chon;
//     }
//     switch (chon)
//     {
//         case 1:
//         {
//             system ("cls");
//             Nhanvien:
//             menuNhanVien();
//             int a;
//             cout<<"\n\n\t\t\tNhap lua chon :";
//             cin >> a;
//             while (a < 0||a > 7)
//             {
//                 cout << "\n\n\t\t\tNhap lua chon :";
//                 cin >> a;
//             }
//             switch (a)
//             {
//             case 1:
//                 system ("cls");
//                 cout << "Hien thi thong tin Nhan vien";
//                 cout << endl;
//                 system ("pause");
//                 goto Nhanvien;
//                 break;
//             case 2:
//             {
//                 system ("cls");
//                 ThemNhanVien:
//                 menuNhanVienThem();
//                 int m;
//                 cout<<"\n\n\t\t\tNhap lua chon :";
//                 cin >> m;
//                 while (m < 0||m > 5)
//                 {
//                     cout << "\n\n\t\t\tNhap lua chon :";
//                     cin >> m;
//                 }
//                 switch (m)
//                 {
//                 case 1:
//                     system ("cls");
//                     cout << "Them nhan vien vao dau danh sach"; cout << endl;
//                     system ("pause");
//                     goto ThemNhanVien;
//                     break;
//                 case 2:
//                     system ("cls");
//                     cout << "Them nhan vien vao cuoi danh sach"; cout << endl;
//                     system ("pause");
//                     goto ThemNhanVien;
//                     break;
//                 case 3:
//                     system ("cls");
//                     cout << "Them nhan vien vao vi tri bat ki"; cout << endl;
//                     system ("pause");
//                     goto ThemNhanVien;
//                     break;
//                 case 4:
//                     goto Nhanvien;
//                     break;
//                 case 5:
//                     exit(0);
//                     break;
//                 }
//             }
//             case 3:
//             {
//                 system ("cls");
//                 XoaNhanVien:
//                 menuXoaNhanVien();
//                 int m;
//                 cout<<"\n\n\t\t\tNhap lua chon :"; cout << endl;
//                 cin >> m;
//                 while (m < 0||m > 5)
//                 {
//                     cout << "\n\n\t\t\tNhap lua chon :";cout << endl;
//                     cin >> m;
//                 }
//                 switch (m)
//                 {
//                 case 1:
//                     system ("cls");
//                     cout << "Xoa nhan vien o dau danh sach";cout << endl;
//                     system ("pause");
//                     goto XoaNhanVien;
//                     break;
//                 case 2:
//                     system ("cls");
//                     cout << "Xoa nhan vien o cuoi danh sach";cout << endl;
//                     system ("pause");
//                     goto XoaNhanVien;
//                     break;
//                 case 3:
//                     system ("cls");
//                     cout << "Xoa nhan vien o vi tri bat ki";cout << endl;
//                     system ("pause");
//                     goto XoaNhanVien;
//                     break;
//                 case 4:
//                     goto Nhanvien;
//                     break;
//                 case 5:
//                     exit(0);
//                     break;
//                 }
//             }
//             case 4:
//                 system("cls");
//                 cout << "Thay doi";cout << endl;
//                 system ("pause");
//                 goto Nhanvien;
//                 break;
//             case 5:
//                 system("cls");
//                 cout << "Tim kiem";cout << endl;
//                 system ("pause");
//                 goto Nhanvien;
//                 break;
//             case 6:
//                 goto Menu;
//                 break;
//             case 7:
//                 exit(0);
//                 break;
//             }
//         }
//         case 2:
//         {
//             system ("cls");
//             Phim:
//             MenuPhim();
//             int b;
//             cout<<"\n\n\t\t\t\tNhap lua chon :";
//             cin >> b;
//             while(b < 0 || b > 7)
//             {
//                 cout<<"\n\n\t\t\t\tNhap lua chon :";
//                 cin >> b ;
//             }
//             switch (b)
//             {
//             case 1:
//                 system ("cls");
//                 cout << "Hien thi thong tin Phim";cout << endl;
//                 system ("pause");
//                 goto Phim;
//                 break;
//             case 2:
//             {
//                 system ("cls");
//                 ThemPhim:
//                 menuThemPhim();
//                 int n;
//                 cout<<"\n\n\t\t\tNhap lua chon :";
//                 cin >> n;
//                 while (n < 0||n > 5)
//                 {
//                     cout << "\n\n\t\t\tNhap lua chon :";
//                     cin >> n;
//                 }
//                 switch (n)
//                 {
//                 case 1:
//                     system ("cls");
//                     cout << "Them Phim vao dau danh sach";cout << endl;
//                     system ("pause");
//                     goto ThemPhim;
//                     break;
//                 case 2:
//                     system ("cls");
//                     cout << "Them Phim vao cuoi danh sach";cout << endl;
//                     system ("pause");
//                     goto ThemPhim;
//                     break;
//                 case 3:
//                     system ("cls");
//                     cout << "Them Phim vao vi tri bat ki";cout << endl;
//                     system ("pause");
//                     goto ThemPhim;
//                     break;
//                 case 4:
//                     goto Phim;
//                     break;
//                 case 5:
//                     exit(0);
//                     break;
//                 }
//             }
//             case 3:
//             {
//                 system ("cls");
//                 XoaPhim:
//                 menuXoaPhim();
//                 int n;
//                 cout<<"\n\n\t\t\tNhap lua chon :";
//                 cin >> n;
//                 while (n < 0||n > 5)
//                 {
//                     cout << "\n\n\t\t\tNhap lua chon :";
//                     cin >> n;
//                 }
//                 switch (n)
//                 {
//                 case 1:
//                     system ("cls");
//                     cout << "Xoa Phim o dau danh sach";
//                     cout << endl;
//                     system ("pause");
//                     goto XoaPhim;
//                     break;
//                 case 2:
//                     system ("cls");
//                     cout << "Xoa Phim o cuoi danh sach"; cout << endl;
//                     system ("pause");
//                     goto XoaPhim;
//                     break;
//                 case 3:
//                     system ("cls");
//                     cout << "Xoa Phim o vi tri bat ki"; cout << endl;
//                     system ("pause");
//                     goto XoaPhim;
//                     break;
//                 case 4:
//                     goto Phim;
//                     break;
//                 case 5:
//                     exit(0);
//                     break;
//                 }
//             }
//             case 4:
//                 system("cls");
//                 cout << "Thay doi"; cout << endl;
//                 system ("pause");
//                 goto Phim;
//                 break;
//             case 5:
//                 system("cls");
//                 cout << "Tim kiem"; cout << endl;
//                 system ("pause");
//                 goto Phim;
//                 break;
//             case 6:
//                 goto Menu;
//                 break;
//             case 7:
//                 exit(0);
//                 break;
//             }

//         }
//         case 3:
//         {
//             system ("cls");
//             KhachHang:
//             MenuKhachHang();
//             int c;
//             cout<<"\n\n\t\t\tNhap lua chon :";
//             cin >> c;
//             while (c < 0||c > 8)
//             {
//                 cout << "\n\n\t\t\tNhap lua chon :";
//                 cin >> c;
//             }
//             switch (c)
//             {
//             case 1:
//                 system ("cls");
//                 cout << "Danh sach lich chieu phim con trong" << endl << endl;
//                 XuatLichDatVe(t);
//                 cout << endl;
//                 system ("pause");
//                 goto KhachHang;
//                 break;
//             case 2:
//                 system("cls");
//                 cout << "Danh sach ghe ngoi con trong";cout << endl;
//                 system ("pause");
//                 goto KhachHang;
//                 break;
//             case 3:
//                 system("cls");
//                 cout << "Dat lich xem phim";cout << endl << endl;
//                 DatLich(t);
//                 cout << endl;
//                 system ("pause");
//                 goto KhachHang;
//                 break;
//             case 4:
//                 system("cls");
//                 cout << "Dat ghe ngoi";cout << endl;
//                 system ("pause");
//                 goto KhachHang;
//                 break;
//             case 5:
//                 system("cls");
//                 cout << "Huy dat lich"; cout << endl << endl;
//                 HuyLich(t);
//                 cout << endl;
//                 system ("pause");
//                 goto KhachHang;
//                 break;
//             case 6:
//                 system("cls");
//                 cout << "Huy dat ghe"; cout << endl;
//                 system ("pause");
//                 goto KhachHang;
//                 break;
//             case 7:
//                 goto Menu;
//                 break;
//             case 8:
//                 exit(0);
//                 break;
//             }
//         }
//         case 4:
//         {
//             system ("cls");
//             QuanLy:
//             MenuQuanLy();
//             int d;
//             cout<<"\n\n\t\t\t\tNhap lua chon :";
//             cin >> d;
//             while(d < 0 || d > 5)
//             {
//                 cout<<"\n\n\t\t\t\tNhap lua chon :";
//                 cin >> d ;
//             }
//             switch (d)
//             {
//             case 1:
//                 system ("cls");
//                 cout << "Danh sach lich chieu phim da dat"; cout << endl << endl;
//                 XuatLichDatVe(t);
//                 cout << endl;
//                 system ("pause");
//                 goto QuanLy;
//                 break;
//             case 2:
//                 system("cls");
//                 cout << "Hien thi danh sach ghe ngoi da dat";cout << endl << endl;
//                 system ("pause");
//                 goto QuanLy;
//                 break;
//             case 3:
//                 system("cls");
//                 cout << "Hien thi danh sach khach da dat ve"; cout << endl << endl;
//                 DanhSachKhachHang(t);
//                 cout << endl;
//                 system ("pause");
//                 goto QuanLy;
//                 break;
//             case 4:
//                 goto Menu;
//                 break;
//             case 5:
//                 exit(0);
//                 break;
//             }
//         }
//         case 5:
//             exit(0);
//             break;
//     }
// }

// int main()
// {
// 	system("cls");
//     TextColor (12);
// 	cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");                                       cout << endl; TextColor (14);
// 	cout << ("\t\t               ==========================================================");    cout << endl;
// 	cout <<("\t\t               De tai: QUAN LY RAP CHIEU PHIM");                              cout << endl;
// 	cout << ("\t\t               Giao vien huong dan: Phan Thanh Tao");                               cout << endl;
// 	cout << ("\t\t               Ho ten sinh vien 1: Nguyen Duc Manh"  "    Lop: 20TCLC_Nhat1"); cout << endl;
// 	cout << ("\t\t               Ho ten sinh vien 2: Tran Nhat Minh"  "    Lop: 20TCLC_Nhat1"); cout << endl;
// 	cout << ("\t\t               Nhom: 9");                                                   cout << endl; TextColor (14);
// 	cout << ("\t\t               ==========================================================");    cout << endl; TextColor (3);
// 	cout << endl;
//     cout << "\t\t\t\t      *********************************************"            << endl;
//     cout << "\t\t\t                  CHUONG TRINH QUAN LY RAP CHIEU PHIM          "<< endl;
//     cout << "\t\t\t\t      *********************************************"            << endl;
//     system ("pause");

//     //Đăng nhập
//     system ("cls");
//     TextColor(4);
//     cout << "\t\t\t\t      *********************************************"            << endl;
//     cout << "\t\t\t\t                       DANG NHAP                       "<< endl;
//     cout << "\t\t\t\t      *********************************************"            << endl;

//     int pass,i,dem=0;
// 	char p[10], user[20];
//     TextColor(11);
//     cout << "\n\t\t\t\t\tEnter User: ";
//     cin >> user;
//     while (strcmp(user, "abcd"))
//     {
//         cout << "\n\t\t\t\t\tAgain!";
//         cout << "\n\n\t\t\t\t\tEnter User: ";
//         cin >> user;
//     }

// 	cout<<"\n\t\t\t\t\tEnter Password (8 charecter): ";
// 	cout.flush();
//    do
// 	{
// 		do
// 		{
// 			pass = getch();
//          if (pass!=13 && pass!=8 && pass!=' ')
// 				cout<<"*";
// 			if (pass==8 && dem>0)
// 			{
// 				cout<<"\b"<<" "<<"\b";
// 				dem--;
// 			}
// 			else
// 				if(pass==8 && dem==0)
// 				dem=0;
//             	else
// 					{
// 						p[dem] = pass;
// 						dem++;
//                }
// 				cout.flush();
// 		}while(pass!=13);

// 	for(i=0;i<dem-1;i++) cout<<"\b";
// 	for(i=0;i<dem;i++) cout<<" ";
// 	for(i=0;i<dem;i++) cout<<"\b";
// 	dem=0;
// 	cout.flush();
// 	}while(p[0]!='m'||p[1]!='a'||p[2]!='n'||p[3]!='h'||p[4]!='h'||p[5]!='n'||p[6]!='e'||p[7]!='e');

//     menu();
//     return 0;
// }