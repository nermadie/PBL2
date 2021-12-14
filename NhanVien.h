#include "Date.h"
#include <iostream>
using namespace std;
class NhanVien
{
protected:
    int _ID;
    string _Name;
    Date _Birthday;
    Date _AdmissionDate;
    string _PhoneNumber;
    string _Address;
    bool _Gender;
    double _Wage;

public:
    NhanVien();
    NhanVien(int, string, Date, Date, string, string, bool, double);
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
    void Wage(double);
    friend ostream &operator<<(ostream &, const NhanVien &);
    friend istream &operator>>(istream &, NhanVien &);
};