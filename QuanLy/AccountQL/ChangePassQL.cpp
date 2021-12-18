#pragma once
#include "ChangePassQL.h"
#include <conio.h>
void ChangePassQL::DoiMatKhauQL(int username)
{
    DSAccountQL temp;
    string password, rightpassword;
    cout << "\t\t\t\t\t\tNhap password hien tai: ";
    while (1)
    {
        cin >> password;
        rightpassword = temp.GivePass(username);
        if (password == rightpassword)
        {
            cout << "\t\t\t\t\t\tBan da nhap sai password hien tai cua minh! Xin ban hay nhap lai password hien tai: ";
        }
        else
            break;
    }
    TextColor(12);
    cout << "\t\t\t\t\t\tBan co chac la muon doi mat khau?(y/n)";
    TextColor(14);
    while (1)
    {
        char condition = getch();
        cout << endl;
        if (condition == 'y' || condition == 'Y')
        {
            temp.Update(username);
            break;
        }
        else if (condition == 'n' || condition == 'N')
        {
            break;
        }
    }
}