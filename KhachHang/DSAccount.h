#include "../Object/Account/Account.cpp"
bool GD(int a, int b);
bool TD(int a, int b);
class DSAccount
{
protected:
    Account *_DSAccount;
    int _Quantity;

public:
    DSAccount();
    DSAccount(Account *, int);
    DSAccount(const DSAccount &);
    ~DSAccount();
    int Quantity();
    void AddtotheEnd(Account &);
    void Update(const int &);
};
