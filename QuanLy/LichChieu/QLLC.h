#pragma once
#include "../../Object/LichChieu/LichChieu.cpp"
#include "../Phim/QLP.cpp"
#include "../PhongChieu/QLPC.cpp"
<<<<<<< HEAD
bool GD(int a, int b);
bool TD(int a, int b);
class QLLC // Bao gồm 2 khoá chính là _ThoiGian và _Phong
=======

bool GD(int a, int b);
bool TD(int a, int b);
class QLLC 
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
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
    int AddtotheEnd(LichChieu &);
    void AddtotheEnd(LichChieu &, ifstream &);
    void AddtoTop(LichChieu &);
    void AddtoTop(LichChieu &, ifstream &);
    void AddtoPosition(LichChieu &, int);
    void AddtoPosition(LichChieu &, int, ifstream &);
    void Update(int);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int &);
    int FindIndexPhong(int, int);
    int FindIndex(int, const Ca &);
    // Bubble Sort
    void Sort();
    void ImportFromFile();
<<<<<<< HEAD
};
=======
};
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
