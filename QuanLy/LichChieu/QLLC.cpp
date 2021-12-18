#pragma once
#include "QLLC.h"
#include <iostream>
using namespace std;
void TextColor(int);
void InTienVe(int);
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
            int idphim, idphong, day, month, year, hour, soluonggheconlai, soluongghebandau, giave;
            char separator;
            FileIn >> idphim >> separator;
            FileIn >> idphong >> separator;
            FileIn >> day >> separator >> month >> separator >> year >> separator;
            FileIn >> hour >> separator;
            FileIn >> soluonggheconlai >> separator;
            FileIn >> soluongghebandau >> separator;
            FileIn >> giave;
            LichChieu A(idphim, idphong, Ca(day, month, year, hour), soluonggheconlai, soluongghebandau, giave);
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
    cout << "\t\t+=============================================================================================================+" << endl;
    cout << "\t\t|                                           ** DANH SACH LICH CHIEU **                                        |" << endl;
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
    cout << "\t\t|               Ten phim                | Ma phong | Ngay chieu | Thoi gian | So luong ghe con trong | Gia ve |" << endl;
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
    {
        cout << "\t\t| ";
        temp.ShowTenPhim(_QLLC[i].IDPhim());
        _QLLC[i].ShowLichChieu();
        cout << endl;
    }
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
}
void QLLC::XemLichChieuTheoNgay(Date &d)
{
    QLP temp;
    cout << "\t\t+=============================================================================================================+" << endl;
    cout << "\t\t|                                           ** DANH SACH LICH CHIEU **                                        |" << endl;
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
    cout << "\t\t|               Ten phim                | Ma phong | Ngay chieu | Thoi gian | So luong ghe con trong | Gia ve |" << endl;
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
    {
        if (_QLLC[i].DateCompare(d))
        {
            cout << "\t\t| ";
            temp.ShowTenPhim(_QLLC[i].IDPhim());
            _QLLC[i].ShowLichChieu();
            cout << endl;
        }
    }
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
}
void QLLC::XemLichChieuTheoPhim(int &idp)
{
    QLP temp;
    cout << "\t\t+=============================================================================================================+" << endl;
    cout << "\t\t|                                           ** DANH SACH LICH CHIEU **                                        |" << endl;
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
    cout << "\t\t|               Ten phim                | Ma phong | Ngay chieu | Thoi gian | So luong ghe con trong | Gia ve |" << endl;
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
    for (int i = 0; i < this->_Quantity; i++)
    {
        if (_QLLC[i].IDPhimCompare(idp))
        {
            cout << "\t\t| ";
            temp.ShowTenPhim(_QLLC[i].IDPhim());
            _QLLC[i].ShowLichChieu();
            cout << endl;
        }
    }
    cout << "\t\t+=======================================+==========+============+===========+========================+========+" << endl;
}
int QLLC::DatMuaVe(const Ca &ca, int maphong, int soluong)
{
    int check = 1, index;
    for (int i = 0; i < _Quantity; i++)
    {
        index = FindIndexPhong(maphong, i);
        if (index != -1)
        {
            if ((this->_QLLC + index)->ThoiGian() == ca)
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
    if (check == 1)
    {
        cout << "\t\t\t\t\t\tBan da nhap sai thong tin! Hay thu lai." << endl;
    }
    else if (check == 0)
    {
        int gheconlaibd = (this->_QLLC + index)->GheConLai();
        if (gheconlaibd < soluong)
        {
            TextColor(12);
            cout << "\t\t\t\t\t\tSo luong ve con lai cua suat chieu khong du cho nhu cau cua ban! Hay thu lai" << endl;
            TextColor(14);
            return -1;
        }
        else
        {
            (this->_QLLC + index)->GheConLai(gheconlaibd - soluong);
            cout << "\t\t\t\t\t\tBan da mua ve thanh cong!" << endl;
            int Bill = soluong * (this->_QLLC + index)->GiaVe();
            cout << "\t\t\t\t\t\tSo tien ban phai tra la: ";
            cout << setw(10) << right;
            InTienVe(Bill);
            cout << " VND" << endl
                 << "\t\t\t\t\t\tBill da duoc luu vao lich su mua hang cua ban! Chan thanh cam on!" << endl;
            return Bill;
        }
    }
    return -1;
}
void QLLC::TongDoanhThu_Toanbo()
{
    int tongsovedaban = 0, tongsotienthuduoc = 0, giave, sove;
    for (int i = 0; i < _Quantity; i++)
    {
        sove = (this->_QLLC + i)->SLGhe() - (this->_QLLC + i)->GheConLai();
        tongsovedaban += sove;
        giave = (this->_QLLC + i)->GiaVe();
        tongsotienthuduoc += giave * sove;
    }
    cout << "\t\t\t\t\t\t+===========================================+" << endl;
    cout << "\t\t\t\t\t\t|              ** DOANH THU **              |" << endl;
    cout << "\t\t\t\t\t\t+=======================+===================+" << endl;
    cout << "\t\t\t\t\t\t| Tong so ve da ban :   | " << setw(11) << right << tongsovedaban << " (ve)  |" << endl;
    cout << "\t\t\t\t\t\t+=======================+===================+" << endl;
    cout << "\t\t\t\t\t\t| Tong so tien thu ve : | ";
    cout << setw(11) << right;
    InTienVe(tongsotienthuduoc);
    cout << " (VND) |" << endl;
    cout << "\t\t\t\t\t\t+=======================+===================+" << endl;
}
void QLLC::ThongKePhimAnKhach()
{
    // sort theo ten phim
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i;
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->IDPhim() > (this->_QLLC + arr[j + 1])->IDPhim())
                swap(arr[j], arr[j + 1]);
        }
    }
    LichChieu *temp = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLLC + i);
    delete[] this->_QLLC;
    this->_QLLC = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLLC + i) = *(temp + *(arr + i));
    delete[] temp;
    delete[] arr;
    // bat dau thong ke
    int sove = 0, doanhthu = 0, z = 0;
    QLP tempQLP;
    int n = tempQLP.TongSoLuongPhim();
    int **array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        *(array + i) = new int[3];
    }
    for (int i = 0; i < _Quantity; i++)
    {
        int a = (this->_QLLC + i)->SLGhe() - (this->_QLLC + i)->GheConLai();
        sove += a;
        doanhthu += a * (this->_QLLC + i)->GiaVe();
        if (i == _Quantity - 1)
        {
            array[z][0] = (this->_QLLC + i)->IDPhim();
            array[z][1] = sove;
            array[z][2] = doanhthu;
            sove = 0, doanhthu = 0;
            z++;
        }
        else if ((this->_QLLC + i)->IDPhim() != (this->_QLLC + i + 1)->IDPhim())
        {
            array[z][0] = (this->_QLLC + i)->IDPhim();
            array[z][1] = sove;
            array[z][2] = doanhthu;
            sove = 0, doanhthu = 0;
            z++;
        }
    }
    arr = new int[n];
    for (int i = 0; i < n; i++)
        *(arr + i) = i;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[arr[j]][2] < array[arr[j + 1]][2])
                swap(arr[j], arr[j + 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "\t\t\t\t\t| ";
        tempQLP.ShowTenPhim(array[arr[i]][0]);
        cout << "|      " << setw(4) << left << array[arr[i]][1] << "    | ";
        cout << setw(13) << right;
        InTienVe(array[arr[i]][2]);
        cout << " |" << endl;
    }
    delete[] arr;
    for (int i = 0; i < n; i++)
    {
        delete[] * (array + i);
    }
    delete[] array;
}
void QLLC::ThongKeKhungGio()
{
    // sort theo ten phim
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i;
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->ThoiGian().Hour() > (this->_QLLC + arr[j + 1])->ThoiGian().Hour())
                swap(arr[j], arr[j + 1]);
        }
    }
    LichChieu *temp = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLLC + i);
    delete[] this->_QLLC;
    this->_QLLC = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLLC + i) = *(temp + *(arr + i));
    delete[] temp;
    delete[] arr;
    // Sau khi da sap xep xong
    int sove = 0, doanhthu = 0, soluong = 0;
    for (int i = 0; i < _Quantity; i++)
    {
        soluong++;
        int a = (this->_QLLC + i)->SLGhe() - (this->_QLLC + i)->GheConLai();
        sove += a;
        doanhthu += a * (this->_QLLC + i)->GiaVe();
        if (i == _Quantity - 1)
        {
            cout << "\t\t\t|    ";
            ((this->_QLLC + i)->ThoiGian()).ShowCa();
            cout << "   |      " << setw(3) << left << sove << "     | ";
            cout << setw(14) << left;
            InTienVe(doanhthu);
            cout << "|       " << setw(4) << left << soluong;
            cout << "    |         " << setw(10) << left << double(sove) / double(soluong) << "   | ";
            cout << setw(14) << left;
            InTienVe(doanhthu / soluong);
            cout << "       |" << endl;
            sove = 0, doanhthu = 0, soluong = 0;
        }
        else if (!((this->_QLLC + i)->ThoiGian().Hour() == (this->_QLLC + i + 1)->ThoiGian().Hour()))
        {
            cout << "\t\t\t|    ";
            ((this->_QLLC + i)->ThoiGian()).ShowCa();
            cout << "   |      " << setw(3) << left << sove << "     | ";
            cout << setw(14) << left;
            InTienVe(doanhthu);
            cout << "|       " << setw(4) << left << soluong;
            cout << "    |         " << setw(10) << left << double(sove) / double(soluong) << "   | ";
            cout << setw(14) << left;
            InTienVe(doanhthu / soluong);
            cout << "       |" << endl;
            sove = 0, doanhthu = 0, soluong = 0;
        }
    }
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
int QLLC::AddtotheEnd(LichChieu &lc)
{
    int check = 1;
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
        return 0;
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
    return 1;
}
void QLLC::AddtotheEnd(LichChieu &lc, ifstream &FileIn)
{
    int check = 1;
    for (int i = 0; i < _Quantity; i++)
    {
        int IndexPhongChieu = FindIndexPhong(lc.IDPhong(), i);
        if (IndexPhongChieu != -1)
        {
            if ((this->_QLLC + IndexPhongChieu)->ThoiGian() == lc.ThoiGian())
            {
                (this->_QLLC + IndexPhongChieu)->ThoiGian().ShowCa();
                lc.ThoiGian().ShowCa();
                cout << endl
                     << IndexPhongChieu << endl;
                cout << "true" << endl;
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
    int check = 1;
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
    int check = 1;
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
    int check = 1;
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
    int check = 1;
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
void QLLC::Update(int index)
{
    int idphong;
    QLPC tempQLPC;
    Ca tempCa;
    while (1)
    {
        cout << "\t\t\t\t\t\tNhap ID phong chieu moi: ";
        while (1)
        {
            cin >> idphong;
            if (-1 != tempQLPC.IndexOf(idphong))
            {
                break;
            }
            else
                cout << "\t\t\t\t\t\tID phong khong ton tai trong danh sach phong! Moi ban nhap lai: ";
        }
        cin >> tempCa;
        int indextemp = FindIndex(idphong, tempCa);
        if (-1 == indextemp)
        {
            break;
        }
        else if (index == indextemp)
        {
            break;
        }
        else
            cout << "\t\t\t\t\t\tID phong va ca da ton tai trong Database! Xin hay nhap lai." << endl;
    }
    cout << "\t\t\t\t\t\tNhap ID phim cho lich chieu nay: ";
    QLP tempQLP;
    int idphim;
    while (1)
    {
        cin >> idphim;
        if (-1 == tempQLP.IndexOf(idphim))
        {
            cout << "\t\t\t\t\t\tID phim khong ton tai trong danh sach phim! Moi ban nhap lai: ";
        }
        else
            break;
    }
    int slghe, giave;
    cout << "\t\t\t\t\t\tNhap so luong ghe: ";
    cin >> slghe;
    cout << "\t\t\t\t\t\tNhap gia ve cho lich chieu phim nay: ";
    cin >> giave;
    (this->_QLLC + index)->IDPhim(idphim);
    (this->_QLLC + index)->IDPhong(idphong);
    (this->_QLLC + index)->ThoiGian(tempCa);
    (this->_QLLC + index)->GheConLai(slghe);
    (this->_QLLC + index)->SLGhe(slghe);
    (this->_QLLC + index)->GiaVe(giave);
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
int QLLC::FindIndexPhim(int idphim)
{
    int index = -1;
    for (int i = 0; i < _Quantity; i++)
    {
        if ((this->_QLLC + i)->IDPhim() == idphim)
        {
            index = i;
            break;
        }
    }
    return index;
}
int QLLC::FindIndexPhong(int id, int cur)
{
    int index = -1;
    for (int i = cur; i < _Quantity; i++)
    {
        if ((this->_QLLC + i)->IDPhong() == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
int QLLC::FindIndex(int id, const Ca &ca)
{
    int index = -1;
    for (int i = 0; i < _Quantity; i++)
    {
        if ((this->_QLLC + i)->IDPhong() == id && (this->_QLLC + i)->ThoiGian() == ca)
        {
            index = i;
            break;
        }
    }
    return index;
}
// Sap xep
void QLLC::Sort()
{
    int *arr = new int[_Quantity];
    for (int i = 0; i < _Quantity; i++)
        *(arr + i) = i;
    // Sort Phong
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->IDPhong() > (this->_QLLC + arr[j + 1])->IDPhong())
                swap(arr[j], arr[j + 1]);
        }
    }
    // Sort gio
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->ThoiGian().Hour() > (this->_QLLC + arr[j + 1])->ThoiGian().Hour())
                swap(arr[j], arr[j + 1]);
        }
    }
    // Sort ten phim
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->IDPhim() > (this->_QLLC + arr[j + 1])->IDPhim())
                swap(arr[j], arr[j + 1]);
        }
    }
    // Sort ngay
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->ThoiGian().Day() > (this->_QLLC + arr[j + 1])->ThoiGian().Day())
                swap(arr[j], arr[j + 1]);
        }
    }
    // Theo thang
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->ThoiGian().Month() > (this->_QLLC + arr[j + 1])->ThoiGian().Month())
                swap(arr[j], arr[j + 1]);
        }
    }
    // Theo nam
    for (int i = 0; i < _Quantity - 1; i++)
    {
        for (int j = 0; j < _Quantity - i - 1; j++)
        {
            if ((this->_QLLC + arr[j])->ThoiGian().Year() > (this->_QLLC + arr[j + 1])->ThoiGian().Year())
                swap(arr[j], arr[j + 1]);
        }
    }
    // Thay doi du lieu theo mang index
    LichChieu *temp = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(temp + i) = *(this->_QLLC + i);
    delete[] this->_QLLC;
    this->_QLLC = new LichChieu[this->_Quantity];
    for (int i = 0; i < this->_Quantity; i++)
        *(this->_QLLC + i) = *(temp + *(arr + i));
    delete[] temp;
    delete[] arr;
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
            int idphim, idphong, day, month, year, hour, soluonggheconlai, soluongghebandau, giave;
            char separator;
            FileIn >> idphim >> separator;
            FileIn >> idphong >> separator;
            FileIn >> day >> separator >> month >> separator >> year >> separator;
            FileIn >> hour >> separator;
            FileIn >> soluonggheconlai >> separator;
            FileIn >> soluongghebandau >> separator;
            FileIn >> giave;
            LichChieu A(idphim, idphong, Ca(day, month, year, hour), soluonggheconlai, soluongghebandau, giave);
            AddtotheEnd(A, FileIn);
            count++;
        }
        cout << "Da them thanh cong " << count << " lich chieu vao Database!" << endl;
        FileIn.close();
    }
}