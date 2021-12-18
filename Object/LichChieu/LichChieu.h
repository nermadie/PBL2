#include "../Film_PhongChieu/Film.cpp"
#include "../Film_PhongChieu/PhongChieu.cpp"
#include "../../Object/Date_Time/Ca.cpp"
class LichChieu
{
private:
    int _IDPhim;
    int _IDPhong;
    Ca _ThoiGian;
    int _GheConLai;
    int _SLGhe;
    int _GiaVe;

public:
    LichChieu();
    LichChieu(int, int, Ca, int, int, int);
    LichChieu(const LichChieu &);
    int IDPhim();
    int IDPhong();
    Ca ThoiGian();
    int GheConLai();
    int SLGhe();
    int GiaVe();
    void IDPhim(int);
    void IDPhong(int);
    void ThoiGian(Ca);
    void GheConLai(int);
    void SLGhe(int);
    void GiaVe(int);
    ~LichChieu();
    void ShowLichChieu();
    bool DateCompare(Date &);
    bool IDPhimCompare(int &);
<<<<<<< HEAD
=======
    friend ostream &operator<<(ostream &, const LichChieu &);
    friend istream &operator>>(istream &, LichChieu &);
>>>>>>> 3aca29cbe5d1390240f0f1b1c128aeeb03e8aadd
    void InsertObjecttoFile(ofstream &);
};
