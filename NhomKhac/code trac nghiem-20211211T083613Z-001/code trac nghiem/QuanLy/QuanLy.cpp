#pragma once
#include "../HeThong/User/User.cpp"
#include "../ThuVien/ConSole.cpp"
#include <iostream>
#include <fstream>
using namespace std;

// Update line input in file
        //path: path to file in database, start from main.cpp file
        //inLine: line to update
        //replaceValue: new line value
void capNhatDong(string path, string inLine, string replaceValue) 
{
    string line;
    ifstream fin;
    
    fin.open(path);
    if (!fin.is_open()) {
        cout << "Error!\n";
    }
    ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        if (line == inLine) {
            temp << replaceValue << "\n";
            continue;
        }
        temp << line << "\n";
    }

    temp.close();
    fin.close();

    const char * p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

void XoaDongTrongFile(string path, string eraseLine) 
{
    std::string line;
    std::ifstream fin;
    
    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != eraseLine)
            temp << line << std::endl;
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char * p = path.c_str();
    remove(p);
    rename("temp.txt", p);
    
}

bool kiemTraId(string path, string id)
{
    ifstream inFile(path);
    string line;
    while (getline(inFile, line))
    {
        if (line == id) return true;
    }
    return false;
}

User LayThongTinDangNhap(string info)
{
    string id, ten, matKhau;
    
    int ViTriDauCachDauTien = info.find_first_of(" ");
    int ViTriDauCachCuoiCung = info.find_last_of(" ");

    id = info.substr(0, ViTriDauCachDauTien);
    ten = info.substr(ViTriDauCachDauTien + 1, ViTriDauCachCuoiCung - ViTriDauCachDauTien - 1);
    matKhau = info.substr(ViTriDauCachCuoiCung + 1, info.length() - ViTriDauCachCuoiCung);

    return User(id, ten, matKhau);
}

struct Node
{   
    User user;
    Node *next;
};

struct List
{
    Node* head;
};

void khoiTaoDanhSach(List &l)
{
    l.head = NULL;
}

Node* taoNode(User user)
{
    Node *p = new Node;
    p->user = user;
    p->next = NULL;
    return p;
}

List LayThongTinToanBoUser()
{
    List l;
    khoiTaoDanhSach(l);

    ifstream inFile("./CoSoDuLieu/TaiKhoan.txt");
    string line;

    while(getline(inFile, line))
    {
        Node* p = taoNode(LayThongTinDangNhap(line));
        if (l.head == NULL) l.head = p;
        else
        {
            p->next = l.head;
            l.head=p;
        }
    }

    inFile.close();

    return l;
}

string TimUser(string id, string ten, string matKhau)
{
    List l = LayThongTinToanBoUser();
    Node *p;
    for (p = l.head; p!=NULL; p=p->next)
	{
		if (((p->user).getTen() == ten) && ((p->user).getMatKhau() == matKhau) && ((p->user).getId() == id))
            return (p->user).getId();
	}
    
    return "";
}

User DangNhap()
{
    string ten, matKhau, id;
    do
    {
        cout << endl;
        id  = getStringInput("\t\t\t\t\t     Nhap ID");
        ten = getStringInput("\t\t\t\t\t     Nhap ten");
        matKhau = getStringInput("\t\t\t\t\t     Nhap mat khau");
        id = TimUser(id, ten, matKhau);
        if (id == "") printLineColor("\t\t\t\t\t\t     Ban da nhap sai! \n", 4);
    } while (id == "");
    cout << "\t\t\t\t\t     Dang nhap thanh cong!\n\n";
    return User(id, ten, matKhau);
}

