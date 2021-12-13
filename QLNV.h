#include "NhanVien.h"

class QLNV : public NhanVien
{
protected:
    NhanVien *_QLNV;
    int _Quantity;

public:
    QLNV();
    QLNV(NhanVien*, int);
    QLNV(const QLNV&);
    ~QLNV();
    void Show();
    void AddtotheEnd(const NhanVien&);
    void AddtoTop(const NhanVien&);
    void AddtoPosition(const NhanVien&, int);
    void Update(const int&);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int&);
    int IndexOf(int id);
    // void Sort(bool (*CTH)(int a, int b) = TD);
    friend class NhanVien;
};