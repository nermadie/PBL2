#include "SignIn.h"

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
    int pass;
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
        cout << "Khong co username: " << username << "! Xin hay nhap lai username: ";
        count++;
    }

    // Password
    count = 0;
    cout << "\n\t\t\t\t\tEnter Password: ";
    char p[30];
    int i = 0;
    while (1)
    {
        do
        {
            pass = getch();
            if (pass != 13 && pass != 8)
                cout << "*";
            if (pass == 8 && count > 0)
            {
                cout << "\b"
                     << " "
                     << "\b";
                count--;
            }
            else if (pass == 8 && count == 0)
                count = 0;
            else
            {
                p[count] = pass;
                count++;
            }
            cout.flush();
        } while (pass != 13);
        p[i] = '\0';
        for (i = 0; i < count - 1; i++)
            cout << "\b";
        for (i = 0; i < count; i++)
            cout << "\b";
        count = 0;
        cout.flush();
        string a(p);
        cout << pass << endl;
        if (a == rightpassword)
        {
            cout << endl
                 << "Ban da dang nhap thanh cong!";
            if (username > 0)
            {
                MenuChinh1(username);
            }
            else
                MenuChinh2();
        }
        else
        {
            cout << count << endl;
            if (count == 5)
            {
                DangNhapQuaSoLanQuyDinh();
            }
            cout << endl
                 << "Ban nhap sai password! Xin hay nhap lai password: ";
            i = 0;
            count++;
        }
    }
    return username;
}
