#include "../QuanLy/LichChieu/QLLC.cpp"
class MuaVe
{
public:
    static void XemDanhSachLichChieuHienCo();
    static void XemDanhSachLichChieuTheoNgay();
    static void XemDanhSachPhimHienCo();
    static void XemDanhSachLichChieutheoPhim();
    static void MuaVeXemPhim();
};
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
    cout << "Ban muon xem phim o phong chieu nao: ";
    int maphong;
    cin >> maphong;
    int soluong;
    cout << "Nhap so luong ve ban muon mua: ";
    cin >> soluong;
    tempLich.DaMuaVe(tempCa, maphong, soluong);
}