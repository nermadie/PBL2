#include "./Object/LichChieu/LichChieu.cpp"
bool GD(int a, int b)
{
    return a < b;
}
bool TD(int a, int b)
{
    return a > b;
}
int main()
{
    try
    {
        bool b[10];
        for (int i = 0; i < 10; i++)
            b[i] = 1;
        LichChieu a(1, 1, Ca(22, 12, 2002, 8), b, 10);
        a.ShowLichChieu();
    }
    catch (const char *msg)
    {
        cout << endl
             << msg;
    }
    catch (string msg)
    {
        cout << endl
             << msg;
    }
    return 0;
}