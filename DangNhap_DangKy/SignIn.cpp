#include "SignIn.h"
#include <unistd.h>

void SignIn::DangNhapQuaSoLanQuyDinh()
{
    throw "Ban da dang nhap sai qua so lan quy dinh!!";
}

int SignIn::DangNhap()
{
    cout << "\t\t\t\t      *********************************************" << endl;
    cout << "\t\t\t\t                       DANG NHAP                       " << endl;
    cout << "\t\t\t\t      *********************************************" << endl;
    int username;
    char pass;
    string rightpassword;
    cout << "\n\t\t\t\t\tEnter User: ";
    int count = 0;
    while (true)
    {
        cin >> username;
        if (username < 0)
        {
            DSAccountQL temp;
            int index = temp.FindUsername(username);
            if (-1 != index)
            {
                rightpassword = temp.GivePass(index);
                break;
            }
        }
        else if (username > 0)
        {
            DSAccount temp;
            int index = temp.FindUsername(username);
            if (-1 != index)
            {
                rightpassword = temp.GivePass(index);
                break;
            }
        }
        if (count == 5)
        {
            DangNhapQuaSoLanQuyDinh();
        }
        cout << "\t\t\t\t\tKhong co username: " << username << "! Xin hay nhap lai username: ";
        count++;
    }
    count = 0;
    cout << "\n\t\t\t\t\tEnter Password: ";
    char c = 0;
    char *x = new char[30];
    int i = 0;
    while (1)
    {
        while (1)
        {
            c = getch();
            if (c == 13 || c == 8)
            {
                x[i] = '\0';
                break;
            }
            else
            {
                x[i++] = c;
                cout << "*";
            }
        }
        x[i] = '\0';
        string a(x);
        if (a == rightpassword)
        {
            cout << endl
                 << "\t\t\t\t\tBan da dang nhap thanh cong!";
            sleep(1);
            delete[] x;
            if (username > 0)
            {
                MenuChinh1(username);
            }
            else
                MenuChinh2();
            break;
        }
        else
        {
            if (count == 5)
            {
                DangNhapQuaSoLanQuyDinh();
            }
            cout << endl
                 << "\t\t\t\t\tBan nhap sai password! Xin hay nhap lai password: ";
            delete[] x;
            x = new char[30];
            i = 0;
            count++;
        }
    }
    return username;
}