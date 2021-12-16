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
    void XemtenPhim_ungvoiID(int);
    void XemlaidanhsachPhim();
    void XemlaidanhsachPhongChieu();
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
    // Interpolation Sort
    void Sort(bool (*CTH)(int a, int b) = TD);
    void ImportFromFile();
};
