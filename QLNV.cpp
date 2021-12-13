#include "QLNV.h"
bool GD(int a, int b)
{
    return a < b;
}
bool TD(int a, int b)
{
    return a > b;
}
class QLNV
{
    NhanVien *_QLNV;
    int _Quantity;

public:
    QLNV()
    {
        this->_QLNV = nullptr;
        this->_Quantity = 0;
    }
    QLNV(NhanVien *QLNV, int quantity) : _QLNV(QLNV), _Quantity(quantity) {}
    QLNV(const QLNV &l)
    {
        this->_QLNV = l._QLNV;
        this->_Quantity = l._Quantity;
    }
    ~QLNV()
    {
        delete[] this->_QLNV;
    }
    void Show()
    {
        cout << "Danh Sach Nhan Vien:" << endl;
        for (int i = 0; i < this->_Quantity; i++)
            _QLNV[i].ShowNV();
    }
    // Them doi tuong-------------------------------------------------
    //  + Them vao cuoi danh sach
    void AddtotheEnd(const NhanVien &nv)
    {
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
    void AddtoTop(const NhanVien &nv)
    {
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
    void AddtoPosition(const NhanVien &nv, int position)
    {
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
    void Update(const int &id)
    {
        int index = IndexOf(id);
        if (index >= 0)
        {
            int ID;
            string Name;
            Date AdmissionDate;
            int dd, mm, yy;
            string Gender;
            double Wage;

            cout << "MSNV: ";
            cin >> ID;
            (this->_QLNV + index)->ID(ID);

            cout << "Name : ";
            cin >> Name;
            (this->_QLNV + index)->Name(Name);

            cout << "Ngay Nhan Vao: "; // Nhập theo kiểu dd/mm/yyyy separator có thể tuỳ chỉnh
            char separator;
            cin >> dd >> separator >> mm >> separator >> yy;
            AdmissionDate = Date(dd, mm, yy);
            (this->_QLNV + index)->AdmissionDate(AdmissionDate);

            cout << "Gioi tinh: "; // Có thể nhập "Nam","nu" đều được hoặc nhập 01
            cin >> Gender;
            if (Gender == "nam" || Gender == "Nam" || Gender == "0")
                (this->_QLNV + index)->Gender(0);
            else if (Gender == "Nu" || Gender == "nu" || Gender == "1")
                (this->_QLNV + index)->Gender(1);

            cout << "Luong: ";
            cin >> Wage;
            (this->_QLNV + index)->Wage(Wage);
        }
        else
            cout << "Khong co nhan vien co MSNV: " << id << endl;
    }
    // Xoa doi tuong---------------------------------------------------------
    //  + Xoa doi tuong dau tien
    void DeleteTop()
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
    void DeleteEnd()
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
    void DeleteatPosition(const int &position)
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
    // int BinarySearch(int l, int r, int id) // Vi ID chua sort nen xet ca 2 phia
    // {
    //     if (r >= l)
    //     {
    //         int mid = l + (r - l) / 2;
    //         if ((this->_QLNV + mid)->ID() == id)
    //             return mid;
    //         int A = BinarySearch(l, mid - 1, id);
    //         int B = BinarySearch(mid + 1, r, id);
    //         if (A != -1)
    //             return A;
    //         else if (B != -1)
    //             return B;
    //         else
    //             return -1;
    //     }
    //     return -1;
    // }
    // int IndexOf(int id)
    // {
    //     return BinarySearch(0, _Quantity - 1, id);
    // }
    // Sap xep(InsertionSort) voi thuoc tinh _ID----------------
    // Ham TD và GD đã được định nghĩa ở phía bên trên cùng
    //     void Sort(bool (*CTH)(int a, int b) = TD)
    //     {
    //         int *tempIndex = new int[_Quantity];
    //         for (int i = 0; i < _Quantity; i++)
    //             *(tempIndex + i) = i; // Mang index
    //         int i, j;
    //         for (i = 1; i < _Quantity; i++)
    //         {
    //             j = i - 1;
    //             while (j >= 0 && CTH((this->_QLNV + j)->ID(), (this->_QLNV + i)->ID()))
    //             {
    //                 tempIndex[j + 1] = tempIndex[j];
    //                 j--;
    //             }
    //             tempIndex[j + 1] = i;
    //         }
    //         NhanVien *temp = new NhanVien[this->_Quantity];
    //         for (int i = 0; i < this->_Quantity; i++)
    //             *(temp + i) = *(this->_QLNV + i);
    //         for (int i = 0; i < this->_Quantity; i++)
    //             *(this->_QLNV + i) = *(temp + *(tempIndex + i));
    //         delete[] temp;
    //     }
};