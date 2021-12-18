#include "QLP.h"
#include <fstream>
#include <conio.h>
#include <iomanip>
QLP::QLP()
{
    ifstream FileIn("Database/Phim/phim.txt", ios_base::in);
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
                this->_QLP = nullptr;
                this->_Quantity = 0;
            }
        }
    }
    else
    {
        _Quantity = 0;
        while (!FileIn.eof())
        {
            int id, duration;
            string name, mainactor, category;
            char separator;
            FileIn >> id >> separator;
            getline(FileIn, name, '|');
            getline(FileIn, mainactor, '|');
            getline(FileIn, category, '|');
            FileIn >> duration;
            Film A(id, name, mainactor, category, duration);
            AddtotheEnd(A, FileIn);
        }
    }
    FileIn.close();
}
QLP::QLP(Film *QLP, int quantity) : _QLP(QLP), _Quantity(quantity) {}
QLP::QLP(const QLP &l)
{
    this->_QLP = l._QLP;
    this->_Quantity = l._Quantity;
}
QLP::~QLP()
{
    ofstream FileOut("Database/Phim/phim.txt", ios_base::out);
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_QLP + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_QLP;
}
int QLP::TongSoLuongPhim()
{
    return this->_Quantity;
}
void QLP::Show()
{
    cout << "\t\t+==========================================================================================================================+" << endl;
    cout << "\t\t|                                                 ** DANH SACH PHIM **                                                     |" << endl;
    cout << "\t\t+=========+=========================================+========================================+================+============+" << endl;
    cout << "\t\t| Ma phim |                Ten phim                 |             Dien vien chinh            |    The loai    | Thoi luong |" << endl;
    cout << "\t\t+=========+=========================================+========================================+================+============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
        _QLP[i].ShowPhim();
    cout << "\t\t+=========+=========================================+========================================+================+============+" << endl;
}
void QLP::Show1Film(int id)
{
    cout << "\t\t+==========================================================================================================================+" << endl;
    cout << "\t\t|                                                 ** DANH SACH PHIM **                                                     |" << endl;
    cout << "\t\t+=========+=========================================+========================================+================+============+" << endl;
    cout << "\t\t| Ma phim |                Ten phim                 |             Dien vien chinh            |    The loai    | Thoi luong |" << endl;
    cout << "\t\t+=========+=========================================+========================================+================+============+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
    {
        if ((this->_QLP + i)->IDFilm() == id)
        {
            _QLP[i].ShowPhim();
            break;
        }
    }
    cout << "\t\t+=========+=========================================+========================================+================+============+" << endl;
}
void QLP::ShowTenPhim(int id)
{
    int Index = IndexOf(id);
    if (Index == -1)
    {
        cout << setw(38) << left << "IDPhim khong ton tai";
    }
    else if (Index > -1)
    {
        cout << setw(38) << left << _QLP[Index].FilmName();
    }
}

// Them doi tuong-------------------------------------------------
//  + Them vao cuoi danh sach
//  + Them vao dau danh sach
int QLP::AddtotheEnd(Film &p)
{
    if (-1 != IndexOf(p.IDFilm()))
    {
        return 0;
    }
    if (this->_Quantity == 0)
    {
        this->_QLP = new Film[this->_Quantity + 1];
        *(this->_QLP + this->_Quantity) = p;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLP + i) = *(temp + i);
        delete[] temp;
        *(this->_QLP + this->_Quantity) = p;
    }
    this->_Quantity++;
    return 1;
}
void QLP::AddtotheEnd(Film &p, ifstream &FileIn)
{
    if (-1 != IndexOf(p.IDFilm()))
    {
        FileIn.close();
        string a = "ID ";
        string id = to_string(p.IDFilm());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLP = new Film[this->_Quantity + 1];
        *(this->_QLP + this->_Quantity) = p;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLP + i) = *(temp + i);
        delete[] temp;
        *(this->_QLP + this->_Quantity) = p;
    }
    this->_Quantity++;
}
void QLP::AddtoTop(Film &p)
{
    if (-1 != IndexOf(p.IDFilm()))
    {
        string a = "ID ";
        string id = to_string(p.IDFilm());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLP = new Film[this->_Quantity + 1];
        *(this->_QLP + this->_Quantity) = p;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLP + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLP) = p;
    }
    this->_Quantity++;
}
void QLP::AddtoTop(Film &p, ifstream &FileIn)
{
    if (-1 != IndexOf(p.IDFilm()))
    {
        FileIn.close();
        string a = "ID ";
        string id = to_string(p.IDFilm());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLP = new Film[this->_Quantity + 1];
        *(this->_QLP + this->_Quantity) = p;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLP + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLP) = p;
    }
    this->_Quantity++;
}
//  + Them vao vi tri bat ky
void QLP::AddtoPosition(Film &p, int position)
{
    if (-1 != IndexOf(p.IDFilm()))
    {
        string a = "ID ";
        string id = to_string(p.IDFilm());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLP = new Film[this->_Quantity + 1];
            *(this->_QLP + this->_Quantity) = p;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            Film *temp = new Film[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLP + i);
            delete[] this->_QLP;
            this->_QLP = new Film[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLP + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLP + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLP + position) = p;
            this->_Quantity++;
        }
    }
}
void QLP::AddtoPosition(Film &p, int position, ifstream &FileIn)
{
    if (-1 != IndexOf(p.IDFilm()))
    {
        FileIn.close();
        string a = "ID ";
        string id = to_string(p.IDFilm());
        string bug = a + id + " da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLP = new Film[this->_Quantity + 1];
            *(this->_QLP + this->_Quantity) = p;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            Film *temp = new Film[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLP + i);
            delete[] this->_QLP;
            this->_QLP = new Film[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLP + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLP + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLP + position) = p;
            this->_Quantity++;
        }
    }
}
// Cap nhat thong tin(Theo thuoc tinh MS Nhan vien(ID))-------------
// Cap nhat : Thay doi ca ID, Name, AdmissionDate, Gender, Wage
void QLP::Update(const int &id)
{
    int index = IndexOf(id);
    if (index >= 0)
    {
        int check = 1;
        cout << "\t\t\t\t\t\tNhap ID moi cho phim: ";
        while (check)
        {
            int ID;
            cin >> ID;
            int indextrave = IndexOf(ID);
            if (-1 != indextrave && indextrave != index)
            {
                cout << "\t\t\t\t\t\tDa co phim co ID nay!! Xin moi ban nhap lai: ";
            }
            else
            {
                (this->_QLP + index)->IDFilm(ID);
                check = 0;
                cin >> *(this->_QLP + index);
            }
        }
    }
    else
        cout << "\t\t\t\t\t\tKhong co phim co ID: " << id << endl;
}
// Xoa doi tuong---------------------------------------------------------
//  + Xoa doi tuong dau tien
void QLP::DeleteTop()
{
    int index = 0;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLP;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLP + i) = *(temp + i);
            }
            else
            {
                *(this->_QLP + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa doi tuong cuoi cung
void QLP::DeleteEnd()
{
    int index = _Quantity - 1;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLP;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLP + i) = *(temp + i);
            }
            else
            {
                *(this->_QLP + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa tai vi tri k bat ky
void QLP::DeleteatPosition(const int &position)
{
    int index = position;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLP;
    }
    else
    {
        Film *temp = new Film[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLP + i);
        delete[] this->_QLP;
        this->_QLP = new Film[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLP + i) = *(temp + i);
            }
            else
            {
                *(this->_QLP + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
// Tim kiem(BinarySearch)-----------------------------------
//  + Tim Index tuong ung voi ID
int QLP::BinarySearch(int l, int r, int id) // Vi ID chua sort nen xet ca 2 phia
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        if ((this->_QLP + mid)->IDFilm() == id)
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
int QLP::IndexOf(int id)
{
    return BinarySearch(0, _Quantity - 1, id);
}
// Sap xep(QuickSort) voi thuoc tinh _ID----------------
<<<<<<< HEAD
// Ham TD và GD được định nghĩa ở duoi
=======
// Ham TD vÃ  GD Ä‘Æ°á»£c Ä‘á»‹nh nghÄ©a á»Ÿ duoi
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
int QLP::Partition(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    int pivot = (this->_QLP + arr[high])->IDFilm(); // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && !CTH((this->_QLP + arr[left])->IDFilm(), pivot))
            left++;
        while (right >= left && CTH((this->_QLP + arr[right])->IDFilm(), pivot))
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
void QLP::QuickSort(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, CTH);
        QuickSort(arr, low, pi - 1, CTH);
        QuickSort(arr, pi + 1, high, CTH);
    }
}
void QLP::Sort(bool (*CTH)(int a, int b))
{
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i; // Mang index
    QuickSort(arr, 0, this->_Quantity - 1, CTH);
    Film *temp = new Film[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLP + i);
    delete[] this->_QLP;
    this->_QLP = new Film[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLP + i) = *(temp + *(arr + i));
    delete[] temp;
    delete[] arr;
}
<<<<<<< HEAD
// Nhập dữ liệu từ file vào trong danh sách
=======
// Nháº­p dá»¯ liá»‡u tá»« file vÃ o trong danh sÃ¡ch
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
void QLP::ImportFromFile()
{
    ifstream FileIn("Database/Phim/import.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay file Import! Import khong thanh cong" << endl;
    }
    else
    {
        int count = 0;
        while (!FileIn.eof())
        {
            int id, duration;
            string name, mainactor, category;
            char separator;
            FileIn >> id >> separator;
            std::getline(FileIn, name, '|');
            std::getline(FileIn, mainactor, '|');
            std::getline(FileIn, category, '|');
            FileIn >> duration;
            Film A(id, name, mainactor, category, duration);
            AddtotheEnd(A, FileIn);
            count++;
        }
        cout << "Da them thanh cong " << count << " phim vao Database!" << endl;
        FileIn.close();
    }
}