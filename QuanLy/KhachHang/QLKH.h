#include "../../Object/KhachHang/KhachHang.cpp"
bool GD(int a, int b);
bool TD(int a, int b);
class QLKH
{
protected:
    KhachHang *_QLKH;
    int _Quantity;

public:
    QLKH();
    QLKH(KhachHang *, int);
    QLKH(const QLKH &);
    ~QLKH();
    int Quantity();
    void Show();
    void Show1KH(int);
    void AddtotheEnd(KhachHang &);
    void AddtotheEnd(KhachHang &, ifstream &);
    void AddtoTop(KhachHang &);
    void AddtoTop(KhachHang &, ifstream &);
    void AddtoPosition(KhachHang &, int);
    void AddtoPosition(KhachHang &, int, ifstream &);
    void Update(const int &);
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