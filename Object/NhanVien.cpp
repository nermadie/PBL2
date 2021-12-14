#include "NhanVien.h"
#include <fstream>
#include <iomanip>
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
    cout << "\t|" << setw(5) << right << _ID << " |";
    cout << " " << setw(28) << left << _Name << "|";
    cout << " ";
    _Birthday.ShowDate();
    cout << " |  ";
    _AdmissionDate.ShowDate();
    cout << "   | " << setw(12) << left << _PhoneNumber;
    cout << "| " << setw(24) << left << _Address;
    cout << "|     ";
    if (_Gender)
        cout << setw(9) << left << " Nu";
    else
        cout << setw(9) << left << " Nam";
    cout << "| " << setw(11) << right << _Wage << " |" << endl;
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
    o << "\t|" << setw(5) << right << nv._ID << " |";
    o << " " << setw(28) << left << nv._Name << "|";
    o << " ";
    Date a = nv._Birthday;
    a.ShowDate();
    o << " |  ";
    a = nv._AdmissionDate;
    a.ShowDate();
    o << "   | " << setw(12) << left << nv._PhoneNumber;
    o << "| " << setw(24) << left << nv._Address;
    o << "|     ";
    if (nv._Gender)
        o << setw(9) << left << " Nu";
    else
        o << setw(9) << left << " Nam";
    o << "| " << setw(11) << right << nv._Wage << " |" << endl;
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
void NhanVien::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _ID << '|';
    FileOut << _Name << '|';
    FileOut << _Birthday << '|';
    FileOut << _AdmissionDate << '|';
    FileOut << _PhoneNumber << '|';
    FileOut << _Address << '|';
    FileOut << _Gender << '|';
    FileOut << _Wage;
}