// #include "../Library/List/List.cpp"
// class Film;
class PhongChieu
{
private:
    int _IDPhongChieu;
    bool *_Ghe;
    // List<Film> *_Film;

public:
    PhongChieu();
    PhongChieu(int, string, string, string, int);
    ~PhongChieu();
    PhongChieu(const PhongChieu &);
    void ShowPhim();
    int IDPhongChieu();
    void IDPhongChieu(int);
    friend istream &operator>>(istream &, PhongChieu &);
    void InsertObjecttoFile(ofstream &);
};