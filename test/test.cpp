#include <iostream>
#include <conio.h>
using namespace std;
double chia(int a, int b)
{
    if (b == 0)
    {
        throw "Chu y: Ban dang chi cho so 0!!!";
    }
    return (a / b);
}
int main()
{
    if (!kbhit())
    {
        char key = getch();
        if (key != '0')
            cout << "asdf";
    }
    chia(1, 0);
    return 0;
}