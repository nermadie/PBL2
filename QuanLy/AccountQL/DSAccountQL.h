#include "../../Object/Account/Account.cpp"
class DSAccountQL
{
protected:
    Account *_DSAccountQL;
    int _Quantity;

public:
    DSAccountQL();
    DSAccountQL(Account *, int);
    DSAccountQL(const DSAccountQL &);
    ~DSAccountQL();
    int Quantity();
    void AddtotheEnd(Account &);
    int FindUsername(int);
    string GivePass(int);
    void Update(const int &);
};
