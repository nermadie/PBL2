#pragma once
#include "../../Object/LichChieu/LichChieu.cpp"
#include "../Phim/QLP.cpp"
#include "../PhongChieu/QLPC.cpp"
bool GD(int a, int b);
bool TD(int a, int b);
class QLLC // Bao gồm 2 khoá chính là _ThoiGian và _Phong
{
private:
    LichChieu *_QLLC;
    int _Quantity;

public:
    QLLC();
    QLLC(LichChieu *, int);
    QLLC(const QLLC &);
    ~QLLC();
    void Show();
    void XemLichChieuTheoNgay(Date &);  // Khach
    void XemLichChieuTheoPhim(int &);   // Khach
    int DatMuaVe(const Ca &, int, int); // Khach
    void TongDoanhThu_Toanbo();         // Quan ly
    void ThongKePhimAnKhach();          // Quan ly
    void ThongKeKhungGio();             // Quan ly
    void XemlaidanhsachPhim();          // Quan ly
    void XemlaidanhsachPhongChieu();    // Quan ly
    void AddtotheEnd(LichChieu &);
    void AddtotheEnd(LichChieu &, ifstream &);
    void AddtoTop(LichChieu &);
    void AddtoTop(LichChieu &, ifstream &);
    void AddtoPosition(LichChieu &, int);
    void AddtoPosition(LichChieu &, int, ifstream &);
    void Update(const int &, const int &, const int &, const int &, const int &);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int &);
    int FindIndexPhong(int, int);
    // Bubble Sort
    void Sort();
    void ImportFromFile();
};
