#pragma once
#include "MucLuc.h"
#include "../QuanLy/QuanLy.cpp"
#include "../QuanLy/QuanLyDeThi.cpp"
#include "../QuanLy/QuanLyHocSinh.cpp"
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <iostream>
using namespace std;
void TrangHocSinh::HienThiNhiemVu()
{
    cout << endl;
    cout << "\t\t\t\t\t       **************************"   << endl;
    cout << "\t\t\t\t\t           TRANG CHU HOC SINH"       << endl;
    cout << "\t\t\t\t\t       **************************"   << endl;
    cout << "\t\t\t\t\t      ____________________________"  << endl;
    cout << "\t\t\t\t\t     |                            |" << endl;
    cout << "\t\t\t\t\t     |  1. Xem thong tin ca nhan  |" << endl;
    cout << "\t\t\t\t\t     |  2. Cap nhat tai khoan     |" << endl;
    cout << "\t\t\t\t\t     |  3. Xem de thi             |" << endl;
    cout << "\t\t\t\t\t     |  4. Lam de thi             |" << endl;
    cout << "\t\t\t\t\t     |  5. Xem diem thi           |" << endl;
    cout << "\t\t\t\t\t     |  6. Thoat                  |" << endl;
    cout << "\t\t\t\t\t     |____________________________|" << endl;
}

void TrangHocSinh::XemThongTinHocSinh(string id)
{
    if (!kiemTraId("./CoSoDuLieu/HocSinh/HocSinh_id.txt", id))
    {
        printLineColor("\t\t\t\t\t        Hoc sinh khong ton tai", 4);
        return;
    }
    HocSinh hs = LayHocSinhTuCoSoDuLieu(id);
    printLineColor("\t\t\t\t                  THONG TIN HOC SINH", 6); cout << endl;
   // cout << "\t\t\t\t\t\t              ______________________    " << endl;
    //cout << "\t\t\t\t\t\t             |                      |" << endl;
    cout << "\t\t\t\t                  Id: " << hs.getId()               << endl;
    cout << "\t\t\t\t                  Ten: " << hs.getTen()        << endl;
    cout << "\t\t\t\t                  Tuoi: " << hs.getTuoi()       << endl;
    cout << "\t\t\t\t                  Gioi tinh: " << hs.getGioiTinh() << endl;
  //  cout << "\t\t\t\t\t\t             ______________________|" << endl;
}

string* KetQua(string line)
{
    string* kq = new string[50];
    int i=0;
    string word = "";
    for (auto x : line) 
    {
        if (x == ' ')
        {
            kq[i++] = word;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    
    kq[i] = word;

    return kq;
}

void TrangHocSinh::XemDe(string id_HocSinh)
{
    string id_DeThi;
    cout << "\t\t\t\t\t     Nhap id de ban muon xem: " ; cin >> id_DeThi;

    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id_DeThi) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t            De thi khong ton tai", 4);
        cout << endl;
        return;
    }
    DeThi dt = LayDeThiTuCoSoDuLieu(id_DeThi);
    
    ifstream inFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt");
    string line;

    if (! inFile.is_open() || (inFile.peek() == ifstream::traits_type::eof()))
    {
        cout << endl;
        printLineColor("\t\t\t\t       Ban chua lam de nay nen khong the xem duoc! \n", 4);
        return;
    }

    string* kq;
    while(getline(inFile, line))
    {
        kq = KetQua(line);

        if (kq[0] == id_DeThi) break;
        cout << endl;
        printLineColor("\t\t\t\t       Ban chua lam de nay nen khong the xem duoc! \n", 4);
        return;
    }

    for (int i = 0; i < dt.getSoCau() ; i++)
    {
        cout << "\t\t\t\t       Cau " << i+1 << ": ";
        cout << dt.getCauHoi(i) << endl;
        cout << "\t\t\t\t       A. " << dt.getDapAnA(i) << endl;
        cout << "\t\t\t\t       B. " << dt.getDapAnB(i) << endl;
        cout << "\t\t\t\t       C. " << dt.getDapAnC(i) << endl;
        cout << "\t\t\t\t       D. " << dt.getDapAnD(i) << endl;
        cout << "\t\t\t\t\t       Dap an cho cau hoi nay la: " << dt.getDapAn(i) << endl;
    }
}

void TrangHocSinh::LamDe(string id_HocSinh, string id_DeThi)
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id_DeThi) == false)
    {
        printLineColor("\t\t\t\t\t            De thi khong ton tai", 4);
        cout << endl;
        return;
    }

    DeThi dt = LayDeThiTuCoSoDuLieu(id_DeThi);    

    ifstream inFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt");
    string line;

    string* kq;

    while(getline(inFile, line))
    {
        kq = KetQua(line);

        if (kq[0] == id_DeThi)
        {
            printLineColor("\t\t\t\t\t          Ban da lam de nay roi \n", 2);
            return;
        }
    }

    char* dapAn_HocSinh = new char[dt.getSoCau()];
    float diem = 0;

    for (int i=0; i < dt.getSoCau() ; i++)
    {
        cout << "\t\t\t\t         Cau " << i+1 << ": ";
        cout << dt.getCauHoi(i) << endl;
        cout << "\t\t\t\t         A. " << dt.getDapAnA(i) << endl;
        cout << "\t\t\t\t         B. " << dt.getDapAnB(i) << endl;
        cout << "\t\t\t\t         C. " << dt.getDapAnC(i) << endl;
        cout << "\t\t\t\t         D. " << dt.getDapAnD(i) << endl;

        do
        {
            dapAn_HocSinh[i] = getCharInput("\t\t\t\t\t            Ban chon"); fflush(stdin);
        } while ((dapAn_HocSinh[i] != 'A') && (dapAn_HocSinh[i] != 'B') && (dapAn_HocSinh[i] != 'C') && (dapAn_HocSinh[i] != 'D'));
         
        if (dt.getDapAn(i) == dapAn_HocSinh[i]) diem++;
    }


    diem = diem/dt.getSoCau() * 10;


    cout << "\t\t\t\t\t           ________________" << endl;
    cout << "\t\t\t\t\t          |                |" << endl;
    cout << "\t\t\t\t\t          | "; printLineColor("Diem: ",3); cout << left << setw(7) << diem << "  |" << endl;
    cout << "\t\t\t\t\t          |________________|" << endl;

    ofstream outFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt", ios::app);

    outFile << id_DeThi << " " << diem << " ";

    for (int i=0; i < dt.getSoCau() ; i++)
        outFile << dapAn_HocSinh[i] << " ";

    outFile << "\n";

    outFile.close();
}

void TrangHocSinh::XemDiemThi(string id_HocSinh)
{
    string id_DeThi;
    cout << "\t\t\t\t\t         Nhap id de thi: ";  cin >> id_DeThi;

    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id_DeThi) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t            De thi khong ton tai", 4);
        cout << endl;
        return;
    }

    DeThi dt = LayDeThiTuCoSoDuLieu(id_DeThi);

    ifstream inFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt");
    string line;

    if ((! inFile.is_open()) || (inFile.peek() == ifstream::traits_type::eof())) 
    {
        cout << endl;
        printLineColor("\t\t\t\t         Ban chua lam de nay nen khong the xem duoc! \n", 4);
        return;
    }

    string* kq;
    while(getline(inFile, line))
    {
        kq = KetQua(line);

        if (kq[0] == id_DeThi) 
        {
            cout << endl;
            printLineColor("\t\t\t\t\t                 KET QUA", 6); cout << endl;
            cout << "\t\t\t\t\t         ______________________" << endl;
            cout << "\t\t\t\t\t        |                      |" << endl;
            cout << "\t\t\t\t\t        | "; printLineColor("Diem: ", 4); cout << setw(7) << kq[1] << "        |" << endl;
            
            if      (stof(kq[1]) >= 9) cout << "\t\t\t\t\t        | Xep loai: XUAT SAC   |\n";
            else if (stof(kq[1]) >= 8) cout << "\t\t\t\t\t        | Xep loai: GIOI       |\n";
            else if (stof(kq[1]) >= 7) cout << "\t\t\t\t\t        | Xep loai: KHA        |\n";
            else if (stof(kq[1]) >= 6) cout << "\t\t\t\t\t        | Xep loai: TRUNG BINH |\n";
            else if (stof(kq[1]) >= 5) cout << "\t\t\t\t\t        | Xep loai: YEU        |\n";
            else                       cout << "\t\t\t\t\t        | Xep loai: CUC YEU    |\n";
            cout << "\t\t\t\t\t        |______________________|" << endl;

            char chon;
            cout << endl;
            cout << "\t\t\t\t    Ban co muon nhin dap an ban da chon khong? (Y/N): "; cin >> chon;
            if (chon != 'Y') return;

            DeThi dt = LayDeThiTuCoSoDuLieu(kq[0]);
            cout << endl;
            for (int i = 0; i < dt.getSoCau() ; i++)
                cout << "\t\t\t\t\t         Cau " << i+1 << ": " << kq[i+2] << endl;
            return;
        }
    }

    cout << endl;
    printLineColor("\t\t\t\t\t   Ban chua lam de nay nen khong co diem! \n", 4);
}

void TrangHocSinh::HienThi(string id)
{
    system("cls");
    int chon;
  //  HocSinh hs = LayHocSinhTuCoSoDuLieu(id);
  //  cout << "Xin chao, " << hs.getTen() << endl;
    do
    {
        TrangHocSinh::HienThiNhiemVu();
        cout << endl;
        cout << "\t\t\t\t\t       -> Moi ban chon: "; cin >> chon;
        cout << endl;
        switch(chon)
        {
            case 1: XemThongTinHocSinh(id);                    
                    break;
            case 2: printLineColor("\t\t\t\t\t            CAP NHAT TAI KHOAN", 6); cout << endl << endl;
                    CapNhatHocSinhTrongCoSoDuLieu(id); cout << endl;
                    printLineColor("\t\t\t\t\t            CAP NHAT THANH CONG",2); cout << endl;
                    break;
            case 3: 
                    printLineColor("\t\t\t\t\t                XEM DE THI", 6); cout << endl << endl;
                    XemDe(id);
                    break;
            case 4:
            {
                string id_DeThi;
                printLineColor("\t\t\t\t\t               LAM DE THI", 6); cout << endl << endl;
                cout << "\t\t\t\t\t           Nhap id de: "; cin >> id_DeThi; cout << endl;
                TrangHocSinh::LamDe(id, id_DeThi);
                break;
            } 
            case 5: TrangHocSinh::XemDiemThi(id);
                    break;
            case 6: 
            {
                system("cls");
                return;
            } 
            default: printLineColor("\t\t\t\t\t\t     Ban da nhap sai", 4); cout << endl; 
        }
        cout << endl;
        cout << "\t\t\t\t\t      Nhan phim bat ky de tiep tuc ";
        getch();
        
        system("cls");
    }
    while (chon != 6);
}