#include "QLPC.h"
#include <fstream>
#include <conio.h>
QLPC::QLPC()
{
    ifstream FileIn("Database/PhongChieu/phongchieu.txt", ios_base::in);
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
                this->_QLPC = nullptr;
                this->_Quantity = 0;
            }
        }
    }
    else
    {
        _Quantity = 0;
        while (!FileIn.eof())
        {
            int id, soluong;
            char separator;
            FileIn >> id >> separator;
            FileIn >> soluong;
            PhongChieu A(id, soluong);
            AddtotheEnd(A, FileIn);
        }
    }
    FileIn.close();
}
QLPC::QLPC(PhongChieu *QLPC, int quantity) : _QLPC(QLPC), _Quantity(quantity) {}
QLPC::QLPC(const QLPC &pc)
{
    this->_QLPC = pc._QLPC;
    this->_Quantity = pc._Quantity;
}
QLPC::~QLPC()
{
    ofstream FileOut("Database/PhongChieu/phongchieu.txt", ios_base::out);
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_QLPC + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_QLPC;
}
void QLPC::Show()
{
    cout << "\t\t\t\t\t\t+===============================+" << endl;
    cout << "\t\t\t\t\t\t|  ** DANH SACH PHONG CHIEU **  |" << endl;
    cout << "\t\t\t\t\t\t+================+==============+" << endl;
    cout << "\t\t\t\t\t\t| Ma phong chieu | So luong ghe |" << endl;
    cout << "\t\t\t\t\t\t+================+==============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        _QLPC[i].ShowPhongChieu();
    cout << "\t\t\t\t\t\t+================+==============+" << endl;
}
// Them doi tuong-------------------------------------------------
//  + Them vao cuoi danh sach
//  + Them vao dau danh sach
void QLPC::AddtotheEnd(PhongChieu &pc)
{
    if (-1 != IndexOf(pc.IDPhongChieu()))
    {
        string a = "ID ";
        string id = to_string(pc.IDPhongChieu());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        *(this->_QLPC + this->_Quantity) = pc;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLPC + i) = *(temp + i);
        delete[] temp;
        *(this->_QLPC + this->_Quantity) = pc;
    }
    this->_Quantity++;
}
void QLPC::AddtotheEnd(PhongChieu &pc, ifstream &FileIn)
{
    if (-1 != IndexOf(pc.IDPhongChieu()))
    {
        FileIn.close();
        string a = "ID ";
        string id = to_string(pc.IDPhongChieu());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        *(this->_QLPC + this->_Quantity) = pc;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLPC + i) = *(temp + i);
        delete[] temp;
        *(this->_QLPC + this->_Quantity) = pc;
    }
    this->_Quantity++;
}
void QLPC::AddtoTop(PhongChieu &pc)
{
    if (-1 != IndexOf(pc.IDPhongChieu()))
    {
        string a = "ID ";
        string id = to_string(pc.IDPhongChieu());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        *(this->_QLPC + this->_Quantity) = pc;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLPC + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLPC) = pc;
    }
    this->_Quantity++;
}
void QLPC::AddtoTop(PhongChieu &pc, ifstream &FileIn)
{
    if (-1 != IndexOf(pc.IDPhongChieu()))
    {
        FileIn.close();
        string a = "ID ";
        string id = to_string(pc.IDPhongChieu());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        *(this->_QLPC + this->_Quantity) = pc;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLPC + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLPC) = pc;
    }
    this->_Quantity++;
}
//  + Them vao vi tri bat ky
void QLPC::AddtoPosition(PhongChieu &pc, int position)
{
    if (-1 != IndexOf(pc.IDPhongChieu()))
    {
        string a = "ID ";
        string id = to_string(pc.IDPhongChieu());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLPC = new PhongChieu[this->_Quantity + 1];
            *(this->_QLPC + this->_Quantity) = pc;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            PhongChieu *temp = new PhongChieu[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLPC + i);
            delete[] this->_QLPC;
            this->_QLPC = new PhongChieu[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLPC + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLPC + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLPC + position) = pc;
            this->_Quantity++;
        }
    }
}
void QLPC::AddtoPosition(PhongChieu &pc, int position, ifstream &FileIn)
{
    if (-1 != IndexOf(pc.IDPhongChieu()))
    {
        FileIn.close();
        string a = "ID ";
        string id = to_string(pc.IDPhongChieu());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLPC = new PhongChieu[this->_Quantity + 1];
            *(this->_QLPC + this->_Quantity) = pc;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            PhongChieu *temp = new PhongChieu[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLPC + i);
            delete[] this->_QLPC;
            this->_QLPC = new PhongChieu[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLPC + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLPC + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLPC + position) = pc;
            this->_Quantity++;
        }
    }
}
// Cap nhat thong tin(Theo thuoc tinh MS Nhan vien(ID))-------------
// Cap nhat : Thay doi ca ID, Name, AdmissionDate, Gender, Wage
void QLPC::Update(const int &id)
{
    int index = IndexOf(id);
    if (index >= 0)
    {
        int check = 1;
        cout << "Nhap ID phong chieu: ";
        while (check)
        {
            int ID;
            cin >> ID;
            if (-1 != IndexOf(ID))
            {
                cout << "Da co phong chieu co ID nay!! Xin moi ban nhap lai: ";
            }
            else
            {
                (this->_QLPC + index)->IDPhongChieu(ID);
                check = 0;
                cin >> *(this->_QLPC + index);
            }
        }
    }
    else
        cout << "Khong co phong chieu co ID: " << id << endl;
}
// Xoa doi tuong---------------------------------------------------------
//  + Xoa doi tuong dau tien
void QLPC::DeleteTop()
{
    int index = 0;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLPC;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLPC + i) = *(temp + i);
            }
            else
            {
                *(this->_QLPC + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa doi tuong cuoi cung
void QLPC::DeleteEnd()
{
    int index = _Quantity - 1;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLPC;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLPC + i) = *(temp + i);
            }
            else
            {
                *(this->_QLPC + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa tai vi tri k bat ky
void QLPC::DeleteatPosition(const int &position)
{
    int index = position;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLPC;
    }
    else
    {
        PhongChieu *temp = new PhongChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLPC + i);
        delete[] this->_QLPC;
        this->_QLPC = new PhongChieu[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLPC + i) = *(temp + i);
            }
            else
            {
                *(this->_QLPC + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
// Tim kiem(BinarySearch)-----------------------------------
//  + Tim Index tuong ung voi ID
int QLPC::BinarySearch(int l, int r, int id) // Vi ID chua sort nen xet ca 2 phia
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if ((this->_QLPC + mid)->IDPhongChieu() == id)
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
int QLPC::IndexOf(int id)
{
    return BinarySearch(0, _Quantity - 1, id);
}
// Sap xep(QuickSort) voi thuoc tinh _ID----------------
// Ham TD và GD được định nghĩa ở duoi
int QLPC::Partition(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    int pivot = (this->_QLPC + arr[high])->IDPhongChieu(); // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && !CTH((this->_QLPC + arr[left])->IDPhongChieu(), pivot))
            left++;
        while (right >= left && CTH((this->_QLPC + arr[right])->IDPhongChieu(), pivot))
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
void QLPC::QuickSort(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, CTH);
        QuickSort(arr, low, pi - 1, CTH);
        QuickSort(arr, pi + 1, high, CTH);
    }
}
void QLPC::Sort(bool (*CTH)(int a, int b))
{
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i; // Mang index
    QuickSort(arr, 0, this->_Quantity - 1, CTH);
    PhongChieu *temp = new PhongChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLPC + i);
    delete[] this->_QLPC;
    this->_QLPC = new PhongChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLPC + i) = *(temp + *(arr + i));
    delete[] temp;
}
// Nhập dữ liệu từ file vào trong danh sách
void QLPC::ImportFromFile()
{
    ifstream FileIn("Database/PhongChieu/phongchieu.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay file Import! Import khong thanh cong" << endl;
    }
    else
    {
        int count = 0;
        while (!FileIn.eof())
        {
            int _IDPhongChieu;
            bool *_Ghe;
            int _SLGhe;
            int id, soluong;
            bool *ghe;
            char separator;
            FileIn >> id >> separator;
            string temp;
            getline(FileIn, temp, '|');
            FileIn >> soluong;
            ghe = new bool[soluong];
            for (int i = 0; i < soluong; i++)
            {
                *(ghe + i) = bool(temp[i] - 48);
            }
            PhongChieu A(id, soluong);
            AddtotheEnd(A, FileIn);
            count++;
        }
        cout << "Da them thanh cong " << count << " phong chieu vao Database!" << endl;
        FileIn.close();
    }
}