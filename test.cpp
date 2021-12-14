#include "QLNV.h"
int main()
{
    try
    {
        QLNV temp;
        temp.Show();
        temp.ImportFromFile();
        temp.Show();
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