#pragma once
#include "Register.h"
#include <fstream>

void Register::NhapThongTinKhachHang()
{
    KhachHang tempKH;
    cin >> tempKH;
    QLKH tempQLKH;
    int newID = tempQLKH.Quantity() + 1;
    tempKH.ID(newID);
    DSAccount tempDSAcc;
    Account tempAcc(newID, "");
    tempDSAcc.AddtotheEnd(tempAcc);
    tempDSAcc.Update(newID);
    tempQLKH.AddtotheEnd(tempKH);
    string Path = "./Database/MuaVe/KH" + to_string(newID) + ".txt";
    ofstream FileOut(Path);
    FileOut.close();
    cout << endl
         << "Tu bay gio ban co the dang nhap voi username(ID): " << newID << " va password ban vua tao!";
}
