#include "NhanVien.h"

NhanVien::NhanVien() {}

NhanVien::NhanVien(int id, string name, Date bi, Date ad, string pn, string address, bool g, double w)
{
    this->_ID = id;
    this->_Name = name;
    this->_Birthday = bi;
    this->_AdmissionDate = ad;
    this->_PhoneNumber = pn;
    this->_Address = address;
    this->_Gender = g;
    this->_Wage = w;
}
NhanVien::NhanVien(const NhanVien &nv)
{
    this->_ID = nv._ID;
    this->_Name = nv._Name;
    this->_Birthday = nv._Birthday;
    this->_AdmissionDate = nv._AdmissionDate;
    this->_PhoneNumber = nv._PhoneNumber;
    this->_Address = nv._Address;
    this->_Gender = nv._Gender;
    this->_Wage = nv._Wage;
}
NhanVien::~NhanVien() {}
void NhanVien::ShowNV()
{
    cout << "ID: " << _ID;
    cout << "Ten nhan vien: " << _Name;
    cout << ", Ngay sinh: ";
    _Birthday.ShowDate();
    cout << ", Ngay nhan vao: ";
    _AdmissionDate.ShowDate();
    cout << ", SDT: " << _PhoneNumber;
    cout << ", Dia chi: " << _Address;
    cout << ", Gioi tinh: ";
    if (_Gender)
        cout << "Nu";
    else
        cout << "Nam";
    cout << ", Luong: " << _Wage << endl;
}
int NhanVien::ID()
{
    return this->_ID;
}
void NhanVien::ID(int value)
{
    this->_ID = value;
}
void NhanVien::Name(string value)
{
    this->_Name = value;
}
void NhanVien::Birthday(Date value)
{
    this->_Birthday = value;
}
void NhanVien::AdmissionDate(Date value)
{
    this->_AdmissionDate = value;
}
void NhanVien::PhoneNumber(string value)
{
    this->_PhoneNumber = value;
}
void NhanVien::Address(string value)
{
    this->_Address = value;
}
void NhanVien::Gender(bool value)
{
    this->_Gender = value;
}
void NhanVien::Wage(double value)
{
    this->_Wage = value;
}
ostream &operator<<(ostream &o, const NhanVien &nv) // Tương tự hàm ShowNV
{
    o << "ID: " << nv._ID;
    o << "Ten nhan vien: " << nv._Name;
    cout << ", Ngay sinh: ";
    Date temp = nv._Birthday;
    temp.ShowDate();
    cout << ", Ngay nhan vao: ";
    temp = nv._AdmissionDate;
    temp.ShowDate();
    o << ", SDT: " << nv._PhoneNumber;
    o << ", Dia chi: " << nv._Address;
    o << ", Gioi tinh: ";
    if (nv._Gender)
        o << "Nu";
    else
        o << "Nam";
    o << ", Luong: " << nv._Wage << endl;
    return o;
}

istream &operator>>(istream &in, NhanVien &nv)
{
    int check;
    cout << "Nhap ten nhan vien: ";
    char str[100];
    in.getline(str, sizeof(str)); // Trường hợp đặc biệt
    nv._Name = str;
    cout << "Nhap ngay sinh: ";
    in >> nv._Birthday;
    cout << "Nhap ngay nhan vao: ";
    in >> nv._AdmissionDate;
    cout << "Nhap so dien thoai: ";
    in >> nv._PhoneNumber;
    cout << "Nhap dia chi: "; // Trường hợp đặc biệt
    fgets(str, 100, stdin);
    in.getline(str, sizeof(str));
    nv._Address = str;
    cout << "Nhap gioi tinh: ";
    string gender;
    do
    {
        if (check == 1)
            cout << "Sai cu phap gioi tinh, moi ban nhap lai :";
        check = 1;
        in >> gender;
        if (gender == "nam" || gender == "Nam" || gender == "0")
        {
            nv._Gender = 0;
            check = 0;
        }
        else if (gender == "Nu" || gender == "nu" || gender == "1")
        {
            nv._Gender = 1;
            check = 0;
        }
    } while (check);
    cout << "Nhap luong: ";
    in >> nv._Wage;
    return in;
}
