#include "./DangNhap_DangKy/SignIn.cpp"
#include "./DangNhap_DangKy/Register.cpp"

void DangNhap_DangKy()
{
    PhanMoDau();
Menu:
    system("cls");
    TextColor(4);
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t                  DANG NHAP HOAC DANG KY                       " << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    TextColor(12);
    cout << "\n\n\t\t\t\t\t         -DANG NHAP HOAC DANG KY-";
    TextColor(14);
    cout << "\n\t\t\t _______________________________________________________________________";
    cout << "\n\t\t\t|"
         << "                                                          \t\t|";
    cout << "\n\t\t\t|"
         << "                           1.Dang nhap                    \t\t|";
    cout << "\n\t\t\t|"
         << "                                                          \t\t|";
    cout << "\n\t\t\t|"
         << "                           2.Dang ki                      \t\t|";
    cout << "\n\t\t\t|"
         << "                                                          \t\t|";
    cout << "\n\t\t\t|"
         << "                           3.Thoat                        \t\t|";
    cout << "\n\t\t\t|_______________________________________________________________________|";

    int chon;
    cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
    cin >> chon;
    while (chon < 0 || chon > 3)
    {
        cout << "\n\n\t\t\t\t\t\tNhap lua chon :";
        cin >> chon;
    }
    switch (chon)
    {
    case 1:
        system("cls");
        SignIn::DangNhap();
        cout << endl;
        system("pause");
        cout.flush();
        break;
    case 2:
        system("cls");
        Register::NhapThongTinKhachHang();
        cout << endl;
        system("pause");
        cout.flush();
        goto Menu;
        break;
    case 3:
        exit(0);
        break;
    }
}

int main()
{
    DangNhap_DangKy();
}