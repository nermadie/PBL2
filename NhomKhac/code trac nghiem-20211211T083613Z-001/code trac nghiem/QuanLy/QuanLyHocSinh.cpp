#pragma once
#include "../HeThong/User/Hoc_Sinh/HocSinh.cpp"
#include "./QuanLy.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include "../ThuVien/Console.cpp"
using namespace std;

void ThemHocSinhVaoCoSoDuLieu(HocSinh hs)
{
    string filePath = "./CoSoDuLieu/HocSinh/";
    string fileName = hs.getId() + ".txt";

    ofstream outFile(filePath + fileName);

    outFile << hs.getId() << "\n";
    outFile << hs.getTen() << "\n";
    outFile << hs.getTuoi() << "\n";
    outFile << hs.getGioiTinh() << "\n";
    outFile << hs.getMatKhau() << "\n";

    outFile.close();

    ofstream outFileId(filePath + "HocSinh_id.txt", ios::app);
    outFileId << hs.getId() << "\n";
    outFileId.close();

    ofstream outFileTaiKhoan("./CoSoDuLieu/TaiKhoan.txt", ios::app);
    outFileTaiKhoan << hs.getId() << " " << hs.getTen() << " " << hs.getMatKhau() << "\n";
    outFileTaiKhoan.close();
}

HocSinh LayHocSinhTuCoSoDuLieu(string id)
{
    
    string filePath = "./CoSoDuLieu/HocSinh/";
    string fileName = id + ".txt";

    if (!kiemTraId(filePath + "HocSinh_id.txt", id)) return HocSinh();
    
    ifstream inFile(filePath + fileName);
    string line;

    string ten, matKhau;
    int  tuoi;
    bool gioiTinh;

    getline(inFile, line);
    id = line;
    getline(inFile, line);
    ten = line;
    getline(inFile, line);
    tuoi = stoi(line);
    getline(inFile, line);
    gioiTinh = stoi(line);
    getline(inFile, line);
    matKhau = line;

    return HocSinh(id, ten, tuoi, gioiTinh, matKhau);
}

void XoaHocSinhTuCoSoDuLieu(string id)
{
    string filePath = "./CoSoDuLieu/HocSinh/";
    string fileName = id + ".txt";

    HocSinh hs = LayHocSinhTuCoSoDuLieu(id);

    if (!kiemTraId(filePath + "HocSinh_id.txt", id)) return;

    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    remove(char_filePath);

    XoaDongTrongFile("./CoSoDuLieu/HocSinh/HocSinh_id.txt", id);

    string dongCanXoa = id + " " + hs.getTen() + " " + hs.getMatKhau();
    XoaDongTrongFile("./CoSoDuLieu/TaiKhoan.txt", dongCanXoa);
}

void XoaDiemThiHocSinh(string id) // id cua hoc sinh
{
    string filePathDiemThi = "./CoSoDuLieu/DiemThi/";
    string fileNameDiemThi = id + ".txt";
    char char_filePathDiemThi[(filePathDiemThi + fileNameDiemThi).length() + 1];
    strcpy(char_filePathDiemThi, (filePathDiemThi + fileNameDiemThi).c_str());

    remove(char_filePathDiemThi);
}

void CapNhatHocSinhTrongCoSoDuLieu(string id)
{

    if (!kiemTraId("./CoSoDuLieu/HocSinh/HocSinh_id.txt", id)) return;
    HocSinh hs = LayHocSinhTuCoSoDuLieu(id);
    XoaHocSinhTuCoSoDuLieu(id);

    string ten, matKhau;
    int  tuoi;
    bool gioiTinh;

    ten = getStringInput("\t\t\t\t               Nhap ten");
    tuoi = getIntInput("\t\t\t\t               Nhap tuoi");
    gioiTinh = getIntInput("\t\t\t\t               Nhap gioi tinh");
    matKhau = getStringInput("\t\t\t\t               Nhap mat khau");

    HocSinh hs_moi(id, ten, tuoi, gioiTinh, matKhau);
    ThemHocSinhVaoCoSoDuLieu(hs_moi);
}

void NhapHocSinh(string id)
{
    string ten, matKhau;
    int tuoi;
    bool gioiTinh;

    ten = getStringInput("\t\t\t\t\t     Nhap ten");
    tuoi = getIntInput("\t\t\t\t\t     Nhap tuoi");
    gioiTinh = getIntInput("\t\t\t\t\t     Nhap gioi tinh");
    matKhau = getStringInput("\t\t\t\t\t     Nhap mat khau");

    HocSinh hs(id, ten, tuoi, gioiTinh, matKhau);
    ThemHocSinhVaoCoSoDuLieu(hs);
}