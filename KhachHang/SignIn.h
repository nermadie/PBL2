#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <conio.h>
using namespace std;
void TextColor(int x)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, x);
}
class SignIn
{
public:
    int pass, i, dem = 0;
    char p[10], user[20];
    TextColor(11);
    cout << "\n\t\t\t\t\tEnter User: ";
    cin >> user;
    while (strcmp(user, "abcd"))
    {
        cout << "\n\t\t\t\t\tAgain!";
        cout << "\n\n\t\t\t\t\tEnter User: ";
        cin >> user;
    }

    cout << "\n\t\t\t\t\tEnter Password (8 charecter): ";
    cout.flush();
    do
    {
        do
        {
            pass = getch();
            if (pass != 13 && pass != 8 && pass != ' ')
                cout << "*";
            if (pass == 8 && dem > 0)
            {
                cout << "\b"
                     << " "
                     << "\b";
                dem--;
            }
            else if (pass == 8 && dem == 0)
                dem = 0;
            else
            {
                p[dem] = pass;
                dem++;
            }
            cout.flush();
        } while (pass != 13);

        for (i = 0; i < dem - 1; i++)
            cout << "\b";
        for (i = 0; i < dem; i++)
            cout << " ";
        for (i = 0; i < dem; i++)
            cout << "\b";
        dem = 0;
        cout.flush();
    } while (p[0] != 'm' || p[1] != 'a' || p[2] != 'n' || p[3] != 'h' || p[4] != 'h' || p[5] != 'n' || p[6] != 'e' || p[7] != 'e');
};

SignIn::SignIn(/* args */)
{
}

SignIn::~SignIn()
{
}
