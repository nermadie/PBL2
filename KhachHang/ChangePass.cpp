#include "ChangePass.h"
void ChangePass::DoiMatKhau(int username)
{
    DSAccount temp;
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
    temp.Update(username);
}