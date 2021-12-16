#include "./KhachHang/Register.cpp"
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
        Register::NhapThongTinKhachHang();
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