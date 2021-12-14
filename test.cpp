#include "QLNV.h"
int main()
{
    try
    {
        NhanVien nv1(8, "Minh", Date(22, 8, 2002), Date(22, 12, 1234), "0123012310", "38 Phan Tu", 0, 3500.0);
        nv1.ShowNV();
        cout << nv1;
        QLNV temp;
        temp.Show();
        temp.AddtotheEnd(nv1);
        temp.ImportFromFile();
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