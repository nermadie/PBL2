#pragma once
#include <iostream>
using namespace std;
#include <windows.h>
#include <iomanip>
bool GD(int a, int b)
{
    return a < b;
}
bool TD(int a, int b)
{
    return a > b;
}
void TextColor(int x)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, x);
}
void InLine(int n)
{
    for (int i = 0; i < n; i++)
        cout << "=";
}
//
int SoChuSo(int x)
{
    int count = 0;
    while (x)
    {
        x /= 10;
        count++;
    }
    return count;
}
void InTienVe(int x)
{
    int n = SoChuSo(x);
    string num = to_string(x);
    char str[n + 1];
    int z = 0;
    for (int i = n; i > 0; i--)
    {
        if (i % 3 == 1 && i != 1)
        {
            str[z++] = num[n - i];
            str[z++] = '.';
        }
        else
            str[z++] = num[n - i];
    }
    str[z] = '\0';
    num = string(str);
    cout << num;
}