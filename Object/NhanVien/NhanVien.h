#include "../Date_Time/Date.cpp"
class NhanVien
{
private:
    int _ID;
    string _Name;
    Date _Birthday;
    Date _AdmissionDate;
    string _PhoneNumber;
    string _Address;
    bool _Gender;
    int _Wage;

public:
    NhanVien();
    NhanVien(int, string, Date, Date, string, string, bool, int);
    NhanVien(const NhanVien &);
    ~NhanVien();
    void ShowNV();
    int ID();
    void ID(int);
    void Name(string);
    void Birthday(Date);
    void AdmissionDate(Date);
    void PhoneNumber(string);
    void Address(string);
    void Gender(bool);
    void Wage(int);
    friend ostream &operator<<(ostream &, const NhanVien &);
    friend istream &operator>>(istream &, NhanVien &);
    void InsertObjecttoFile(ofstream &);
};