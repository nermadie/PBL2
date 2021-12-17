#include <iostream>
using namespace std;
#include <windows.h>

void TextColor(int x){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , x );
}
void InLine(int n){
    for (int i = 0; i < n; i++)
        cout<<"=";
}

void MenuKhachHang()
{
    system("cls");TextColor(12);
                cout<<"\n\n\t\t\t\t\t\t     -KHACH HANG-"; TextColor(14);
                cout<<"\n\t\t\t _______________________________________________________________________";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                1.Mua ve                               \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                2.Doi mat khau                         \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                3.Thoat                                \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|_______________________________________________________________________|";
}

void MenuMuaVe()
{
    system("cls");TextColor(12);
                cout<<"\n\n\t\t\t\t\t\t     -MUA VE-"; TextColor(14);
                cout<<"\n\t\t\t _______________________________________________________________________";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                1.Danh sach lich chieu hien co         \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                2.Danh sach lich chieu theo ngay       \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                3.Danh sach phim hien co               \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                4.Danh sach lich chieu theo phim       \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                5.Mua ve xem phim                      \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                6.Xem lich su mua ve                   \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                7.Quay Lai                             \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                8.Thoat                                \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLy()
{
    system("cls");TextColor(12);
                cout<<"\n\n\t\t\t\t\t\t     -QUAN LY-"; TextColor(14);
                cout<<"\n\t\t\t _______________________________________________________________________";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                1.Quan ly nhan vien                    \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                2.Quan ly phim                         \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                3.Quan ly khach hang                   \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                4.Quan ly lich chieu                   \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                5.Quan ly phong chieu                  \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                6.Quan ly doanh thu                    \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                7.Doi mat khau                         \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                8.Thoat                                \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyNhanVien()
{
    system("cls");TextColor(12);
                cout<<"\n\n\t\t\t\t\t\t     -QUAN LY NHAN VIEN-"; TextColor(14);
                cout<<"\n\t\t\t _______________________________________________________________________";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                1.Danh sach nhan vien                  \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                2.Them nhan vien                       \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                3.Xoa nhan vien                        \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                4.Sua thong tin nhan vien              \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                5.Tim kiem nhan vien theo ID           \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                6.Quay lai                             \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                7.Thoat                                \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|_______________________________________________________________________|";
}

void MenuQuanLyPhim()
{
    system("cls");TextColor(12);
                cout<<"\n\n\t\t\t\t\t\t     -QUAN LY PHIM-"; TextColor(14);
                cout<<"\n\t\t\t _______________________________________________________________________";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                1.Danh sach phim                       \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                2.Them phim                            \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                3.Xoa phim                             \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                4.Sua thong tin phim                   \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                5.Tim kiem phim theo IDPhim            \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                6.Quay lai                             \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|"<<"                7.Thoat                                \t\t|";
                cout<<"\n\t\t\t|"<<"                                                       \t\t|";
                cout<<"\n\t\t\t|_______________________________________________________________________|";    
}

void MenuQuanLyKhachHang()
{

}

void MenuQuanLyLichChieu()
{

}

void MenuQuanLyPhongChieu()
{

}

void MenuQuanLyDoanhThu()
{

}

void MenuChinh1()
{
    MenuKhachHang:
    MenuKhachHang();
    int chon;
    cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
    cin >> chon;
    while(chon < 0 || chon > 3)
    {
        cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
        cin >> chon;
    }
    switch (chon)
    {
    case 1:
        {
            system("cls");
            Muave:
            MenuMuaVe();
            int a;
            cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
            cin >> a;
            while(a < 0 || a > 8)
            {
                cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
                cin >> a;
            }
            switch (a)
            {
            case 1:
                system ("cls");
                cout << "Danh sach lich chieu hien co: ";
                system("pause");
                goto Muave;
                break;
            case 2:
                system ("cls");
                cout << "Danh sach lich chieu theo ngay: ";
                system("pause");
                goto Muave;
                break;
            case 3:
                system ("cls");
                cout << "Danh sach phim hien co: ";
                system("pause");
                goto Muave;
                break;
            case 4:
                system ("cls");
                cout << "Danh sach lich chieu theo phim: ";
                system("pause");
                goto Muave;
                break;
            case 5:
                system ("cls");
                cout << "Mua ve xem phim: ";
                system("pause");
                goto Muave;
                break;
            case 6:
                system ("cls");
                cout << "Xem lich su mua ve: ";
                system("pause");
                goto Muave;
                break;
            case 7:
                goto MenuKhachHang;
                break;
            case 8:
                exit(0);
                break;
            
            }
        }
    case 2:
        system ("cls");
        cout << "Doi mat khau";
        system("pause");
        goto MenuKhachHang;
        break;
    case 3:
        exit(0);
        break;
    }
}

void MenuChinh2()
{
    MenuQuanLy:
    MenuQuanLy();
    int chon;
    cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
    cin >> chon;
    while(chon < 0 || chon > 8)
    {
        cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
        cin >> chon;
    }
    switch (chon)
    {
    case 1:
        {
            system("cls");
            MenuQuanLyNhanVien:
            MenuQuanLyNhanVien();
            int a;
            cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
            cin >> a;
            while(a < 0 || a > 7)
            {
                cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
                cin >> a;
            }
            switch (a)
            {
            case 1 :
                system("cls");
                cout << "Danh sach nhan vien";
                cout << endl;
                system("pause");
                goto MenuQuanLyNhanVien;
                break;
            case 2:
                system("cls");
                cout << "Them nhan vien";
                cout << endl;
                system("pause");
                goto MenuQuanLyNhanVien;
                break;
            case 3:
                system("cls");
                cout << "Xoa nhan vien";
                cout << endl;
                system("pause");
                goto MenuQuanLyNhanVien;
                break;
            case 4:
                system("cls");
                cout << "Sua thong tin nhan vien";
                cout << endl;
                system("pause");
                goto MenuQuanLyNhanVien;
                break;
            case 5:
                system("cls");
                cout << "Tim kiem nhan vien";
                cout << endl;
                system("pause");
                goto MenuQuanLyNhanVien;
                break;
            case 6:
                goto MenuQuanLy;
                break;
            case 7:
                exit(0);
                break;
            }
        }
    case 2:
        {
            system("cls");
            MenuQuanLyPhim:
            MenuQuanLyPhim();
            int b;
            cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
            cin >> b;
            while(b < 0 || b > 7)
            {
                cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
                cin >> b;
            }
            switch (b)
            {
            case 1 :
                system("cls");
                cout << "Danh sach phim";
                cout << endl;
                system("pause");
                goto MenuQuanLyPhim;
                break;
            case 2:
                system("cls");
                cout << "Them phim";
                cout << endl;
                system("pause");
                goto MenuQuanLyPhim;
                break;
            case 3:
                system("cls");
                cout << "Xoa phim";
                cout << endl;
                system("pause");
                goto MenuQuanLyPhim;
                break;
            case 4:
                system("cls");
                cout << "Sua thong tin phim";
                cout << endl;
                system("pause");
                goto MenuQuanLyPhim;
                break;
            case 5:
                system("cls");
                cout << "Tim kiem phim";
                cout << endl;
                system("pause");
                goto MenuQuanLyPhim;
                break;
            case 6:
                goto MenuQuanLy;
                break;
            case 7:
                exit(0);
                break;
            }
        }
    case 3:
        system("cls");
        cout << "Quan ly khach hang";
        system("pause");
        goto MenuQuanLy;    
    case 4:
        system("cls");
        cout << "Quan ly lich chieu";
        system("pause");
        goto MenuQuanLy;
    case 5:
        system("cls");
        cout << "Quan ly phong chieu";
        system("pause");
        goto MenuQuanLy;
    case 6:
        system("cls");
        cout << "Quan ly doanh thu";
        system("pause");
        goto MenuQuanLy;
    case 7:
        system("cls");
        cout << "Doi mat khau";
        system("pause");
        goto MenuQuanLy;
    case 8:
        exit(0);
        break;
    }
}

int main()
{
    MenuChinh2();
}