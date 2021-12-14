#include "NhanVien.h"
int main()
{
    try
    {
        NhanVien nv1(1, "Minh", Date(22, 8, 2002), Date(22, 12, 1234), "0123012310", "38 Phan Tu", 0, 3500.0);
        nv1.ShowNV();
        cout << nv1;
    }
    catch (const char *msg)
    {
        cout << endl
             << msg;
    }
    return 0;
}