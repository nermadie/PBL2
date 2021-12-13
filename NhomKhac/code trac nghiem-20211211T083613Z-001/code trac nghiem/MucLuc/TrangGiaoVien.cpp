#pragma once
#include "MucLuc.h"
#include "../HeThong/DeThi/DeThi.cpp"
#include "../QuanLy/QuanLyDeThi.cpp"
#include "../QuanLy/QuanLyHocSinh.cpp"
#include "../QuanLy/QuanLyGiaoVien.cpp"
#include "../HeThong/User/Giao_Vien/GiaoVien.cpp"
#include "./TrangHocSinh.cpp"
#include "../ThuVien/Console.cpp"
#include <conio.h>
#include <iostream>
using namespace std;

void TrangGiaoVien::HienThiNhiemVu()
{
    cout << endl;
    cout << "\t\t\t\t            ******************************"      << endl;
    cout << "\t\t\t\t                  TRANG CHU GIAO VIEN"           << endl;
    cout << "\t\t\t\t            ******************************"      << endl;
    cout << "\t\t\t\t        ______________________________________"  << endl;
    cout << "\t\t\t\t       |                                      |" << endl;
    cout << "\t\t\t\t       |  1. Xem thong tin ca nhan giao vien  |" << endl;
    cout << "\t\t\t\t       |  2. Tuy chon doi voi hoc sinh        |" << endl;
    cout << "\t\t\t\t       |  3. Tuy chon doi voi de thi          |" << endl;
    cout << "\t\t\t\t       |  4. Xem danh sach hoc sinh           |" << endl;
    cout << "\t\t\t\t       |  5. Xem ket qua thi tat ca hoc sinh  |" << endl;
    cout << "\t\t\t\t       |  6. Xem danh sach de thi             |" << endl;
    cout << "\t\t\t\t       |  7. Xem danh sach tat ca giao vien   |" << endl;
    cout << "\t\t\t\t       |  8. Thoat                            |" << endl;
    cout << "\t\t\t\t       |______________________________________|" << endl;
}

void TrangGiaoVien::XemThongTinGiaoVien(string id)
{
    GiaoVien gv = LayGiaoVienTuCoSoDuLieu(id);
    printLineColor("\t\t\t\t                  THONG TIN GIAO VIEN ", 6); cout << endl;
    cout << "\t\t\t\t               Id: " << gv.getId()              << endl;
    cout << "\t\t\t\t               Ten: " << gv.getTen()            << endl;
    cout << "\t\t\t\t               Tuoi: " << gv.getTuoi()          << endl;
    cout << "\t\t\t\t               Gioi tinh: " << gv.getGioiTinh() << endl;
}

void TrangGiaoVien::HienThiTuyChonDoiVoiHocSinh()
{
    cout << endl;
    cout << "\t\t\t\t            ******************************"    << endl;
    cout << "\t\t\t\t                   TUY CHON HOC SINH"          << endl;
    cout << "\t\t\t\t            ******************************"    << endl;
    cout << "\t\t\t\t          __________________________________"  << endl;
    cout << "\t\t\t\t         |                                  |" << endl;
    cout << "\t\t\t\t         |  1. Xem thong tin hoc sinh       |" << endl;
    cout << "\t\t\t\t         |  2. Them hoc sinh                |" << endl;
    cout << "\t\t\t\t         |  3. Cap nhat thong tin hoc sinh  |" << endl;
    cout << "\t\t\t\t         |  4. Xoa hoc sinh                 |" << endl;
    cout << "\t\t\t\t         |  5. Thoat                        |" << endl;
    cout << "\t\t\t\t         |__________________________________|" << endl;
}

void TrangGiaoVien::TuyChonDoiVoiHocSinh()
{
    int chon;
    string id_HocSinh; 
    do
    { 
        TrangGiaoVien::HienThiTuyChonDoiVoiHocSinh();
        cout << endl;

        cout << "\t\t\t\t            -> Moi ban chon: "; cin >> chon;
        cout << endl << endl;
      
        switch (chon)
        {
            case 1: printLineColor("\t\t\t\t\t             XEM HOC SINH", 6); cout << endl << endl;
                    cout << "\t\t\t\t\t       Nhap id hoc sinh: "; cin >> id_HocSinh;
                    cout << endl;
                    TrangHocSinh::XemThongTinHocSinh(id_HocSinh);
                    cout << endl;
                    break;

            case 2: 
            {
                printLineColor("\t\t\t\t\t             THEM HOC SINH", 6); cout << endl << endl;
                cout << "\t\t\t\t\t        Nhap id hoc sinh: "; cin >> id_HocSinh;
                if (kiemTraId("./CoSoDuLieu/HocSinh/HocSinh_id.txt", id_HocSinh) == true)
                {
                    cout << endl;
                    printLineColor("\t\t\t\t\t       Tai khoan nay da ton tai", 4); cout << endl;
                    return;
                }

                NhapHocSinh(id_HocSinh);
                cout << endl;
                printLineColor("\t\t\t\t\t        THEM HOC SINH THANH CONG", 2); cout << endl << endl;
                break;
            }

            case 3: printLineColor("\t\t\t\t\t           CAP NHAT HOC SINH", 6); cout << endl << endl;
                    cout << "\t\t\t\t\t       Nhap id hoc sinh: "; cin >> id_HocSinh;
                    if (!kiemTraId("./CoSoDuLieu/HocSinh/HocSinh_id.txt",id_HocSinh))
                    {
                        cout << endl;
                        printLineColor("\t\t\t\t\t        KHONG TIM THAY HOC SINH", 4); cout << endl << endl;  
                        return;
                    }
                    CapNhatHocSinhTrongCoSoDuLieu(id_HocSinh);
                    cout << endl;
                    printLineColor("\t\t\t\t\t      CAP NHAT HOC SINH THANH CONG", 2); cout << endl << endl;
                    break;

            case 4: printLineColor("\t\t\t\t\t              XOA HOC SINH", 6); cout << endl << endl;
                    cout << "\t\t\t\t\t       Nhap id hoc sinh: "; cin >> id_HocSinh;
                    if (kiemTraId("./CoSoDuLieu/HocSinh/HocSinh_id.txt", id_HocSinh) == false)
                    {
                        cout << endl;
                        printLineColor("\t\t\t\t\t    Khong tim thay hoc sinh can xoa", 4);
                        cout << endl;
                        break;
                    }
                    XoaHocSinhTuCoSoDuLieu(id_HocSinh);
                    XoaDiemThiHocSinh(id_HocSinh);
                    cout << endl ;
                    printLineColor("\t\t\t\t\t        XOA HOC SINH THANH CONG", 2); cout << endl << endl;
                    break;

            case 5: return;

            default: printLineColor("\t\t\t\t\t     Ban da nhap sai", 4); cout << endl;
        }
        cout << endl;
        cout << "\t\t\t\t\t     Nhan phim bat ky de tiep tuc ";
        getch(); 
        system("cls");
    }
    while(chon != 5);
}


void TrangGiaoVien::HienThiTuyChonDoiVoiDeThi()
{
    cout << endl;
    cout << "\t\t\t\t             ******************************"   << endl;
    cout << "\t\t\t\t                     TUY CHON DE THI"          << endl;
    cout << "\t\t\t\t             ******************************"   << endl;
    cout << "\t\t\t\t            ________________________________"  << endl;
    cout << "\t\t\t\t           |                                |" << endl;
    cout << "\t\t\t\t           |  1. Xem de thi                 |" << endl;
    cout << "\t\t\t\t           |  2. Them de thi moi            |" << endl;
    cout << "\t\t\t\t           |  3. Xoa de thi                 |" << endl;
    cout << "\t\t\t\t           |  4. Them cau hoi cho de thi    |" << endl;
    cout << "\t\t\t\t           |  5. Cap nhat cau hoi trong de  |" << endl;
    cout << "\t\t\t\t           |  6. Xoa cau hoi trong de       |" << endl;
    cout << "\t\t\t\t           |  7. Thoat                      |" << endl;
    cout << "\t\t\t\t           |________________________________|" << endl;
}

void TrangGiaoVien::XemDe(string id)
{
    DeThi dt = LayDeThiTuCoSoDuLieu(id);
    for (int i=0; i < dt.getSoCau() ; i++)
    {
        cout << "\t\t\t\t   Cau " << i+1 << ": ";
        cout << dt.getCauHoi(i) << endl;
        cout << "\t\t\t\t   A. " << dt.getDapAnA(i) << endl;
        cout << "\t\t\t\t   B. " << dt.getDapAnB(i) << endl;
        cout << "\t\t\t\t   C. " << dt.getDapAnC(i) << endl;
        cout << "\t\t\t\t   D. " << dt.getDapAnD(i) << endl;
        cout << "\t\t\t\t   Dap an cho cau hoi nay la: " << dt.getDapAn(i) << endl;
    }
}

void TrangGiaoVien::TuyChonDoiVoiDeThi()
{
    while (true)
    {
        TrangGiaoVien::HienThiTuyChonDoiVoiDeThi();
        cout << endl;

        int chon;
        string id_DeThi;
        cout << "\t\t\t\t              -> Moi ban chon: "; cin >> chon;
        cout << endl;

        switch (chon)
        {
            case 1: 
                    printLineColor("\t\t\t\t\t\t       XEM DE THI", 6); cout << endl << endl;   
                    cout << "\t\t\t\t\t       Nhap id cho de thi: ";     cin >> id_DeThi;
                    TrangGiaoVien::XemDe(id_DeThi);
                    break;
            case 2: 
                    printLineColor("\t\t\t\t\t\t       THEM DE THI", 6); cout << endl << endl;
                    cout << "\t\t\t\t\t       Nhap id cho de thi: ";     cin >> id_DeThi;
                //    NhapDeThi(id_DeThi);
                    if(NhapDeThi(id_DeThi) == 1)
                    {   
                        cout << endl;
                        printLineColor("\t\t\t\t\t          THEM DE THI THANH CONG", 2);
                    }
                    cout << endl;
                    break;
            case 3: 
                    printLineColor("\t\t\t\t\t\t       XOA DE THI", 6); cout << endl << endl;
                    cout << "\t\t\t\t\t       Nhap id cho de thi: ";     cin >> id_DeThi;
                //    XoaDeThiTuCoSoDuLieu(id_DeThi);
                    if(XoaDeThiTuCoSoDuLieu(id_DeThi) == 1)
                    {   
                        cout << endl;
                        printLineColor("\t\t\t\t\t          XOA DE THI THANH CONG", 2);
                    } 
                    cout << endl;
                    break;
            case 4:
                    printLineColor("\t\t\t\t\t\t       THEM CAU HOI", 6); cout << endl << endl; 
                    cout << "\t\t\t\t\t       Nhap id cho de thi: ";     cin >> id_DeThi;
                //    ThemCauHoiChoDeThi(id_DeThi);
                    if(ThemCauHoiChoDeThi(id_DeThi) == 1)
                    {
                        cout << endl;
                        printLineColor("\t\t\t\t\t          THEM CAU HOI THANH CONG", 2);
                    }
                    cout << endl;
                    break;
            case 5: printLineColor("\t\t\t\t\t\t      CAP NHAT CAU HOI", 6); cout << endl << endl;
                    cout << "\t\t\t\t\t       Nhap id cho de thi: ";     cin >> id_DeThi;
                //    CapNhatCauHoiTrongCoSoDuLieu(id_DeThi);
                    if(CapNhatCauHoiTrongCoSoDuLieu(id_DeThi) == 1) 
                    {
                        cout << endl;
                        printLineColor("\t\t\t\t\t       CAP NHAT CAU HOI THANH CONG", 2); 
                    }
                    cout << endl;
                    break;
                    
            case 6: printLineColor("\t\t\t\t\t\t        XOA CAU HOI", 6); cout << endl << endl; 
                    cout << "\t\t\t\t\t       Nhap id cho de thi: ";     cin >> id_DeThi;
                //    XoaCauHoiTrongDe(id_DeThi);
                    if(XoaCauHoiTrongDe(id_DeThi) == 1)
                    {
                        cout << endl;
                        printLineColor("\t\t\t\t\t          XOA CAU HOI THANH CONG", 2); 
                    }
                    cout << endl;
                    break;
                    
            case 7: return;
            default: printLineColor("\t\t\t\t\t            Ban da nhap sai", 4); cout << endl;
        }
        cout << endl;
        cout << "\t\t\t\t\t      Nhan phim bat ky de tiep tuc ";
        getch(); 
        system("cls");
    }
}

void XemDanhSachHocSinh()
{
    string filePath = "./CoSoDuLieu/HocSinh/HocSinh_id.txt";

    ifstream inFile(filePath);
    string line;

    string id;

    while (getline(inFile, line))
    {
        id = line;
        TrangHocSinh::XemThongTinHocSinh(id);
        cout << endl;
    }

}

void XemKetQuaThiCuaTatCaHocSinh()
{
    string filePath_HocSinh("./CoSoDuLieu/HocSinh/HocSinh_id.txt");
    
    ifstream inFile_HocSinh(filePath_HocSinh);
    string line_HocSinh;
    string id_HocSinh;
    HocSinh hs;

    string id_DeThi;
    string line_DeThi;

    cout << "\t\t\t\t\t        Nhap id de: "; cin >> id_DeThi;
    DeThi dt = LayDeThiTuCoSoDuLieu(id_DeThi);
    cout << endl;

    string* kq;

    while (getline(inFile_HocSinh, line_HocSinh))
    {
        id_HocSinh = line_HocSinh;

        hs = LayHocSinhTuCoSoDuLieu(id_HocSinh);
        ifstream inFile_DeThi("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt");

        while(getline(inFile_DeThi, line_DeThi))
        {
            kq = KetQua(line_DeThi);
            if (kq[0] == id_DeThi)
            {
                cout << "\t\t\t\t\t        Id: " << hs.getId() << endl;
                cout << "\t\t\t\t\t        Ten: " << hs.getTen() << endl; 
                cout << "\t\t\t\t\t        Diem: " << kq[1] << endl;
                cout << endl;
            }
        }
    }
}

void XemDanhSachDeThi()
{
    string filePath = "./CoSoDuLieu/DeThi/DeThi_id.txt";
    ifstream inFile(filePath);

    string id_DeThi;

    string line;

   
    while(getline(inFile, line))
    {
        id_DeThi = line;
        cout << "\t\t\t\t\t\t      " <<  id_DeThi << endl;
    }
    cout << endl;

    char chon;
    do
    {
        cout << "\t\t\t\t        Ban muon xem de thi nao khong? (Y/N) "; cin >> chon;

        switch (chon)
        {
            case 'Y':
            {
                cout << endl;
                cout << "\t\t\t\t          Nhap id de thi ban muon xem: "; cin >> id_DeThi;
                TrangGiaoVien::XemDe(id_DeThi);
            }
            
            case 'N': 
            {
                return;
            };
            default: 
            {
                cout << endl;
                printLineColor("\t\t\t\t\t   Ban da nhap sai! Moi ban nhap lai! \n",4);
                cout << endl;
            }
        }
    } while ((chon != 'Y') || (chon != 'N'));
}

void XemDanhSachGiaoVien()
{
    string filePath = "./CoSoDuLieu/GiaoVien/GiaoVien_id.txt";

    ifstream inFile(filePath);
    string line;

    string id;

    while (getline(inFile, line))
    {
        id = line;
        TrangGiaoVien::XemThongTinGiaoVien(id);
        cout << endl << endl;
    }
}

void TrangGiaoVien::HienThi(string id)
{
    system("cls");
    GiaoVien gv = LayGiaoVienTuCoSoDuLieu(id);
    int chon;
    do
    {
        TrangGiaoVien::HienThiNhiemVu();
        cout << endl;
        cout << "\t\t\t\t           -> Moi ban chon: "; cin >> chon;
        cout << endl;

        switch (chon)
        {
            case 1: XemThongTinGiaoVien(id);
                    break;
            
            case 2: system("cls");
                    TuyChonDoiVoiHocSinh();
                    break;

            case 3: system("cls");
                    TuyChonDoiVoiDeThi();
                    break;
            
            case 4: XemDanhSachHocSinh();
                    break;

            case 5: printLineColor("\t\t\t\t\t            KET QUA THI", 6); cout << endl << endl;
                    XemKetQuaThiCuaTatCaHocSinh();
                    break;
        
            case 6: printLineColor("\t\t\t\t\t         DANH SACH DE THI", 6); cout << endl << endl;
                    XemDanhSachDeThi();
                    break;
            
            case 7: XemDanhSachGiaoVien();
                    break;

            case 8: break;

            default: printLineColor("\t\t\t\t\t\t     Ban da nhap sai", 4); cout << endl; 
        }
        cout << endl;
        cout << "\t\t\t\t\t   Nhan phim bat ky de tiep tuc ";
        getch(); 
        system("cls");
    }
    while (chon != 8);
}