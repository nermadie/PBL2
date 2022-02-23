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
                system("pause");
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
        while (!FileIn.eof())
        {
            int id;
            string name, phonenumber, address;
            bool gender;
            double wage;
            char separator;
            int dd1, mm1, yyyy1, dd2, mm2, yyyy2;
            FileIn >> id >> separator;
            getline(FileIn, name, '|');
            FileIn >> dd1 >> separator >> mm1 >> separator >> yyyy1 >> separator;
            FileIn >> dd2 >> separator >> mm2 >> separator >> yyyy2 >> separator;
            getline(FileIn, phonenumber, '|');
            getline(FileIn, address, '|');
            FileIn >> gender >> separator;
            FileIn >> wage;
            NhanVien A(id, name, Date(dd1, mm1, yyyy1), Date(dd2, mm2, yyyy2), phonenumber, address, gender, wage);
            AddtotheEnd(A, FileIn);
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
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_QLNV + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_QLNV;
}
void QLNV::Show()
{
    cout << "\t+======================================================================================================================================+" << endl;
    cout << "\t|                                                    ** DANH SACH NHAN VIEN **                                                         |" << endl;
    cout << "\t+======+=============================+============+===============+=============+=========================+==============+=============+" << endl;
    cout << "\t|  ID  |        Ten nhan vien        | Ngay sinh  | Ngay gia nhap |     SDT     |         Dia chi         |  Gioi tinh   |    Luong    |" << endl;
    cout << "\t+======+=============================+============+===============+=============+=========================+==============+=============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        cout << _QLNV[i];
    cout << "\t+======+=============================+============+===============+=============+=========================+==============+=============+" << endl;
}
void QLNV::Show1NV(int id)
{
    cout << "\t+======================================================================================================================================+" << endl;
    cout << "\t|                                                    ** DANH SACH NHAN VIEN **                                                         |" << endl;
    cout << "\t+======+=============================+============+===============+=============+=========================+==============+=============+" << endl;
    cout << "\t|  ID  |        Ten nhan vien        | Ngay sinh  | Ngay gia nhap |     SDT     |         Dia chi         |  Gioi tinh   |    Luong    |" << endl;
    cout << "\t+======+=============================+============+===============+=============+=========================+==============+=============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        if ((this->_QLNV + i)->ID() == id)
            cout << _QLNV[i];
    cout << "\t+======+=============================+============+===============+=============+=========================+==============+=============+" << endl;
}
// Them doi tuong-------------------------------------------------
//  + Them vao cuoi danh sach
//  + Them vao dau danh sach
int QLNV::AddtotheEnd(NhanVien &nv)
{
    if (-1 != IndexOf(nv.ID()))
    {
        return 0;
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
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLNV + i) = *(temp + i);
        delete[] temp;
        *(this->_QLNV + this->_Quantity) = nv;
    }
    this->_Quantity++;
    return 1;
}
void QLNV::AddtotheEnd(NhanVien &nv, ifstream &FileIn)
{
    if (-1 != IndexOf(nv.ID()))
    {
        FileIn.close();
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
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLNV + i) = *(temp + i);
        delete[] temp;
        *(this->_QLNV + this->_Quantity) = nv;
    }
    this->_Quantity++;
}

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
void QLNV::AddtoTop(NhanVien &nv, ifstream &FileIn)
{
    if (-1 != IndexOf(nv.ID()))
    {
        FileIn.close();
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
void QLNV::AddtoPosition(NhanVien &nv, int position, ifstream &FileIn)
{
    if (-1 != IndexOf(nv.ID()))
    {
        FileIn.close();
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
        cout << "\t\t\t\t\t\tNhap ID moi cho nhan vien: ";
        while (check)
        {
            int ID;
            cin >> ID;
            if (-1 != IndexOf(ID))
            {
                cout << "\t\t\t\t\t\tDa co nhan vien co ID nay!! Xin moi ban nhap lai: ";
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
        cout << "\t\t\t\t\t\tKhong co nhan vien co MSNV: " << id << endl;
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
        delete[] temp;
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
        delete[] temp;
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
        delete[] temp;
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
// Sap xep(QuickSort) voi thuoc tinh _ID----------------
// Ham TD và GD được định nghĩa ở duoi

int QLNV::Partition(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    int pivot = (this->_QLNV + arr[high])->ID(); // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && !CTH((this->_QLNV + arr[left])->ID(), pivot))
            left++;
        while (right >= left && CTH((this->_QLNV + arr[right])->ID(), pivot))
            right--;
        if (left >= right)
            break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void QLNV::QuickSort(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, CTH);
        QuickSort(arr, low, pi - 1, CTH);
        QuickSort(arr, pi + 1, high, CTH);
    }
}

void QLNV::Sort(bool (*CTH)(int a, int b))
{
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i; // Mang index
    QuickSort(arr, 0, this->_Quantity - 1, CTH);
    NhanVien *temp = new NhanVien[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLNV + i);
    delete[] this->_QLNV;
    this->_QLNV = new NhanVien[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLNV + i) = *(temp + *(arr + i));
    delete[] temp;
    delete[] arr;
}

// Nhập dữ liệu từ file vào trong danh sách
void QLNV::ImportFromFile()
{
    ifstream FileIn("Database/NhanVien/import.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay file Import! Import khong thanh cong" << endl;
    }
    else
    {
        int count = 0;
        while (!FileIn.eof())
        {
            int id;
            string name, phonenumber, address;
            bool gender;
            double wage;
            char separator;
            int dd1, mm1, yyyy1, dd2, mm2, yyyy2;
            FileIn >> id >> separator;
            getline(FileIn, name, '|');
            FileIn >> dd1 >> separator >> mm1 >> separator >> yyyy1 >> separator;
            FileIn >> dd2 >> separator >> mm2 >> separator >> yyyy2 >> separator;
            getline(FileIn, phonenumber, '|');
            getline(FileIn, address, '|');
            FileIn >> gender >> separator;
            FileIn >> wage;
            NhanVien A(id, name, Date(dd1, mm1, yyyy1), Date(dd2, mm2, yyyy2), phonenumber, address, gender, wage);
            AddtotheEnd(A, FileIn);
            count++;
        }
        cout << "Da them thanh cong " << count << " nhan vien vao Database!" << endl;
        FileIn.close();
    }
}