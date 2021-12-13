#pragma once
#include "../HeThong/DeThi/DeThi.cpp"
#include "../ThuVien/Console.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include "QuanLy.cpp"
using namespace std;

void ThemDeThiVaoCoSoDuLieu(DeThi dt)
{
    string filePath = "./CoSoDuLieu/DeThi/";
    string fileName = dt.getId() + ".txt";

    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", dt.getId()) == true)
    {
        cout << "\t\t\t\t\t        De thi da ton tai \n";
        return;
    }

    ofstream outFile(filePath + fileName);
    
    string* cauHoi = new string[dt.getSoCau()];
    string* dapAnA = new string[dt.getSoCau()];
    string* dapAnB = new string[dt.getSoCau()];
    string* dapAnC = new string[dt.getSoCau()];
    string* dapAnD = new string[dt.getSoCau()];
    char* dapAn = new char[dt.getSoCau()];
  
    cauHoi = dt.getCauHoi();
    dapAnA = dt.getDapAnA();
    dapAnB = dt.getDapAnB();
    dapAnC = dt.getDapAnC();
    dapAnD = dt.getDapAnD();
    dapAn = dt.getDapAn();

    for (int i = 0 ; i < dt.getSoCau() ; ++i)
    {  
        outFile << cauHoi[i] << "\n";
        outFile << dapAnA[i] << "\n";
        outFile << dapAnB[i] << "\n";
        outFile << dapAnC[i] << "\n";
        outFile << dapAnD[i] << "\n";
        outFile << dapAn[i]  << "\n";
    }

    outFile.close();

    ofstream outFileId(filePath + "DeThi_id.txt", ios::app);
    outFileId << dt.getId() << "\n";
    outFile.close();
}

DeThi LayDeThiTuCoSoDuLieu(string id) 
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t        De thi khong ton tai \n", 4);
        return DeThi();
    }

    string filePath = "./CoSoDuLieu/DeThi/";
    string fileName = id + ".txt";
    
    string* cauHoi = new string[50];
    string* dapAnA = new string[50];
    string* dapAnB = new string[50];
    string* dapAnC = new string[50];
    string* dapAnD = new string[50];
    char* dapAn = new char[50];
    
    string line;
    int i = 0; // stt dong
    int j = 0; // stt cau hoi 

    ifstream inFile(filePath + fileName);
    while (getline(inFile, line))
    {
        if (i % 6 == 0)
        {
            cauHoi[j] = line;
        }

        if (i % 6 == 1)
        {
            dapAnA[j] = line;
        }

        if (i % 6 == 2)
        {
            dapAnB[j] = line;
        }

        if (i % 6 == 3)
        {
            dapAnC[j] = line;
        }

        if (i % 6 ==4)
        {
            dapAnD[j] = line;
        }

        if (i % 6 == 5)
        {
            dapAn[j] = StringToChar(line);
            j++;
        }

        i++;
    }

    inFile.close();

    return DeThi(j, id, cauHoi, dapAnA, dapAnB, dapAnC, dapAnD, dapAn);
}

string* KetQua1(string line)
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

string DongDiemCanXoa(string id_HocSinh, string id_DeThi)
{
    ifstream inFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt");
    string line;

    string* kq;
    string l;
    
    while(getline(inFile, line))
    {
        kq = KetQua1(line);

        if (kq[0] == id_DeThi) 
        {
            l = line; 
            break;
        }
    }
    return l;    
}

bool XoaDeThiTuCoSoDuLieu(string id) 
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t          De thi khong ton tai \n", 4);
        return 0;
    }

    string filePath = "./CoSoDuLieu/DeThi/";
    string fileName = id + ".txt";
    
    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    remove(char_filePath);

    XoaDongTrongFile("./CoSoDuLieu/DeThi/DeThi_id.txt", id);

    ifstream inFileHocSinh("./CoSoDuLieu/HocSinh/HocSinh_id.txt");
    string line_HocSinh;
    string id_HocSinh;
    string l;

    while (getline(inFileHocSinh, line_HocSinh))
    {
        id_HocSinh = line_HocSinh;
        l = DongDiemCanXoa(id_HocSinh, id);
        XoaDongTrongFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt", l);
    }

    return 1;
}

bool CapNhatCauHoiTrongCoSoDuLieu(string id) 
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t\t    De thi khong ton tai \n", 4); 
        return 0;
    }

    string filePath = "./CoSoDuLieu/DeThi/";
    string fileName = id + ".txt";

    int vt;
    DeThi dt = LayDeThiTuCoSoDuLieu(id);

    cout << "\t\t\t\t           Nhap vi tri cau hoi muon cap nhat: "; cin >> vt;
    if (vt > dt.getSoCau() || vt <= 0)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t      Ban da nhap sai vi tri cau hoi!", 4);
        cout << endl;
        return 0;
    }
    cout << endl;
    string cauHoi = dt.getCauHoi()[vt - 1];
    string cauHoiMoi;
    printLineColor("\t\t\t\t       Nhap cau hoi moi: ", 6); cin >> cauHoiMoi ; fflush(stdin);
    capNhatDong(filePath + fileName, cauHoi, cauHoiMoi);

    string dapAnA = dt.getDapAnA()[vt - 1];
    string dapAnAMoi;
    printLineColor("\t\t\t\t       Nhap dap an A moi: ", 6); cin >> dapAnAMoi ; fflush(stdin);
    capNhatDong(filePath + fileName, dapAnA, dapAnAMoi);

    string dapAnB = dt. getDapAnB()[vt - 1];
    string dapAnBMoi;
    printLineColor("\t\t\t\t       Nhap dap an B moi: ", 6); cin >> dapAnBMoi ; fflush(stdin);
    capNhatDong(filePath + fileName, dapAnB, dapAnBMoi);

    string dapAnC = dt. getDapAnC()[vt - 1];
    string dapAnCMoi;
    printLineColor("\t\t\t\t       Nhap dap an C moi: ", 6); cin >> dapAnCMoi ; fflush(stdin);
    capNhatDong(filePath + fileName, dapAnC, dapAnCMoi);

    string dapAnD = dt. getDapAnD()[vt - 1];
    string dapAnDMoi;
    printLineColor("\t\t\t\t       Nhap dap an D moi: ", 6); cin >> dapAnDMoi ; fflush(stdin);
    capNhatDong(filePath + fileName, dapAnD, dapAnDMoi);

    char dapAn = dt.getDapAn()[vt - 1];
    char dapAnMoi;
    do
    {
        dapAnMoi = getCharInput("\t\t\t\t        Nhap dap an moi");
        if (dapAnMoi != 'A' && dapAnMoi != 'B' && dapAnMoi != 'C' && dapAnMoi != 'D') 
        {
            printLineColor("\t\t\t\t\t   Ban da nhap sai! Moi ban nhap lai!", 4); 
            cout << endl;
        }
    } while (dapAnMoi != 'A' && dapAnMoi != 'B' && dapAnMoi != 'C' && dapAnMoi != 'D');

    capNhatDong(filePath + fileName, to_string(dapAn), to_string(dapAnMoi));

    ifstream inFileHocSinh("./CoSoDuLieu/HocSinh/HocSinh_id.txt");
    string line_HocSinh;
    string id_HocSinh;
    string l;

    while (getline(inFileHocSinh, line_HocSinh))
    {
        id_HocSinh = line_HocSinh;
        l = DongDiemCanXoa(id_HocSinh, id);
        XoaDongTrongFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt", l);
    }

    return 1;
}

bool XoaCauHoiTrongDe(string id)
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t           De thi khong ton tai \n", 4);
        return 0;
    }

    string filePath = "./CoSoDuLieu/DeThi/";
    string fileName = id + ".txt";

    int vt;
    DeThi dt = LayDeThiTuCoSoDuLieu(id);

    do
    {
        cout << "\t\t\t\t\t     Nhap vi tri cau hoi muon xoa: "; cin >> vt;
        if (vt > dt.getSoCau() || vt <= 0)
        {
            cout << endl;
            printLineColor("\t\t\t\t      Ban da nhap sai vi tri cau hoi! Moi ban nhap lai! \n", 4);
            cout << endl;
        }
    } while (vt > dt.getSoCau() || vt <= 0);

    string cauHoi = dt.getCauHoi(vt - 1);
    string dapAnA = dt.getDapAnA(vt - 1);
    string dapAnB = dt.getDapAnB(vt - 1);
    string dapAnC = dt.getDapAnC(vt - 1);
    string dapAnD = dt.getDapAnD(vt - 1);
    char dapAn = dt.getDapAn(vt - 1);  
    string dapAn_str(1, dapAn);

    XoaDongTrongFile(filePath + fileName, cauHoi);
    XoaDongTrongFile(filePath + fileName, dapAnA);
    XoaDongTrongFile(filePath + fileName, dapAnB);
    XoaDongTrongFile(filePath + fileName, dapAnC);
    XoaDongTrongFile(filePath + fileName, dapAnD);
    XoaDongTrongFile(filePath + fileName, dapAn_str);

    ifstream inFileHocSinh("./CoSoDuLieu/HocSinh/HocSinh_id.txt");
    string line_HocSinh;
    string id_HocSinh;
    string l;

    while (getline(inFileHocSinh, line_HocSinh))
    {
        id_HocSinh = line_HocSinh;
        l = DongDiemCanXoa(id_HocSinh, id);
        XoaDongTrongFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt", l);
    }

    return 1;
}

bool NhapDeThi(string id) 
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id) == true)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t             De thi da ton tai \n", 4);
        return 0;
    }

    int soCau; 
    soCau = getIntInput("\t\t\t\t\t       Nhap so cau: ");
    
    string* cauHoi = new string[soCau];
    string* dapAnA = new string[soCau];
    string* dapAnB = new string[soCau];
    string* dapAnC = new string[soCau];
    string* dapAnD = new string[soCau];
    char* dapAn = new char[soCau];

    for (int i=0; i < soCau ; i++)
    {
        cauHoi[i] = getStringInput("\t\t\t\t       Nhap cau hoi");
        dapAnA[i] = getStringInput("\t\t\t\t       Nhap dap an A");
        dapAnB[i] = getStringInput("\t\t\t\t       Nhap dap an B");
        dapAnC[i] = getStringInput("\t\t\t\t       Nhap dap an C");
        dapAnD[i] = getStringInput("\t\t\t\t       Nhap dap an D");
        do
        {
            dapAn[i] = getCharInput("\t\t\t\t\t   Nhap dap an dung cho cau hoi");
            if ((dapAn[i] != 'A') && (dapAn[i] != 'B') && (dapAn[i] != 'C') && (dapAn[i] != 'D'))   
                printLineColor("\t\t\t\t\t           Ban da nhap sai! \n", 4);
        } while ((dapAn[i] != 'A') && (dapAn[i] != 'B') && (dapAn[i] != 'C') && (dapAn[i] != 'D'));
        cout << endl;
    }

    DeThi dt(soCau, id, cauHoi, dapAnA, dapAnB, dapAnC, dapAnD, dapAn);
    ThemDeThiVaoCoSoDuLieu(dt);
    return 1;
}

bool ThemCauHoiChoDeThi(string id) 
{
    if (kiemTraId("./CoSoDuLieu/DeThi/DeThi_id.txt", id) == false)
    {
        cout << endl;
        printLineColor("\t\t\t\t\t           De thi khong ton tai \n", 4);
        return 0;
    }

    DeThi temp = LayDeThiTuCoSoDuLieu(id);
    XoaDeThiTuCoSoDuLieu(id);
    
    string cauHoi, dapAnA, dapAnB, dapAnC, dapAnD;
    int dapAn;

    cauHoi = getStringInput("\t\t\t\t        Nhap cau hoi");
    dapAnA = getStringInput("\t\t\t\t        Nhap dap an A");
    dapAnB = getStringInput("\t\t\t\t        Nhap dap an B");
    dapAnC = getStringInput("\t\t\t\t        Nhap dap an C");
    dapAnD = getStringInput("\t\t\t\t        Nhap dap an D");
    do
    {
        dapAn = getCharInput("\t\t\t\t\t        Nhap dap an");
        if (dapAn != 'A' && dapAn != 'B' && dapAn != 'C' && dapAn != 'D') 
        {
            printLineColor("\t\t\t\t\t   Ban da nhap sai! Moi ban nhap lai!", 4); 
            cout << endl;
        }
    } while (dapAn != 'A' && dapAn != 'B' && dapAn != 'C' && dapAn != 'D');


    string* cauHoi_moi = new string[temp.getSoCau() + 1];
    string* dapAnA_moi = new string[temp.getSoCau() + 1];
    string* dapAnB_moi = new string[temp.getSoCau() + 1];
    string* dapAnC_moi = new string[temp.getSoCau() + 1];
    string* dapAnD_moi = new string[temp.getSoCau() + 1];
    char* dapAn_moi = new char[temp.getSoCau() + 1];

    for (int i=0 ; i < temp.getSoCau(); i++)
    {
        cauHoi_moi[i] = temp.getCauHoi(i);
        dapAnA_moi[i] = temp.getDapAnA(i);
        dapAnB_moi[i] = temp.getDapAnB(i);
        dapAnC_moi[i] = temp.getDapAnC(i);
        dapAnD_moi[i] = temp.getDapAnD(i);
        dapAn_moi[i] = temp.getDapAn(i);
    }

    cauHoi_moi[temp.getSoCau()] = cauHoi;
    dapAnA_moi[temp.getSoCau()] = dapAnA;
    dapAnB_moi[temp.getSoCau()] = dapAnB;
    dapAnC_moi[temp.getSoCau()] = dapAnC;
    dapAnD_moi[temp.getSoCau()] = dapAnD;
    dapAn_moi[temp.getSoCau()] = dapAn;

    DeThi dt(temp.getSoCau() + 1, id, cauHoi_moi, dapAnA_moi, dapAnB_moi, dapAnC_moi, dapAnD_moi, dapAn_moi);
    ThemDeThiVaoCoSoDuLieu(dt);

    ifstream inFileHocSinh("./CoSoDuLieu/HocSinh/HocSinh_id.txt");
    string line_HocSinh;
    string id_HocSinh;
    string l;

    while (getline(inFileHocSinh, line_HocSinh))
    {
        id_HocSinh = line_HocSinh;
        l = DongDiemCanXoa(id_HocSinh, id);
        XoaDongTrongFile("./CoSoDuLieu/DiemThi/" + id_HocSinh + ".txt", l);
    }

    return 1;
}