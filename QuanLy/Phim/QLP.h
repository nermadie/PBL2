#pragma once
#include "../../Object/Film_PhongChieu/Film.cpp"
#include "../../Utilis/Utilis.cpp"
bool GD(int a, int b);
bool TD(int a, int b);
class QLP
{
protected:
    Film *_QLP;
    int _Quantity;

public:
    QLP();
    QLP(Film *, int);
    QLP(const QLP &);
    ~QLP();
    int TongSoLuongPhim(); // thong ke phim an khach
    void Show();
    void Show1Film(int);
    void ShowTenPhim(int); // Cho class QLLC
    int AddtotheEnd(Film &);
    void AddtotheEnd(Film &, ifstream &);
    void AddtoTop(Film &);
    void AddtoTop(Film &, ifstream &);
    void AddtoPosition(Film &, int);
    void AddtoPosition(Film &, int, ifstream &);
    void Update(const int &);
    void UpdatenotID(const int &);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int &);
    // BinarySearch
    int BinarySearch(int, int, int);
    int IndexOf(int);
    // QuickSort
    int Partition(int *, int, int, bool (*CTH)(int a, int b));
    void QuickSort(int *, int, int, bool (*CTH)(int a, int b));
    void Sort(bool (*CTH)(int a, int b) = TD);
    void ImportFromFile();
};