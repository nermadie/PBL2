#include "QuanLyAll.h"
void DoanhThu::TongDoanhThu_Toanbo()
{
    QLLC tempLich;
    tempLich.TongDoanhThu_Toanbo();
}
void DoanhThu::ThongKePhimAnKhach()
{
    QLLC tempLich;
    cout << "\t\t\t\t\t+======================================================================+" << endl;
    cout << "\t\t\t\t\t|                     ** THONG KE PHIM AN KHACH **                     |" << endl;
    cout << "\t\t\t\t\t+=======================================+==============+===============+" << endl;
    cout << "\t\t\t\t\t|               Ten phim                | So ve da ban |   Doanh thu   |" << endl;
    cout << "\t\t\t\t\t+=======================================+==============+===============+" << endl;
    tempLich.ThongKePhimAnKhach();
    cout << "\t\t\t\t\t+=======================================+==============+===============+" << endl;
}
void DoanhThu::ThongKeKhungGio()
{
    QLLC tempLich;
    cout << "\t\t\t+=========================================================================================================+" << endl;
    cout << "\t\t\t|                                      ** THONG KE THEO KHUNG GIO **                                      |" << endl;
    cout << "\t\t\t+============+==============+===============+===============+======================+======================+" << endl;
    cout << "\t\t\t| Suat chieu | So ve da ban |   Doanh thu   | So suat chieu | So ve ban trung binh | Doanh thu trung binh |" << endl;
    cout << "\t\t\t+============+==============+===============+===============+======================+======================+" << endl;
    tempLich.ThongKeKhungGio();
    cout << "\t\t\t+============+==============+===============+===============+======================+======================+" << endl;
}

void QuanLyNhanVien::DanhSachNhanVien()
{
    QLNV temp;
    temp.Sort();
    temp.Show();
}
void QuanLyNhanVien::ThemNhanVien()
{
    QLNV tempQLNV;
    NhanVien tempNV;
    int ID;
    do
    {
        int check = 1;
        cout << "\t\t\t\t\t\tNhap ID nhan vien: ";
        while (check)
        {
            cin >> ID;
            if (-1 != tempQLNV.IndexOf(ID))
            {
                cout << "\t\t\t\t\t\tDa co nhan vien co ID nay!! Xin moi ban nhap lai: ";
            }
            else
            {
                tempNV.ID(ID);
                check = 0;
                cin >> tempNV;
            }
        }
        if (tempQLNV.AddtotheEnd(tempNV))
        {
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\tBan da nhap sai thong tin nao do! Xin hay kiem tra lai!" << endl;
        }
    } while (1);
}
void QuanLyNhanVien::XoaNhanVien()
{
    QLNV tempQLNV;
    int ID;
    cout << "\t\t\t\t\t\tMoi ban nhap ID nhan vien minh muon xoa: ";
    while (1)
    {
        cin >> ID;
        int tempID = tempQLNV.IndexOf(ID);
        if (-1 != tempID)
        {
            tempQLNV.DeleteatPosition(tempID);
            cout << "\t\t\t\t\t\tDa xoa nhan vien co ID: " << ID << " ra khoi Database!" << endl;
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\tKhong tim thay nhan vien co ID nay! Moi ban nhap lai: ";
        }
    }
}
void QuanLyNhanVien::SuaThongTinNhanVien()
{
    QLNV tempQLNV;
    int ID;
    cout << "\t\t\t\t\t\tMoi ban nhap ID nhan vien minh muon thay doi: ";
    while (1)
    {
        cin >> ID;
        if (-1 != tempQLNV.IndexOf(ID))
        {
            tempQLNV.Update(ID);
            cout << "\t\t\t\t\t\tDa cap nhat thong tin cho nhan vien!  " << endl;
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\tMoi ban nhap lai: ";
        }
    }
}
void QuanLyNhanVien::TimKiemNhanVienTheoID()
{
    QLNV tempQLNV;
    int ID;
    cout << "\t\t\t\t\t\tMoi ban nhap ID nhan vien minh muon xem: ";
    while (1)
    {
        cin >> ID;
        if (-1 != tempQLNV.IndexOf(ID))
        {
            tempQLNV.Show1NV(ID);
            break;
        }
        else
        {
            cout << "\t\t\t\t\t\tKhong tim thay nhan vien co ID nay! Moi ban nhap lai: ";
        }
    }
}