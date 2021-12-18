#include "MuaVe.h"
void MuaVe::XemDanhSachLichChieuHienCo()
{
    QLLC temp;
    temp.Show();
}
void MuaVe::XemDanhSachLichChieuTheoNgay()
{
    QLLC temp;
    temp.Sort();
    Date a;
    cout << "Moi ban nhap ngay: ";
    cin >> a;
    temp.XemLichChieuTheoNgay(a);
}
void MuaVe::XemDanhSachPhimHienCo()
{
    QLP temp;
    temp.Sort();
    temp.Show();
}
void MuaVe::XemDanhSachLichChieutheoPhim()
{
    QLLC tempLich;
    tempLich.Sort();
    QLP tempPhim;
    tempPhim.Sort();
    tempPhim.Show();
    cout << "\t\tNhap ma phim de xem chi tiet lich chieu: ";
    int maphim;
    cin >> maphim;
    tempLich.XemLichChieuTheoPhim(maphim);
}
void MuaVe::MuaVeXemPhim()
{
    int idkhachmua;
    while (1)
    {
        QLLC tempLich;
        tempLich.Sort();
        QLP tempPhim;
        tempPhim.Sort();
        tempPhim.Show();
        cout << "\t\tNhap ma phim de xem chi tiet lich chieu: ";
        int maphim;
        cin >> maphim;
        tempLich.XemLichChieuTheoPhim(maphim);
        cout << "\t\tNhap ca va ngay ban muon mua ve: " << endl;
        Ca tempCa;
        cin >> tempCa;
        cout << "Ban muon xem phim o phong chieu nao (co the co nhieu phong): ";
        int maphong;
        cin >> maphong;
        int soluong;
        cout << "Nhap so luong ve ban muon mua: ";
        cin >> soluong;
        int check = tempLich.DatMuaVe(tempCa, maphong, soluong);
        if (check != -1)
        {
            string Path = "Database/MuaVe/KH" + to_string(idkhachmua) + ".txt";
            ofstream FileOut(Path, ios_base::app);
            FileOut << maphim << "|";
            tempCa.InsertObjecttoFile(FileOut);
            FileOut << maphong << "|" << soluong << "|" << check << '\n';
            FileOut.close();
            break;
        }
    }
}
void MuaVe::XemLichSuMuaVe()
{
    int idkhachmua;
    QLP temp;
    int tongsotiendamua = 0;
    string Path = "Database/MuaVe/KH" + to_string(idkhachmua) + ".txt";
    ifstream FileIn(Path, ios_base::in);
    cout << "\t\t+===================================================================================================================+" << endl;
    cout << "\t\t|                                                 ** LICH SU MUA VE **                                              |" << endl;
    cout << "\t\t+========================================+============+===========+==========+==============+==========+============+" << endl;
    cout << "\t\t|               Ten phim                 | Ngay Chieu | Thoi Gian | Ma Phong | SL ve da mua |  Gia ve  | Thanh Tien |" << endl;
    cout << "\t\t+========================================+============+===========+==========+==============+==========+============+" << endl;
    while (!FileIn.eof())
    {
        char separator;
        int idphim;
        FileIn >> idphim >> separator;
        cout << "\t\t| ";
        temp.ShowTenPhim(idphim);
        int dd, mm, yyyy, hh;
        FileIn >> dd >> separator >> mm >> separator >> yyyy >> separator >> hh >> separator;
        Ca tempCa(dd, mm, yyyy, hh);
        cout << " | ";
        tempCa.ShowDate();
        cout << " |   ";
        tempCa.ShowCa();
        int maphong;
        FileIn >> maphong >> separator;
        cout << "   |    " << setw(3) << left << maphong << "   |      ";
        int soluong;
        FileIn >> soluong >> separator;
        cout << setw(2) << left << soluong << "      | ";
        int thanhtien;
        FileIn >> thanhtien;
        cout << setw(9) << left;
        InTienVe(thanhtien / soluong);
        cout << "| ";
        cout << setw(9) << left;
        InTienVe(thanhtien);
        cout << "  |\n";
        tongsotiendamua += thanhtien;
    }
    cout << "\t\t+========================================+============+===========+==========+==============+==========+============+" << endl;
    cout << "\t\t| Tong so tien ban da mua ve :                                                                         | ";
    cout << setw(9) << left;
    InTienVe(tongsotiendamua);
    cout << "  | " << endl;
    cout
        << "\t\t+======================================================================================================+============+" << endl;
        system("pause");
    FileIn.close();
}