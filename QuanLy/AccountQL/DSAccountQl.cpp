#include "DSAccountQL.h"
#include <fstream>
#include <conio.h>
DSAccountQL::DSAccountQL()
{
    ifstream FileIn("Database/ID_Password/id_passwordQL.txt", ios_base::in);
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
                this->_DSAccountQL = nullptr;
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
DSAccountQL::DSAccountQL(Account *DSAccountQL, int quantity) : _DSAccountQL(DSAccountQL), _Quantity(quantity) {}
DSAccountQL::DSAccountQL(const DSAccountQL &l)
{
    this->_DSAccountQL = l._DSAccountQL;
    this->_Quantity = l._Quantity;
}
DSAccountQL::~DSAccountQL()
{
    ofstream FileOut("Database/ID_Password/id_passwordQL.txt", ios_base::out);
    for (int i = 0; i < this->_Quantity; i++)
    {
        (_DSAccountQL + i)->InsertObjecttoFile(FileOut);
        if (i != this->_Quantity - 1)
            FileOut << "\n";
    }
    FileOut.close();
    delete[] this->_DSAccountQL;
}
int DSAccountQL::Quantity()
{
    return this->_Quantity;
}
void DSAccountQL::AddtotheEnd(Account &nv)
{
    if (this->_Quantity == 0)
    {
        this->_DSAccountQL = new Account[this->_Quantity + 1];
        *(this->_DSAccountQL + this->_Quantity) = nv;
    }
    else
    {
        Account *temp = new Account[this->_Quantity];
        for (int i = 0; i < this->_Quantity; i++)
            *(temp + i) = *(this->_DSAccountQL + i);
        delete[] this->_DSAccountQL;
        this->_DSAccountQL = new Account[this->_Quantity + 1];
        for (int i = 0; i < this->_Quantity; i++)
            *(this->_DSAccountQL + i) = *(temp + i);
        delete[] temp;
        *(this->_DSAccountQL + this->_Quantity) = nv;
    }
    this->_Quantity++;
}
int DSAccountQL::FindUsername(int id)
{
    int index = -1;
    for (int i = 0; i < this->_Quantity; i++)
    {
        if ((this->_DSAccountQL + i)->IDNguoiDung() == id)
        {
            index = i;
        }
    }
    return index;
}
string DSAccountQL::GivePass(int index)
{
    return (_DSAccountQL + index)->Password();
}
void DSAccountQL::Update(const int &id)
{
    int index = -(id - 1);
    if (index >= 0)
    {
        cout << "Moi ban nhap password moi: ";
        cin >> (*(this->_DSAccountQL + index));
    }
    else
        cout << "Khong co quan ly co ID: " << id << endl;
}