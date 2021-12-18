#include "./DangNhap_DangKy/SignIn.cpp"


int main()
{
    try
    {
        TextColor(15);
        SignIn::DangNhap();
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
