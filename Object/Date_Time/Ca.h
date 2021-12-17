#include "Date.cpp"
class Ca : public Date
{
private:
    int _Hour;

public:
    Ca();
    Ca(int, int, int, int);
    Ca(const Ca &);
    ~Ca();
    int Day();
    int Month();
    int Year();
    int Hour();
    void ShowCa();
    friend ostream &operator<<(ostream &, const Ca &);
    friend istream &operator>>(istream &, Ca &);
    bool operator==(const Ca &);
    void InsertObjecttoFile(ofstream &);
};
