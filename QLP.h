#include "Phim.h"

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
    void Show();
    void AddtotheEnd(const Film &);
    void AddtoTop(const Film &);
    void AddtoPosition(const Film &, int);
    void Update(const int &);
    void DeleteTop();
    void DeleteEnd();
    void DeleteatPosition(const int &);
    int BinarySearch(int, int, int);
    int IndexOf(int);
    void Sort(bool (*CTH)(int a, int b));
};
