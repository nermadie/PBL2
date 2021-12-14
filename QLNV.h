#include "NhanVien.h"

class QLNV
{
protected:
    NhanVien *_QLNV;
    int _Quantity;

public:
    QLNV();
    QLNV(NhanVien *, int);
    QLNV(const QLNV &);
    ~QLNV();
    void Show();
    void AddtotheEnd(NhanVien &);
    void AddtoTop(NhanVien &);
    void AddtoPosition(NhanVien &, int);
    void Update(const int &);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int &);
    int BinarySearch(int, int, int);
    int IndexOf(int);
    void Sort(bool (*CTH)(int a, int b));
    void ImportFromFile();
};