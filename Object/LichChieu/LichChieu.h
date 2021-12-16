#include "../Film_PhongChieu/Film.cpp"
#include "../Film_PhongChieu/PhongChieu.cpp"
#include "../../Object/Date_Time/Ca.cpp"
class LichChieu
{
private:
    int _IDPhim;
    int _IDPhong;
    Ca _ThoiGian;
    bool *_Ghe;
    int _SLGhe;

public:
    LichChieu();
    LichChieu(int, int, Ca, bool *, int);
    LichChieu(const LichChieu &);
    int IDPhim();
    int IDPhong();
    Ca ThoiGian();
    ~LichChieu();
    void ShowLichChieu();
    friend ostream &operator<<(ostream &, const LichChieu &);
    friend istream &operator>>(istream &, LichChieu &);
    void InsertObjecttoFile(ofstream &);
};
