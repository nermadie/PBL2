#include "KhachHang.h"
#include <fstream>
#include <iomanip>
KhachHang::KhachHang() {}
KhachHang::KhachHang(int id, string name, Date bi, string pn, string address, bool g)
{
    this->_ID = id;
    this->_Name = name;
    this->_Birthday = bi;
    this->_PhoneNumber = pn;
    this->_Address = address;
    this->_Gender = g;
}
KhachHang::KhachHang(const KhachHang &nv)
{
    this->_ID = nv._ID;
    this->_Name = nv._Name;
    this->_Birthday = nv._Birthday;
    this->_PhoneNumber = nv._PhoneNumber;
    this->_Address = nv._Address;
    this->_Gender = nv._Gender;
}
KhachHang::~KhachHang() {}
void KhachHang::ShowKhachHang()
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    cout << "\t\t\t|" << setw(5) << right << _ID << " |";
=======
    cout << "\t|" << setw(5) << right << _ID << " |";
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
=======
    cout << "\t|" << setw(5) << right << _ID << " |";
>>>>>>> parent of 465bfc4 (ql)
=======
    cout << "\t|" << setw(5) << right << _ID << " |";
>>>>>>> parent of 465bfc4 (ql)
    cout << " " << setw(28) << left << _Name << " |";
    cout << " ";
    _Birthday.ShowDate();
    cout << " | " << setw(12) << left << _PhoneNumber;
    cout << "| " << setw(24) << left << _Address;
    cout << "|     ";
    if (_Gender)
        cout << setw(9) << left << " Nu";
    else
        cout << setw(9) << left << " Nam";
    cout << "|" << endl;
}
int KhachHang::ID()
{
    return this->_ID;
}
void KhachHang::ID(int value)
{
    this->_ID = value;
}
void KhachHang::Name(string value)
{
    this->_Name = value;
}
void KhachHang::Birthday(Date value)
{
    this->_Birthday = value;
}
void KhachHang::PhoneNumber(string value)
{
    this->_PhoneNumber = value;
}
void KhachHang::Address(string value)
{
    this->_Address = value;
}
void KhachHang::Gender(bool value)
{
    this->_Gender = value;
}
istream &operator>>(istream &in, KhachHang &nv)
{
    int check;
    cout << "Nhap ten khach hang: ";
    char str[100];
<<<<<<< HEAD
    fflush(stdin);
=======
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
    in.getline(str, sizeof(str)); // Trường hợp đặc biệt
    nv._Name = str;
    cout << "Nhap ngay sinh: ";
    in >> nv._Birthday;
    cout << "Nhap so dien thoai: ";
    in >> nv._PhoneNumber;
    cout << "Nhap dia chi: "; // Trường hợp đặc biệt
<<<<<<< HEAD
    fflush(stdin);
=======
    fgets(str, 100, stdin);
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
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
    return in;
}
void KhachHang::InsertObjecttoFile(ofstream &FileOut)
{
    FileOut << _ID << '|';
    FileOut << _Name << '|';
    FileOut << _Birthday << '|';
    FileOut << _PhoneNumber << '|';
    FileOut << _Address << '|';
    FileOut << _Gender;
}