#include "QLKH.h"
#include <fstream>
#include <conio.h>
QLKH::QLKH()
{
    ifstream FileIn("Database/KhachHang/KhachHang.txt", ios_base::in);
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
                this->_QLKH = nullptr;
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
            char separator;
            int dd1, mm1, yyyy1;
            FileIn >> id >> separator;
            getline(FileIn, name, '|');
            FileIn >> dd1 >> separator >> mm1 >> separator >> yyyy1 >> separator;
            getline(FileIn, phonenumber, '|');
            getline(FileIn, address, '|');
            FileIn >> gender;
            KhachHang A(id, name, Date(dd1, mm1, yyyy1), phonenumber, address, gender);
            AddtotheEnd(A, FileIn);
        }
    }
    FileIn.close();
}
QLKH::QLKH(KhachHang *QLKH, int quantity) : _QLKH(QLKH), _Quantity(quantity) {}
QLKH::QLKH(const QLKH &l)
{
    this->_QLKH = l._QLKH;
    this->_Quantity = l._Quantity;
}
QLKH::~QLKH()
{
    ofstream FileOut("Database/KhachHang/KhachHang.txt", ios_base::out);
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_QLKH + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_QLKH;
}
int QLKH::Quantity()
{
    return this->_Quantity;
}
void QLKH::Show()
{
    cout << "\t\t\t+=========================================================================================================+" << endl;
    cout << "\t\t\t|                                       ** DANH SACH KHACH HANG **                                        |" << endl;
    cout << "\t\t\t+======+==============================+============+=============+=========================+==============+" << endl;
    cout << "\t\t\t|  ID  |        Ten khach hang        | Ngay sinh  |     SDT     |         Dia chi         |  Gioi tinh   |" << endl;
    cout << "\t\t\t+======+==============================+============+=============+=========================+==============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        _QLKH[i].ShowKhachHang();
    cout << "\t\t\t+======+==============================+============+=============+=========================+==============+" << endl;
}
void QLKH::Show1KH(int id)
{
    cout << "\t\t\t+=========================================================================================================+" << endl;
    cout << "\t\t\t|                                       ** DANH SACH KHACH HANG **                                        |" << endl;
    cout << "\t\t\t+======+==============================+============+=============+=========================+==============+" << endl;
    cout << "\t\t\t|  ID  |        Ten khach hang        | Ngay sinh  |     SDT     |         Dia chi         |  Gioi tinh   |" << endl;
    cout << "\t\t\t+======+==============================+============+=============+=========================+==============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        if ((this->_QLKH + i)->ID() == id)
        {
            _QLKH[i].ShowKhachHang();
            break;
        }
    cout << "\t\t\t+======+==============================+============+=============+=========================+==============+" << endl;
}
// Them doi tuong-------------------------------------------------
//  + Them vao cuoi danh sach
//  + Them vao dau danh sach
void QLKH::AddtotheEnd(KhachHang &nv)
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
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        *(this->_QLKH + this->_Quantity) = nv;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLKH + i) = *(temp + i);
        delete[] temp;
        *(this->_QLKH + this->_Quantity) = nv;
    }
    this->_Quantity++;
}
void QLKH::AddtotheEnd(KhachHang &nv, ifstream &FileIn)
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
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        *(this->_QLKH + this->_Quantity) = nv;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLKH + i) = *(temp + i);
        delete[] temp;
        *(this->_QLKH + this->_Quantity) = nv;
    }
    this->_Quantity++;
}
void QLKH::AddtoTop(KhachHang &nv)
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
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        *(this->_QLKH + this->_Quantity) = nv;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLKH + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLKH) = nv;
    }
    this->_Quantity++;
}
void QLKH::AddtoTop(KhachHang &nv, ifstream &FileIn)
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
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        *(this->_QLKH + this->_Quantity) = nv;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLKH + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLKH) = nv;
    }
    this->_Quantity++;
}
//  + Them vao vi tri bat ky
void QLKH::AddtoPosition(KhachHang &nv, int position)
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
            this->_QLKH = new KhachHang[this->_Quantity + 1];
            *(this->_QLKH + this->_Quantity) = nv;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            KhachHang *temp = new KhachHang[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLKH + i);
            delete[] this->_QLKH;
            this->_QLKH = new KhachHang[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLKH + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLKH + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLKH + position) = nv;
            this->_Quantity++;
        }
    }
}
void QLKH::AddtoPosition(KhachHang &nv, int position, ifstream &FileIn)
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
            this->_QLKH = new KhachHang[this->_Quantity + 1];
            *(this->_QLKH + this->_Quantity) = nv;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            KhachHang *temp = new KhachHang[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLKH + i);
            delete[] this->_QLKH;
            this->_QLKH = new KhachHang[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLKH + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLKH + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLKH + position) = nv;
            this->_Quantity++;
        }
    }
}
// Cap nhat thong tin(Theo thuoc tinh MS Khach Hang(ID))-------------
// Cap nhat : Thay doi ca ID, Name, AdmissionDate, Gender, Wage
void QLKH::Update(const int &id)
{
    int index = IndexOf(id);
    if (index >= 0)
    {
        int check = 1;
        cout << "Nhap ID khach hang: ";
        while (check)
        {
            int ID;
            cin >> ID;
            int indextrave = IndexOf(ID);
            if (-1 != indextrave && indextrave != index)
            {
                cout << "Da co khach hang co ID nay!! Xin moi ban nhap lai: ";
            }
            else
            {
                (this->_QLKH + index)->ID(ID);
                check = 0;
                cin >> *(this->_QLKH + index);
            }
        }
    }
    else
        cout << "Khong co khach hang co MSKH: " << id << endl;
}
// Xoa doi tuong---------------------------------------------------------
//  + Xoa doi tuong dau tien
void QLKH::DeleteTop()
{
    int index = 0;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLKH;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLKH + i) = *(temp + i);
            }
            else
            {
                *(this->_QLKH + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa doi tuong cuoi cung
void QLKH::DeleteEnd()
{
    int index = _Quantity - 1;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLKH;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLKH + i) = *(temp + i);
            }
            else
            {
                *(this->_QLKH + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa tai vi tri k bat ky
void QLKH::DeleteatPosition(const int &position)
{
    int index = position;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLKH;
    }
    else
    {
        KhachHang *temp = new KhachHang[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLKH + i);
        delete[] this->_QLKH;
        this->_QLKH = new KhachHang[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLKH + i) = *(temp + i);
            }
            else
            {
                *(this->_QLKH + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
// Tim kiem(BinarySearch)-----------------------------------
//  + Tim Index tuong ung voi ID
int QLKH::BinarySearch(int l, int r, int id) // Vi ID chua sort nen xet ca 2 phia
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if ((this->_QLKH + mid)->ID() == id)
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
int QLKH::IndexOf(int id)
{
    return BinarySearch(0, _Quantity - 1, id);
}
// Sap xep(QuickSort) voi thuoc tinh _ID----------------
// Ham TD vÃ  GD Ä‘Æ°á»£c Ä‘á»‹nh nghÄ©a á»Ÿ duoi
int QLKH::Partition(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    int pivot = (this->_QLKH + arr[high])->ID(); // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && !CTH((this->_QLKH + arr[left])->ID(), pivot))
            left++;
        while (right >= left && CTH((this->_QLKH + arr[right])->ID(), pivot))
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
void QLKH::QuickSort(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, CTH);
        QuickSort(arr, low, pi - 1, CTH);
        QuickSort(arr, pi + 1, high, CTH);
    }
}
void QLKH::Sort(bool (*CTH)(int a, int b))
{
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i; // Mang index
    QuickSort(arr, 0, this->_Quantity - 1, CTH);
    KhachHang *temp = new KhachHang[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLKH + i);
    delete[] this->_QLKH;
    this->_QLKH = new KhachHang[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLKH + i) = *(temp + *(arr + i));
    delete[] temp;
    delete[] arr;
}
// Nháº­p dá»¯ liá»‡u tá»« file vÃ o trong danh sÃ¡ch
void QLKH::ImportFromFile()
{
    ifstream FileIn("Database/KhachHang/import.txt", ios_base::in);
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
            char separator;
            int dd1, mm1, yyyy1;
            FileIn >> id >> separator;
            getline(FileIn, name, '|');
            FileIn >> dd1 >> separator >> mm1 >> separator >> yyyy1 >> separator;
            getline(FileIn, phonenumber, '|');
            getline(FileIn, address, '|');
            FileIn >> gender;
            KhachHang A(id, name, Date(dd1, mm1, yyyy1), phonenumber, address, gender);
            AddtotheEnd(A, FileIn);
            count++;
        }
        cout << "Da them thanh cong " << count << " nhan vien vao Database!" << endl;
        FileIn.close();
    }
}