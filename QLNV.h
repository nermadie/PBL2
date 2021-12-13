#include "NhanVien.h"
class QLNV:
{
protected:
    NhanVien *_List;
    int _Quantity;

public:
    QLNV();
    QLNV(NhanVien *, int);
    QLNV(const QLNV &l);
    ~QLNV();
    void Show();
    void AddtotheEnd(const NhanVien &nv);
    void AddtoTop(const NhanVien &nv);
    void AddtoPosition(const NhanVien &nv, int position);
    void Update(const int &id);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int &position);
    int IndexOf(int id);
    void Sort(bool (*CTH)(int a, int b) = TD);
    friend class NhanVien;
};