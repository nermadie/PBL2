#include "../../Object/Film_PhongChieu/PhongChieu.cpp"
bool GD(int a, int b);
bool TD(int a, int b);
class QLPC
{
protected:
    PhongChieu *_QLPC;
    int _Quantity;

public:
    QLPC();
    QLPC(PhongChieu *, int);
    QLPC(const QLPC &);
    ~QLPC();
    void Show();
    int AddtotheEnd(PhongChieu &);
    void AddtotheEnd(PhongChieu &, ifstream &);
    void AddtoTop(PhongChieu &);
    void AddtoTop(PhongChieu &, ifstream &);
    void AddtoPosition(PhongChieu &, int);
    void AddtoPosition(PhongChieu &, int, ifstream &);
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
