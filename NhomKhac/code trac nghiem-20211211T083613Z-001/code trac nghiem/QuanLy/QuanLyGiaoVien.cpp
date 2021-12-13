#pragma once
#include "../HeThong/User/Giao_Vien/GiaoVien.cpp"
#include "./QuanLy.cpp"
#include "../ThuVien/Console.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include<string>
using namespace std;

void ThemGiaoVienVaoCoSoDuLieu(GiaoVien gv)
{
    string filePath = "./CoSoDuLieu/GiaoVien/";
    string fileName = gv.getId() + ".txt";

    ofstream outFile(filePath + fileName);

    outFile << gv.getId() << "\n";
    outFile << gv.getTen() << "\n";
    outFile << gv.getTuoi() << "\n";
    outFile << gv.getGioiTinh() << "\n";
    outFile << gv.getMatKhau() << "\n";

    outFile.close();

    ofstream outFileId(filePath + "GiaoVien_id.txt", ios::app);
    outFileId << gv.getId() << "\n";
    outFileId.close();

    ofstream outFileTaiKhoan("./CoSoDuLieu/TaiKhoan.txt", ios::app);
    outFileTaiKhoan << gv.getId() << " " << gv.getTen() << " " << gv.getMatKhau() << "\n";
    outFileTaiKhoan.close();
}

GiaoVien LayGiaoVienTuCoSoDuLieu(string id)
{
    if (!kiemTraId("./CoSoDuLieu/GiaoVien/GiaoVien_id.txt", id))  return GiaoVien();
    string filePath = "./CoSoDuLieu/GiaoVien/";
    string fileName = id + ".txt";

    ifstream inFile(filePath + fileName);
    if (!inFile.is_open()) {
        cout << "File khong ton tai\n";
        return GiaoVien();
    }
    string line;

    string ten, matKhau;
    int  tuoi;
    bool gioiTinh;
    string diaChi, sdt, dob;

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

    return GiaoVien(id, ten, tuoi, gioiTinh, matKhau);
}

void XoaGiaoVienTuCoSoDuLieu(string id)
{
    string filePath = "./CoSoDuLieu/GiaoVien/";
    string fileName = id + ".txt";

    if (!kiemTraId(filePath + "GiaoVien_id.txt", id)) return;

    char char_filePath[(filePath + fileName).length() + 1];
    strcpy(char_filePath, (filePath + fileName).c_str());

    remove(char_filePath);

    XoaDongTrongFile("./CoSoDuLieu/GiaoVien/GiaoVien_id.txt", id);
}

void CapNhatGiaoVienTrongCoSoDuLieu(string id)
{
    if (!kiemTraId("./CoSoDuLieu/GiaoVien/GiaoVien_id.txt", id)) return;

    GiaoVien gv = LayGiaoVienTuCoSoDuLieu(id);
    XoaGiaoVienTuCoSoDuLieu(id);

    string ten, matKhau;
    int  tuoi;
    bool gioiTinh;
    string diaChi, sdt, dob;

    ten = getStringInput("Nhap ten");
    tuoi = getIntInput("Nhap tuoi");
    gioiTinh = getIntInput("Nhap gioi tinh");
    matKhau = getStringInput("Nhap mat khau");

    GiaoVien gv_moi(id, ten, tuoi, gioiTinh, matKhau);
    ThemGiaoVienVaoCoSoDuLieu(gv_moi);
}

void NhapGiaoVien()
{
    string id, ten, matKhau;
    int tuoi;
    bool gioiTinh;

    id = getStringInput("Nhap id");
    ten = getStringInput("Nhap ten");
    tuoi = getIntInput("Nhap tuoi");
    gioiTinh = getIntInput("Nhap gioi tinh");
    matKhau = getStringInput("Nhap mat khau");

    GiaoVien gv(id, ten, tuoi, gioiTinh, matKhau);
    ThemGiaoVienVaoCoSoDuLieu(gv);
}