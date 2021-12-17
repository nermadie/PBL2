#include "../../Object/NhanVien/NhanVien.cpp"
bool GD(int a, int b);
bool TD(int a, int b);
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
    void Show1NV(int);
    int AddtotheEnd(NhanVien &);
    void AddtotheEnd(NhanVien &, ifstream &);
    void AddtoTop(NhanVien &);
    void AddtoTop(NhanVien &, ifstream &);
    void AddtoPosition(NhanVien &, int);
    void AddtoPosition(NhanVien &, int, ifstream &);
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