#include "QLNV.h"
#include <fstream>
#include <conio.h>
QLNV::QLNV()
{
    ifstream FileIn("Database/NhanVien/nhanvien.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay Database! Ban co muon tao Database moi?(Y/N)" << endl;
        if (!kbhit())
        {
            char key = getch();
            if (key == 27 || key == 'n' || key == 'N')
            {
                throw "Hay xem xet lai Database va khoi dong lai chuong trinh";
            }
            else if (key == 'Y' || key == 'y')
            {
                this->_QLNV = nullptr;
                this->_Quantity = 0;
            }
        }
    }
    else
    {
        _Quantity = 0;
        while (FileIn.eof() == false)
        {
            int id;
            string name, phonenumber, address;
            bool gender;
            double wage;
            char separator;
            int dd1, mm1, yyyy1, dd2, mm2, yyyy2;
            FileIn >> id >> separator;
            getline(FileIn, name, ',');
            FileIn >> dd1 >> separator >> mm1 >> separator >> yyyy1 >> separator;
            FileIn >> dd2 >> separator >> mm2 >> separator >> yyyy2 >> separator;
            getline(FileIn, phonenumber, ',');
            getline(FileIn, address, ',');
            FileIn >> gender >> separator;
            FileIn >> wage;
            NhanVien A(id, name, Date(dd1, mm1, yyyy1), Date(dd2, mm2, yyyy2), phonenumber, address, gender, wage);
            AddtotheEnd(A);
        }
    }
    FileIn.close();
}
QLNV::QLNV(NhanVien *QLNV, int quantity) : _QLNV(QLNV), _Quantity(quantity) {}
QLNV::QLNV(const QLNV &l)
{
    this->_QLNV = l._QLNV;
    this->_Quantity = l._Quantity;
}
QLNV::~QLNV()
{
    ofstream FileOut("Database/NhanVien/nhanvien.txt", ios_base::out);
    for (int i = 0; i < _Quantity; i++)
    {
        (_QLNV + i)->InsertObjecttoFile(FileOut);
    }
    FileOut.close();
    delete[] this->_QLNV;
}
void QLNV::Show()
{
    cout << "Danh Sach Nhan Vien:" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        _QLNV[i].ShowNV();
}
// Them doi tuong-------------------------------------------------
//  + Them vao cuoi danh sach
void QLNV::AddtotheEnd(NhanVien &nv)
{
    // Ngoại lệ:
    if (-1 != IndexOf(nv.ID()))
    {
        string a = "ID ";
        string id = to_string(nv.ID());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    // Không lỗi:
    if (this->_Quantity == 0)
    {
        this->_QLNV = new NhanVien[this->_Quantity + 1];
        *(this->_QLNV + this->_Quantity) = nv;
    }
    else
    {
        NhanVien *temp = new NhanVien[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLNV + i);
        delete[] this->_QLNV;
        this->_QLNV = new NhanVien[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLNV + i) = *(temp + i);
        delete[] temp;
        *(this->_QLNV + this->_Quantity) = nv;
    }
    this->_Quantity++;
}
//  + Them vao dau danh sach
void QLNV::AddtoTop(NhanVien &nv)
{
    if (-1 != IndexOf(nv.ID()))
    {
        string a = "ID ";
        string id = to_string(nv.ID());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLNV = new NhanVien[this->_Quantity + 1];
        *(this->_QLNV + this->_Quantity) = nv;
    }
    else
    {
        NhanVien *temp = new NhanVien[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLNV + i);
        delete[] this->_QLNV;
        this->_QLNV = new NhanVien[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLNV + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLNV) = nv;
    }
    this->_Quantity++;
}
//  + Them vao vi tri bat ky
void QLNV::AddtoPosition(NhanVien &nv, int position)
{
    if (-1 != IndexOf(nv.ID()))
    {
        string a = "ID ";
        string id = to_string(nv.ID());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLNV = new NhanVien[this->_Quantity + 1];
            *(this->_QLNV + this->_Quantity) = nv;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            NhanVien *temp = new NhanVien[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLNV + i);
            delete[] this->_QLNV;
            this->_QLNV = new NhanVien[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLNV + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLNV + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLNV + position) = nv;
            this->_Quantity++;
        }
    }
}
// Cap nhat thong tin(Theo thuoc tinh MS Nhan vien(ID))-------------
// Cap nhat : Thay doi ca ID, Name, AdmissionDate, Gender, Wage
void QLNV::Update(const int &id)
{
    int index = IndexOf(id);
    if (index >= 0)
    {
        int check = 1;
        cout << "Nhap ID nhan vien: ";
        while (check)
        {
            int ID;
            cin >> ID;
            if (-1 != IndexOf(ID))
            {
                cout << "Da co nhan vien co ID nay!! Xin moi ban nhap lai: ";
            }
            else
            {
                (this->_QLNV + index)->ID(ID);
                check = 0;
                cin >> *(this->_QLNV + index);
            }
        }
    }
    else
        cout << "Khong co nhan vien co MSNV: " << id << endl;
}
// Xoa doi tuong---------------------------------------------------------
//  + Xoa doi tuong dau tien
void QLNV::DeleteTop()
{
    int index = 0;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLNV;
    }
    else
    {
        NhanVien *temp = new NhanVien[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLNV + i);
        delete[] this->_QLNV;
        this->_QLNV = new NhanVien[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLNV + i) = *(temp + i);
            }
            else
            {
                *(this->_QLNV + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa doi tuong cuoi cung
void QLNV::DeleteEnd()
{
    int index = _Quantity - 1;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLNV;
    }
    else
    {
        NhanVien *temp = new NhanVien[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLNV + i);
        delete[] this->_QLNV;
        this->_QLNV = new NhanVien[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLNV + i) = *(temp + i);
            }
            else
            {
                *(this->_QLNV + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa tai vi tri k bat ky
void QLNV::DeleteatPosition(const int &position)
{
    int index = position;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLNV;
    }
    else
    {
        NhanVien *temp = new NhanVien[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLNV + i);
        delete[] this->_QLNV;
        this->_QLNV = new NhanVien[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLNV + i) = *(temp + i);
            }
            else
            {
                *(this->_QLNV + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
// Tim kiem(BinarySearch)-----------------------------------
//  + Tim Index tuong ung voi ID
int QLNV::BinarySearch(int l, int r, int id) // Vi ID chua sort nen xet ca 2 phia
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if ((this->_QLNV + mid)->ID() == id)
            return mid;
        int A = BinarySearch(l, mid - 1, id);
        int B = BinarySearch(mid + 1, r, id);
        if (A != -1)
            return A;
        else if (B != -1)
            return B;
        else
            return -1;
    }
    return -1;
}
int QLNV::IndexOf(int id)
{
    return BinarySearch(0, _Quantity - 1, id);
}
// Sap xep(InsertionSort) voi thuoc tinh _ID----------------
// Ham TD và GD được định nghĩa ở duoi
bool GD(int a, int b)
{
    return a < b;
}
bool TD(int a, int b)
{
    return a > b;
}
void QLNV::Sort(bool (*CTH)(int a, int b) = TD)
{
    int *tempIndex = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(tempIndex + i) = i; // Mang index
    int i, j;
    for (i = 1; i < _Quantity; i++)
    {
        j = i - 1;
        while (j >= 0 && CTH((this->_QLNV + j)->ID(), (this->_QLNV + i)->ID()))
        {
            tempIndex[j + 1] = tempIndex[j];
            j--;
        }
        tempIndex[j + 1] = i;
    }
    NhanVien *temp = new NhanVien[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLNV + i);
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLNV + i) = *(temp + *(tempIndex + i));
    delete[] temp;
}
void QLNV::ImportFromFile()
{
    ifstream FileIn("Database/NhanVien/import.txtimport.txt", ios_base::in);
    while (FileIn.eof() == false)
    {
        int id;
        string name, phonenumber, address;
        bool gender;
        double wage;
        char separator;
        int dd1, mm1, yyyy1, dd2, mm2, yyyy2;
        FileIn >> id >> separator;
        getline(FileIn, name, ',');
        FileIn >> dd1 >> separator >> mm1 >> separator >> yyyy1 >> separator;
        FileIn >> dd2 >> separator >> mm2 >> separator >> yyyy2 >> separator;
        getline(FileIn, phonenumber, ',');
        getline(FileIn, address, ',');
        FileIn >> gender >> separator;
        FileIn >> wage;
        NhanVien A(id, name, Date(dd1, mm1, yyyy1), Date(dd2, mm2, yyyy2), phonenumber, address, gender, wage);
        AddtotheEnd(A);
    }
}