#include <iostream>
using namespace std;

void thanh_sang(int x, int y,int w, int h, int b_color, string nd)
{
    for (int iy = y + 1; iy <= y+h - 1; iy++)
    {
        for(int ix = x + 1; ix <= x+w - 1; ix++)
        {
            gotoxy(ix, iy);
            cout << " ";
        }   
    }
    gotoxy(x + 1, y + 1);
    cout << nd;
}

void box(int x, int y, int w, int h, int t_color, int b_color, string nd)
{
    textcolor(b_color);
    for (int iy = y + 1; iy <= y+h - 1; iy++)
    {
        for(int ix = x + 1; ix <= x+w - 1; ix++)
        {
            gotoxy(ix, iy);
            cout << " ";
        }
    }
    gotoxy(x + 1, y + 1);
    cout << nd;
    // vẽ viền
    textcolor(t_color);
    if(h <= 1 || w <= 1) return;
    for (int ix = x; ix <= x + w; ix++)
    {
        gotoxy(ix,y);
        cout << char(196);
        gotoxy(ix, y+h);
        cout << char(196);
    }
    for(int iy = y; iy <= y + h; iy++)
    {
        gotoxy(x, iy);
        cout << char(179);
        gotoxy(x+w, iy);
        cout << char(179);
    }
    gotoxy(x, y); cout << char(218);
    gotoxy(x+w, y); cout << char(191);
    gotoxy(x, y+h); cout << char(192);
    gotoxy(x+w, y+h); cout << char(217);
}
void n_box(int x, int y, int w, int h, int t_color, int b_color, string nd, int n)
{
    for(int i = 0; i < n; i++)
    {
        box(x, y + (i*2), w, h, t_color, b_color, nd);
        if(i != 0)
        {
        gotoxy(x, y + (i*2)); cout << char(195);
        gotoxy(x + 20,y + (i*2)); cout << char(180);
        }
    }
}
void menu()
{
    ShowCursor(0);
    // setting
    int w = 20;
    int h = 2;
    int t_color = 11;
    int b_color = 9;
    int b_color_sang = 75;
    string nd = "Hello";
    int n = 4;
    n_box(x, y, w, h, t_color, b_color, nd, n);
    thanh_sang(x,y,w,h,b_color_sang, nd);
    int xp = x, yp = y; // tọa độ thanh sáng
    int xc = xp, yc = yp;
    bool kt = true;
    while (true)
    {
        if(kt == true)
        {
            gotoxy(xc, yc);
            thanh_sang(xc, yc, w, h, b_color, nd);
            xc = xp, yc = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, nd);
            kt = false;
        }
        if(_kbhit())
        {
            char c = getch();
            if(c == -32)
            {
                kt = true;
                c = getch();
                if(c == 72)
                {
                    if(yp != y) yp -= 2;
                    else
                    {
                        yp = y + h*(n-1);
                    }
                }
                else if (c == 80)
                {
                    if(yp != y +h*(n-1))
                    yp +=2;
                    else yp = y;
                }
            }
        }
    }
     
}

int main()
{
    //Menu động
    menu();
    
    _getch();
} 