#include "DSAccount.h"
#include <fstream>
#include <conio.h>
DSAccount::DSAccount()
{
    ifstream FileIn("Database/ID_Password/id_password.txt", ios_base::in);
    if (FileIn.fail())
    {
        cout << "Khong tim thay Database! Ban co muon tao Database moi?(Y/N)" << endl;
        if (!kbhit())
        {
            char key = getch();
            if (key == 27 || key == 'n' || key == 'N')
            {
                throw "Hay xem xet lai Database va khoi dong lai chuong trinh";
            }
            else if (key == 'Y' || key == 'y')
            {
                this->_DSAccount = nullptr;
                this->_Quantity = 0;
            }
        }
    }
    else
    {
        _Quantity = 0;
        while (!FileIn.eof())
        {
            int id;
            string pass;
            char separator;
            FileIn >> id >> separator;
            getline(FileIn, pass);
            Account A(id, pass);
            AddtotheEnd(A);
        }
    }
    FileIn.close();
}
DSAccount::DSAccount(Account *DSAccount, int quantity) : _DSAccount(DSAccount), _Quantity(quantity) {}
DSAccount::DSAccount(const DSAccount &l)
{
    this->_DSAccount = l._DSAccount;
    this->_Quantity = l._Quantity;
}
DSAccount::~DSAccount()
{
    ofstream FileOut("Database/ID_Password/id_password.txt", ios_base::out);
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_DSAccount + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_DSAccount;
}
int DSAccount::Quantity()
{
    return this->_Quantity;
}
void DSAccount::AddtotheEnd(Account &nv)
{
    if (this->_Quantity == 0)
    {
        this->_DSAccount = new Account[this->_Quantity + 1];
        *(this->_DSAccount + this->_Quantity) = nv;
    }
    else
    {
        Account *temp = new Account[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_DSAccount + i);
        delete[] this->_DSAccount;
        this->_DSAccount = new Account[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_DSAccount + i) = *(temp + i);
        delete[] temp;
        *(this->_DSAccount + this->_Quantity) = nv;
    }
    this->_Quantity++;
}
int DSAccount::FindUsername(int id)
{
    int index = -1;
    for (int i = 0; i < this->_Quantity; i++)
    {
        if ((this->_DSAccount + i)->IDNguoiDung() == id)
        {
            index = i;
        }
    }
    return index;
}
string DSAccount::GivePass(int index)
{
    return (_DSAccount + index)->Password();
}
void DSAccount::Update(const int &id)
{
    int index = id - 1;
    if (index >= 0)
    {
        cout << "Moi ban nhap password moi: ";
        cin >> (*(this->_DSAccount + index));
    }
    else
        cout << "Khong co khach hang co ID: " << id << endl;
}