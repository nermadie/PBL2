// #include <iostream>
// using namespace std;
// // Ngày tháng năm
// class Date
// {
//     protected:
//         int day;
//         int month;
//         int year;
//     public:
//         Date(int, int, int);
//         ~Date();
// };

// Date::Date(int day, int month, int year)
// {
//     this->day = day;
//     this->month = month;
//     this->year = year;
// }

// Date::~Date()
// {
// }

// // Nhân viên
// class Nhanvien : public Date
// {
//     private:
//         int maNV;
//         string name;
//         int age;
//         string gender;
//         int numberphone;
//         string address;
//         int salary;
//     public:
//         Nhanvien(int = 1, string = "", int = 20, string = "", int = 1234, string = "", int = 1, int = 1, int = 2020, int = 0);
//         ~Nhanvien();
//         void Show(); 
//         int MaNV();
//         void MaNV(int);
//         string Name();
//         void Name(string);
//         int Age();
//         void Age(int);
//         int NumberPhone();
//         void NumberPhone(int);
//         string Address();
//         void Address(string);
//         friend ostream& operator<<(ostream&, const Nhanvien&);    
//         friend istream& operator>>(istream&, Nhanvien&);
// };

// int Nhanvien::MaNV()
// {
//     return this->maNV;
// }

// void Nhanvien::MaNV(int new_value)
// {
//     this->maNV = new_value;
// }
// string Nhanvien::Name()
// {
//     return name;
// }
// void Nhanvien::Name(string new_value)
// {
//     this->name = new_value;
// }
// int Nhanvien::Age()
// {
//     return age;
// }
// void Nhanvien::Age(int new_value)
// {
//     this->age = new_value;
// }
// int Nhanvien::NumberPhone()
// {
//     return numberphone;
// }
// void Nhanvien::NumberPhone(int new_value)
// {
//     this->numberphone = new_value;
// }
// string Nhanvien::Address()
// {
//     return address;
// }
// void Nhanvien::Address(string new_value)
// {
//     this->address = new_value;
// }

// Nhanvien::Nhanvien(int maNV, string name, int age, string gender, int numberphone, string address, int day, int month, int year, int salary)
//     : Date(day, month, year)
// {   
//     this->maNV = maNV;
//     this->name = name;
//     this->age = age;
//     this->gender = gender;
//     this->numberphone = numberphone;
//     this->address = address;
//     this->salary = salary;
// }

// Nhanvien::~Nhanvien(){}

// void Nhanvien::Show()
// {
//     cout << "Ma nhan vien: " << this->maNV;
//     cout << "Ten nhan vien: " << this->name;
//     cout << "\nTuoi nhan vien: " << this->age;
//     cout << "\n Gioi tinh: " << this->gender;
//     cout << "\nSo dien thoai: " << this->numberphone;
//     cout << "\nDia chi cua nhan vien: " << this->address;
//     cout << "\nNgay sinh cua nhan vien: " << this->day;
//     if (this->month < 10)
//     {
//         cout << "/0" << this->month << "/" << this->year << endl; 
//     }
//     else cout << "/" << this->month << "/" << this->year << endl;
//     cout << "\nLuong cua nhien vien: " << this->salary;
// }

// ostream& operator<<(ostream& o, const Nhanvien& n)
// {
//     o << "Ma nhan vien: " << n.maNV;
//     o << "\nTen nhan vien: " << n.name;
//     o << "\nTuoi nhan vien: " << n.age;
//     o << "\nGioi tinh: " << n.gender;
//     o << "\nSo dien thoai: " << n.numberphone;
//     o << "\nDia chi cua nhan vien: " << n.address;
//     o << "\nNgay sinh cua nhan vien: " << n.day;
//     if (n.month < 10)
//     {
//         cout << "/0" << n.month << "/" << n.year << endl; 
//     }
//     else cout << "/" << n.month << "/" << n.year << endl;
//     o << "Luong cua nhan vien: " << n.salary; 
//     return o;
// }

// istream& operator>>(istream& i, Nhanvien& n)
// {
//     cout << "Nhap ma nhan vien: ";
//     i >> n.maNV;
//     cout << "\nNhan ten nhan vien: ";
//     i >> n.name;
//     cout <<"\nNhap so tuoi: ";
//     i >> n.age;
//     cout <<"\nNhap gioi tinh: ";
//     i >> n.gender;
//     cout << "\nNhap so dien thoai: ";
//     i >> n.numberphone;
//     cout << "\nNhap dia chi: ";
//     i >> n.address;
//     cout << "\nNhap ngay thang nam sinh: ";
//     do
//     {
//         cout << "\nNgay: "; 
//         i >> n.day;
//     } while (n.day > 31 || n.day < 1);
//     do
//     {
//         cout << "Thang: "; 
//         i >> n.month;
//     } while (n.month > 12 || n.month < 1);
//     do
//     {
//         cout << "Nam: "; 
//         i >> n.year;
//     } while (n.year < 1);
//     cout << "Nhap tien luong: ";
//     i >> n.salary;
//     return i;
// }

// // quản lý nhân viên
// class QLNV
// {
//     private:
//         Nhanvien *n;
//         int p;
//     public:
//         QLNV();
//         ~QLNV();
//         void Add(Nhanvien); // Thêm nhân viên vào cuối mảng
//         void Show();
//         void Update(int);
//         int IndexOf(int);
//         void Delete(Nhanvien);

// };

// QLNV::QLNV()
// {
//     this->n = nullptr;
//     this->p = 0;
// }

// QLNV::~QLNV()
// {
//     delete[] this->n;
// }

// void QLNV::Show()
// {
//     for (int i = 0; i < this->p; i++)
//     {
//         (*(this->n + i)).Show();
//     }
    
// }

// void QLNV::Add(Nhanvien nv)
// {
//     if(this->p == 0)
//     {
//         this->n = new Nhanvien[this->p + 1];
//         *(this->n + this->p) = nv;
//     }
//     else
//     {
//         Nhanvien *temp = new Nhanvien[this->p];
//         for (int i = 0; i < this->p; i++)
//         {
//             *(temp + i) = *(this->n + i);
//         }
//         delete[] this->n;
//         this->n = new Nhanvien[this->p + 1];
//         for (int i = 0; i < this->p; i++)
//         {
//             *(this->n + i) = *(temp + i);
//         }
//         *(this->n + this->p) = nv;
//     }
//     this->p++;
// }

// void QLNV::Update(int m)
// {
//     int index = IndexOf(m);
//     if(index >= 0)
//     {
//         string name;
//         cout << "Name = ";
//         cin >> name;
//         (this->n + index)->Name(name);
//         int age;
//         cout << "Age = ";
//         cin >> age;
//         (this->n + index)->Age(age);
//         int numberphone;
//         cout << "NumberPhone = ";
//         cin >> numberphone;
//         (this->n + index)->NumberPhone(numberphone);
//         string address;
//         cout << "Address = ";
//         cin >> address;
//         (this->n + index)->Address(address);
//     }
// }

// int QLNV::IndexOf(int m)
// {
//    int index = -1;
//    for(int i = 0; i < this->p; i++)
//    {
//        if((this->n + i)->MaNV() == m)
//        {
//            index = i;
//            break;
//        }
//     }
//     return index;
// } 

// void QLNV::Delete(Nhanvien nv)
// {
//     int index = IndexOf(nv.MaNV());
//     if(index >= 0)
//     {
//         if(this->p == 1)
//         {
//             delete[] this->n;
//         }
//         else{
//             Nhanvien *temp = new Nhanvien[this->p];
//             for(int i = 0; i < this->p; ++i)
//                 *(temp + i) = *(this->n + i);
//             delete[] this->n;
//             this->n = new Nhanvien[this->p - 1];
//             for(int i = 0; i < this->p - 1; ++i)
//             {
//                 if(i < index)
//                 {
//                     *(this->n + i) = *(temp + i);
//                 }
//                 else
//                 {
//                     *(this->n + i) = *(temp + i + 1);
//                 }
//             }
//         }
//         this->p--;
//     }
// }

// // Phim
// class Film : public Date
// {
//     private:
//         int _MaPhim;
//         string _FilmName;
//         string _MainActor;
//         string _Category; // Thể loại
//         string _MovieDuration; // Phút
//     public:
//         Film(int = 1, string = "", string = "", string = "", string = "", int = 1, int = 1 , int = 2020);
//         ~Film();
//         void show();
//         int MaPhim();
//         void MaPhim(int);
//         string FilmName();
//         void FilmName(string);
//         string MainActor();
//         void MainActor(string);
//         string Category();
//         void Category(string);
//         string MovieDuration();
//         void MovieDuration(string);
//         friend ostream& operator<<(ostream&, const Film&);
//         friend istream& operator>>(istream&, Film&);
// };
// Film::Film(int _MaPhim, string _FilmName, string _MainActor, string _Category, string _MovieDuration,int day, int month, int year)
//     : Date(day, month, year)
// {
//     this->_MaPhim = _MaPhim;
//     this->_FilmName = _FilmName;
//     this->_MainActor = _MainActor;
//     this->_Category = _Category;
//     this->_MovieDuration = _MovieDuration;
// }

// Film::~Film(){}

// int Film::MaPhim()
// {
//     return _MaPhim;
// }
// void Film::MaPhim(int new_value)
// {
//     this->_MaPhim = new_value;
// }
// string Film::FilmName()
// {
//     return _FilmName;
// }
// void Film::FilmName(string new_value)
// {
//     this->_FilmName = new_value;
// }
// string Film::MainActor()
// {
//     return _MainActor;
// }
// void Film::MainActor(string new_value)
// {
//     this->_MainActor = new_value;
// }
// string Film::Category()
// {
//     return _Category;
// }
// void Film::Category(string new_value)
// {
//     this->_Category = new_value;
// }
// string Film::MovieDuration()
// {
//     return _MovieDuration;
// }
// void Film::MovieDuration(string new_value)
// {
//     this->_MovieDuration = new_value;
// }

// void Film::show()
// {
//     cout << "Ma phim: " << this->_MaPhim;
//     cout << "Ten phim: " << this->_FilmName;
//     cout << "\nCac dien vien chinh: " << this->_MainActor;
//     cout << "\nThe loai: " << this->_Category;
//     cout << "\nThoi luong phim: " << this->_MovieDuration;
//     cout << "\nNgay phat hanh: " << this->day;
//     if (this->month < 10)
//     {
//         cout << "/0" << this->month << "/" << this->year << endl; 
//     }
//     else cout << "/" << this->month << "/" << this->year << endl;
// }

// ostream& operator<<(ostream& o, const Film& f)
// {
//     o << "Ma phim: " << f._MaPhim;
//     o << "Ten phim: " << f._FilmName;
//     o << "\nCac dien vien chinh: " << f._MainActor;
//     o << "\nThe loai: " << f._Category;
//     o << "\nThoi luong phim: " << f._MovieDuration;
//     o << "\nNgay phat hanh: " << f.day;
//     if (f.month < 10)
//     {
//         o << "/0" << f.month << "/" << f.year << endl; 
//     }
//     else o << "/" << f.month << "/" << f.year << endl;
//     return o;
// }

// istream& operator>>(istream& i, Film& f)
// {
//     cout << "Nhap ma phim: ";
//     i >> f._MaPhim;
//     cout << "\nNhap ten phim: ";
//     i >> f._FilmName;
//     cout << "\nNhap cac dien vien chinh: ";
//     i >> f._MainActor;
//     cout << "\nNhap the loai: ";
//     i >> f._Category;
//     cout << "\nNhap thoi luong phim: ";
//     i >> f._MovieDuration;
//     cout << "\nNhap ngay phat hanh: ";
//     do
//     {
//         cout << "\nNgay: "; 
//         i >> f.day;
//     } while (f.day > 31 || f.day < 1);
//     do
//     {
//         cout << "\nThang: "; 
//         i >> f.month;
//     } while (f.month > 12 || f.month < 1);
//     do
//     {
//         cout << "\nNam: "; 
//         i >> f.year;
//     } while (f.year < 1);
//     return i;
// }


// // quản lý phim
// class QLP
// {
//     private:
//         Film *p;
//         int n;
//     public:
//         QLP();
//         ~QLP();
//         void Add(Film); // Thêm phim vào cuối mảng
//         void show();
//         void Update(int);
//         int IndexOf(int);
//         void Delete(Film);
// };

// QLP::QLP()
// {
//     this->p = nullptr;
//     this->n = 0;
// }

// QLP::~QLP()
// {
//     delete[] this->p;
// }

// void QLP::Add(Film f)
// {
//     if(this->n == 0)
//     {
//         this->p = new Film[this->n + 1];
//         *(this->p + this->n) = f;
//     }
//     else
//     {
//         Film *temp = new Film[this->n];
//         for (int i = 0; i < this->n; i++)
//         {
//             *(temp + i) = *(this->p + i);
//         }
//         delete[] this->p;
//         this->p = new Film[this->n + 1];
//         for (int i = 0; i < this->n; i++)
//         {
//             *(this->p + i) = *(temp + i);
//         }
//         *(this->p + this->n) = f;
//     }
//     this->n++;
// }

// void QLP::Update(int m)
// {
//     int index = IndexOf(m);
//     if(index >= 0)
//     {
//         string _FilmName;
//         cout << "FilmName: ";
//         cin >> _FilmName;
//         (this->p + index)->FilmName(_FilmName);
//         string _MainActor;
//         cout << "MainActor: ";
//         cin >> _MainActor;
//         (this->p + index)->MainActor(_MainActor);
//         string _Category;
//         cout << "Category: ";
//         cin >> _Category;
//         (this->p + index)->Category(_Category);
//         string _MovieDuration;
//         cout << "MovieDuration: ";
//         cin >> _MovieDuration;
//         (this->p + index)->MovieDuration(_MovieDuration);
//     }
// }

// int QLP::IndexOf(int m)
// {
//    int index = -1;
//    for(int i = 0; i < this->n; i++)
//    {
//        if((this->p + i)->MaPhim() == m)
//        {
//            index = i;
//            break;
//        }
//     }
//     return index;
// } 

// void QLP::Delete(Film f)
// {
//     int index = IndexOf(f.MaPhim());
//     if(index >= 0)
//     {
//         if(this->n == 1)
//         {
//             delete[] this->p;
//         }
//         else{
//             Film *temp = new Film[this->n];
//             for(int i = 0; i < this->n; ++i)
//                 *(temp + i) = *(this->p + i);
//             delete[] this->p;
//             this->p = new Film[this->n - 1];
//             for(int i = 0; i < this->n - 1; ++i)
//             {
//                 if(i < index)
//                 {
//                     *(this->p + i) = *(temp + i);
//                 }
//                 else
//                 {
//                     *(this->p + i) = *(temp + i + 1);
//                 }
//             }
//         }
//         this->n--;
//     }
// }


// int main()
// {
// }