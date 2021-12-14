#include "QuanLy/QLP.cpp"
// #include "Object/Film.cpp"
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
        QLP temp;
        temp.Show();
        temp.ImportFromFile();
        temp.Sort();
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