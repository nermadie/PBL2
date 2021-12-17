// #ifndef ThongTin_h
// #define ThongTin_h
// #include <iostream>
// #include <iomanip>
// #include <fstream>
// #include <string.h>
// using namespace std;
// class ThongTin
// {
// public:
//     string hoten, sdt;
//     int thu, ca;

// public:
//     friend void NhapDuLieu(int &n);
//     friend void XuatDuLieuRaFile(int &n);
//     friend void XuatLichDatVe(int n);
//     friend void DatLich(int &n);
//     friend void HuyLich(int &n);
//     friend void DanhSachKhachHang(int n);
// } khachhang[70];

// void NhapDuLieu(int &n)
// {
//     fstream file;
//     file.open("data.txt");
//     file >> n;
//     if (n != 0)
//     {
//         for (int i = 1; i <= n; i++)
//         {
//             file >> (khachhang[i]).hoten >> (khachhang[i]).sdt >> khachhang[i].thu >> khachhang[i].ca;
//         }
//     }
//     file.close();
// };

// void XuatDuLieuRaFile(int &n)
// {
//     fstream file;
//     file.open("data.txt");
//     file << n << endl;
//     for (int i = 1; i <= n; i++)
//         file << khachhang[i].hoten << " " << khachhang[i].sdt << " " << khachhang[i].thu << " " << khachhang[i].ca << endl;
//     file.close();
// };

// void XuatLichDatVe(int n)
// {
//     cout << "                ";
//     int lich[15][15];
//     for (int i = 1; i <= 10; i++)
//         for (int j = 1; j <= 10; j++)
//             lich[i][j] = 1;

//     for (int i = 1; i <= n; i++)
//         lich[khachhang[i].ca + 1][khachhang[i].thu] = 0;

//     for (int i = 1; i <= 10; i++)
//     {
//         for (int j = 1; j <= 7; j++)
//         {
//             if ((i == 1) && (j != 1))
//                 cout << setw(10) << "thu " << j;
//             else if ((j == 1) and (i != 1))
//             {
//                 if (i < 4)
//                     cout << "ca " << i - 1 << " (" << i + 5 << "h30-" << i + 6 << "h30)"
//                          << ":"
//                          << "     ";
//                 if (i == 4)
//                     cout << "ca " << i - 1 << " (" << i + 5 << "h30-" << i + 6 << "h30)"
//                          << ":"
//                          << "    ";
//                 if (i == 5)
//                     cout << "ca " << i - 1 << " (" << i + 5 << "h30-" << i + 6 << "h30)"
//                          << ":"
//                          << "   ";
//                 if (i > 5)
//                     cout << "ca " << i - 1 << " (" << i + 6 << "h30-" << i + 7 << "h30)"
//                          << ":"
//                          << "   ";
//             }

//             else if ((i != 1) and (j != 1))
//             {
//                 if (lich[i][j] == 1)
//                 {
//                     if ((lich[i][j - 1] == 0) and (j > 2))
//                         cout << "  ";
//                     cout << "Trong"
//                          << "      ";
//                 }
//                 else
//                 {
//                     if ((lich[i][j - 1] == 0) and (j > 2))
//                         cout << "  ";
//                     cout << "Full     ";
//                     //  if (j!=7)
//                     //  cout << setw(11);
//                 }
//             }
//         }
//         cout << endl;
//     }
// };

// void DatLich(int &n)
// {
//     n = n + 1;
//     int dem = 0;
//     cout << "\nNhap ten cua ban: ";
//     cin >> (khachhang[n]).hoten;
//     cout << endl
//          << "Nhap so dien thoai cua ban: ";
//     cin >> (khachhang[n].sdt);

//     do
//     {
//         cout << "\nNhap thu ban muon dat: ";
//         cin >> khachhang[n].thu;
//         dem = 0;

//         if (n > 9)
//         {
//             for (int i = 1; i <= n - 1; i++)
//                 if (khachhang[i].thu == khachhang[n].thu)
//                     dem = dem + 1;
//             if (dem == 9)
//                 cout << "\nThu ban chon da het lich, vui long chon lai ";
//         }

//         //

//         if (((khachhang[n]).thu < 2) or ((khachhang[n]).thu > 7))
//             cout << "\nThu ban chon khong hop le, vui long mot lan nua ";
//     } while (((khachhang[n]).thu < 2) or ((khachhang[n]).thu > 7) or (dem == 9));

//     // nhap ca

//     do
//     {
//         cout << "\nNhap ca ban muon dat: ";
//         cin >> khachhang[n].ca;
//         if (((khachhang[n]).ca < 1) or ((khachhang[n]).ca > 9))
//             cout << "\nCa ban chon khong hop le, vui long mot lan nua ";
//     } while (((khachhang[n]).ca < 1) or ((khachhang[n]).ca > 9));
//     cout << endl
//          << "BAN DA DAT LICH THANH CONG !";
// };

// void HuyLich(int &n)
// {
//     int thutu[10], kt, dem = 0, ca[10], thu[10];
//     string sdt, ten[10];
//     cout << "nhap so dien thoai ba da dat lich" << endl;
//     cin >> sdt;
//     for (int i = 1; i <= n; i++)
//         if (sdt == khachhang[i].sdt)
//         {
//             dem = dem + 1;
//             ten[dem] = khachhang[i].hoten;
//             ca[dem] = khachhang[i].ca;
//             thu[dem] = khachhang[i].thu;
//             thutu[dem] = i;
//         }
//     if (dem > 0)
//     {
//         cout << "ban da dung so dien thoai nay de dat " << dem << " lich la: " << endl;
//         for (int i = 1; i <= dem; i++)
//             cout << i << " - Ten: " << ten[i] << ", Thu: " << thu[i] << ", Ca: " << ca[i] << endl;
//         cout << "Ban muon huy lich nao: ";
//         cin >> kt;
//         for (int i = thutu[kt]; i <= n; i++)
//         {
//             khachhang[i].ca = khachhang[i + 1].ca;
//             khachhang[i].hoten = khachhang[i + 1].hoten;
//             khachhang[i].sdt = khachhang[i + 1].sdt;
//             khachhang[i].thu = khachhang[i + 1].thu;
//         }
//         n = n - 1;
//         cout << "Ban da huy lich thanh cong !" << endl;
//     }
//     else
//         cout << "Ban chua dung so dien thoai nay de dat lich hoac so dien thoai ban nhap khong dung" << endl;
// };

// void DanhSachKhachHang(int n)
// {
//     cout << "TONG SO KHACH HANG DA DAT LICH TRONG TUAN: " << n << endl;
//     cout << "DANH SACH KHACH HANG" << endl;
//     cout << "+--------------------+--------------------+-------+-------+" << endl;
//     cout << "|        Ten         |         SDT        |  Thu  |  Ca   |" << endl;
//     cout << "+--------------------+--------------------+-------+-------+" << endl;
//     for (int i = 1; i <= n; i++)
//     {
//         unsigned long tengoc = 17 + 4 - (khachhang[1].hoten).size();
//         unsigned long sdtgoc = 17 + 4 - (khachhang[1].sdt).size();
//         unsigned long ten1 = (khachhang[1].hoten).size() - (khachhang[i].hoten).size();
//         unsigned long sdt1 = (khachhang[1].sdt).size() - (khachhang[i].sdt).size();
//         cout << "| " << khachhang[i].hoten << setw(tengoc + ten1) << "| " << khachhang[i].sdt << setw(sdtgoc + sdt1) << "| " << khachhang[i].thu << setw(7);
//         cout << "| " << khachhang[i].ca << setw(6) << "|" << endl;
//     }
//     cout << "+--------------------+--------------------+-------+-------+" << endl;
// };
// #endif
