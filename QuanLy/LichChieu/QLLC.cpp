#include "QLLC.h"
QLLC::QLLC()
{
    ifstream FileIn("Database/LichChieu/lichchieu.txt", ios_base::in);
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
                this->_QLLC = nullptr;
                this->_Quantity = 0;
            }
        }
    }
    else
    {
        _Quantity = 0;
        while (!FileIn.eof())
        {
            int idphim, idphong, day, month, year, hour, soluongghe;
            bool *listghe;
            string temp;
            char separator;
            FileIn >> idphim >> separator;
            FileIn >> idphong >> separator;
            FileIn >> day >> separator >> month >> separator >> year >> separator;
            FileIn >> hour >> separator;
            getline(FileIn, temp, '|');
            FileIn >> soluongghe;
            for (int i = 0; i < soluongghe; i++)
            {
                *(listghe + i) = bool(temp[i] - 48);
            }
            LichChieu A(idphim, idphong, Ca(day, month, year, hour), listghe, soluongghe);
            AddtotheEnd(A, FileIn);
        }
    }
    FileIn.close();
}
QLLC::QLLC(LichChieu *QLLC, int Quantity) : _QLLC(QLLC), _Quantity(Quantity) {}
QLLC::QLLC(const QLLC &lc)
{
    this->_QLLC = lc._QLLC;
    this->_Quantity = lc._Quantity;
}
QLLC::~QLLC()
{
    ofstream FileOut("Database/LichChieu/lichchieu.txt", ios_base::out);
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_QLLC + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_QLLC;
}
void QLLC::Show()
{
    QLP temp;
    cout << "\t+====================================================================================================+" << endl;
    cout << "\t|                                       ** DANH SACH LICH CHIEU **                                   |" << endl;
    cout << "\t+================+===================================================================================+" << endl;
    cout << "\t|               Ten phim                | Ma phong | Ngay chieu | Thoi gian | So luong ghe con trong |" << endl;
    cout << "\t+================+===================================================================================+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
    {
        cout << "| ";
        temp.ShowTenPhim(_QLLC[i].IDPhim());
        cout << " |";
        _QLLC[i].ShowLichChieu();
    }
    cout << "\t+================+===================================================================================+" << endl;
}
void QLLC::XemlaidanhsachPhim()
{
    QLP temp;
    temp.Show();
}
void QLLC::XemlaidanhsachPhongChieu()
{
    QLPC temp;
    temp.Show();
}
void QLLC::AddtotheEnd(LichChieu &lc)
{
    int check;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                check = 0;
                break;
            }
            else
            {
                check = 1;
            }
        }
    }
    if (check == 0)
    {
        string a = "IDPhong ";
        string id = to_string(lc.IDPhong());
        string b = " va suat chieu ";
        string day = to_string(lc.ThoiGian().Day());
        string month = to_string(lc.ThoiGian().Month());
        string year = to_string(lc.ThoiGian().Year());
        string hour = to_string(lc.ThoiGian().Hour());
        string bug = a + id + b + day + "/" + month + "/" + year + ":" + hour + "h da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        *(this->_QLLC + this->_Quantity) = lc;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLLC + i) = *(temp + i);
        delete[] temp;
        *(this->_QLLC + this->_Quantity) = lc;
    }
    this->_Quantity++;
}
void QLLC::AddtotheEnd(LichChieu &lc, ifstream &FileIn)
{
    int check;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                check = 0;
                break;
            }
            else
            {
                check = 1;
            }
        }
    }
    if (check == 0)
    {
        FileIn.close();
        string a = "IDPhong ";
        string id = to_string(lc.IDPhong());
        string b = " va suat chieu ";
        string day = to_string(lc.ThoiGian().Day());
        string month = to_string(lc.ThoiGian().Month());
        string year = to_string(lc.ThoiGian().Year());
        string hour = to_string(lc.ThoiGian().Hour());
        string bug = a + id + b + day + "/" + month + "/" + year + ":" + hour + "h da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        *(this->_QLLC + this->_Quantity) = lc;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_QLLC + i) = *(temp + i);
        delete[] temp;
        *(this->_QLLC + this->_Quantity) = lc;
    }
    this->_Quantity++;
}
void QLLC::AddtoTop(LichChieu &lc)
{
    int check;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                check = 0;
                break;
            }
            else
            {
                check = 1;
            }
        }
    }
    if (check == 0)
    {
        string a = "IDPhong ";
        string id = to_string(lc.IDPhong());
        string b = " va suat chieu ";
        string day = to_string(lc.ThoiGian().Day());
        string month = to_string(lc.ThoiGian().Month());
        string year = to_string(lc.ThoiGian().Year());
        string hour = to_string(lc.ThoiGian().Hour());
        string bug = a + id + b + day + "/" + month + "/" + year + ":" + hour + "h da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        *(this->_QLLC + this->_Quantity) = lc;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLLC + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLLC) = lc;
    }
    this->_Quantity++;
}
void QLLC::AddtoTop(LichChieu &lc, ifstream &FileIn)
{
    int check;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                check = 0;
                break;
            }
            else
            {
                check = 1;
            }
        }
    }
    if (check == 0)
    {
        FileIn.close();
        string a = "IDPhong ";
        string id = to_string(lc.IDPhong());
        string b = " va suat chieu ";
        string day = to_string(lc.ThoiGian().Day());
        string month = to_string(lc.ThoiGian().Month());
        string year = to_string(lc.ThoiGian().Year());
        string hour = to_string(lc.ThoiGian().Hour());
        string bug = a + id + b + day + "/" + month + "/" + year + ":" + hour + "h da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        *(this->_QLLC + this->_Quantity) = lc;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity + 1];
        for (int i = 1; i <= this->_Quantity; i++)
            *(this->_QLLC + i) = *(temp + i - 1);
        delete[] temp;
        *(this->_QLLC) = lc;
    }
    this->_Quantity++;
}
//  + Them vao vi tri bat ky
void QLLC::AddtoPosition(LichChieu &lc, int position)
{
    int check;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                check = 0;
                break;
            }
            else
            {
                check = 1;
            }
        }
    }
    if (check == 0)
    {
        string a = "IDPhong ";
        string id = to_string(lc.IDPhong());
        string b = " va suat chieu ";
        string day = to_string(lc.ThoiGian().Day());
        string month = to_string(lc.ThoiGian().Month());
        string year = to_string(lc.ThoiGian().Year());
        string hour = to_string(lc.ThoiGian().Hour());
        string bug = a + id + b + day + "/" + month + "/" + year + ":" + hour + "h da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLLC = new LichChieu[this->_Quantity + 1];
            *(this->_QLLC + this->_Quantity) = lc;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            LichChieu *temp = new LichChieu[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLLC + i);
            delete[] this->_QLLC;
            this->_QLLC = new LichChieu[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLLC + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLLC + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLLC + position) = lc;
            this->_Quantity++;
        }
    }
}
void QLLC::AddtoPosition(LichChieu &lc, int position, ifstream &FileIn)
{
    int check;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                check = 0;
                break;
            }
            else
            {
                check = 1;
            }
        }
    }
    if (check == 0)
    {
        FileIn.close();
        string a = "IDPhong ";
        string id = to_string(lc.IDPhong());
        string b = " va suat chieu ";
        string day = to_string(lc.ThoiGian().Day());
        string month = to_string(lc.ThoiGian().Month());
        string year = to_string(lc.ThoiGian().Year());
        string hour = to_string(lc.ThoiGian().Hour());
        string bug = a + id + b + day + "/" + month + "/" + year + ":" + hour + "h da bi trung trong Database! Hay xem lai Database hoac du lieu dau vao";
        throw bug;
    }
    if (this->_Quantity == 0)
    {
        if (position > 0 || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            this->_QLLC = new LichChieu[this->_Quantity + 1];
            *(this->_QLLC + this->_Quantity) = lc;
            this->_Quantity++;
        }
    }
    else
    {
        if (position > _Quantity || position < 0)
            cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
        else
        {
            LichChieu *temp = new LichChieu[this->_Quantity];
            for (int i = 0; i < this->_Quantity; i++)
                *(temp + i) = *(this->_QLLC + i);
            delete[] this->_QLLC;
            this->_QLLC = new LichChieu[this->_Quantity + 1];
            for (int i = 0; i < position; i++)
                *(this->_QLLC + i) = *(temp + i);
            for (int i = position + 1; i <= this->_Quantity; i++)
                *(this->_QLLC + i) = *(temp + i - 1);
            delete[] temp;
            *(this->_QLLC + position) = lc;
            this->_Quantity++;
        }
    }
}
// Cap nhat thong tin(Theo thuoc tinh MS Nhan vien(ID))-------------
// Cap nhat : Thay doi ca ID, Name, AdmissionDate, Gender, Wage
void QLLC::Update(const int &idphong, const int &day, const int &month, const int &year, const int &hour)
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
                (this->_QLLC + index)->IDLichChieu(ID);
                check = 0;
                cin >> *(this->_QLLC + index);
            }
        }
    }
    else
        cout << "Khong co phong chieu co ID: " << id << endl;
}
// Xoa doi tuong---------------------------------------------------------
//  + Xoa doi tuong dau tien
void QLLC::DeleteTop()
{
    int index = 0;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLLC;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLLC + i) = *(temp + i);
            }
            else
            {
                *(this->_QLLC + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa doi tuong cuoi cung
void QLLC::DeleteEnd()
{
    int index = _Quantity - 1;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLLC;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLLC + i) = *(temp + i);
            }
            else
            {
                *(this->_QLLC + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
//  + Xoa tai vi tri k bat ky
void QLLC::DeleteatPosition(const int &position)
{
    int index = position;
    if (this->_Quantity == 1)
    {
        delete[] this->_QLLC;
    }
    else
    {
        LichChieu *temp = new LichChieu[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_QLLC + i);
        delete[] this->_QLLC;
        this->_QLLC = new LichChieu[this->_Quantity - 1];
        for (int i = 0; i < this->_Quantity - 1; i++)
        {
            if (i < index)
            {
                *(this->_QLLC + i) = *(temp + i);
            }
            else
            {
                *(this->_QLLC + i) = *(temp + i + 1);
            }
        }
    }
    this->_Quantity--;
}
int QLLC::FindIndexPhong(int id, int cur)
{
    int index = -1;
    for (int i = cur; i < _Quantity; i++)
    {
        if ((this->_QLLC + i)->IDPhong() == id)
            index = i;
    }
    return index;
}
// Sap xep(QuickSort) voi thuoc tinh _ID----------------
// Ham TD và GD được định nghĩa ở duoi
int QLLC::Partition(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    int pivot = (this->_QLLC + arr[high])->IDLichChieu(); // pivot
    int left = low;
    int right = high - 1;
    while (true)
    {
        while (left <= right && !CTH((this->_QLLC + arr[left])->IDLichChieu(), pivot))
            left++;
        while (right >= left && CTH((this->_QLLC + arr[right])->IDLichChieu(), pivot))
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
void QLLC::QuickSort(int *arr, int low, int high, bool (*CTH)(int a, int b))
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, CTH);
        QuickSort(arr, low, pi - 1, CTH);
        QuickSort(arr, pi + 1, high, CTH);
    }
}
void QLLC::Sort(bool (*CTH)(int a, int b))
{
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i; // Mang index
    QuickSort(arr, 0, this->_Quantity - 1, CTH);
    LichChieu *temp = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLLC + i);
    delete[] this->_QLLC;
    this->_QLLC = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLLC + i) = *(temp + *(arr + i));
    delete[] temp;
}
void QLLC::ImportFromFile()
{
    ifstream FileIn("Database/LichChieu/lichchieu.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay file Import! Import khong thanh cong" << endl;
    }
    else
    {
        int count = 0;
        while (!FileIn.eof())
        {
            int idphim, idphong, day, month, year, hour, soluongghe;
            bool *listghe;
            string temp;
            char separator;
            FileIn >> idphim >> separator;
            FileIn >> idphong >> separator;
            FileIn >> day >> separator >> month >> separator >> year >> separator;
            FileIn >> hour >> separator;
            getline(FileIn, temp, '|');
            FileIn >> soluongghe;
            for (int i = 0; i < soluongghe; i++)
            {
                *(listghe + i) = bool(temp[i] - 48);
            }
            LichChieu A(idphim, idphong, Ca(day, month, year, hour), listghe, soluongghe);
            AddtotheEnd(A, FileIn);
            count++;
        }
        cout << "Da them thanh cong " << count << " lich chieu vao Database!" << endl;
        FileIn.close();
    }
}