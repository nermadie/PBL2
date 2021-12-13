#include <iostream>
#include "./MucLuc/TrangGiaoVien.cpp"
#include "./MucLuc/TrangHocSinh.cpp"
using namespace std;

int main()
{    
	system("cls");
    cout << endl;
	printLineColor("\t\t\t\t\t          DO AN CO SO LAP TRINH ", 6);                                       cout << endl;
	printLineColor("\t\t               ==========================================================", 7);    cout << endl; 
	printLineColor("\t\t               De tai: HE THONG THI TRAC NGHIEM", 7);                              cout << endl;
	printLineColor("\t\t               Giao vien huong dan: MAI VAN HA", 7);                               cout << endl;
	printLineColor("\t\t               Ho ten sinh vien 1: TRAN THI NGOC TRAM"  "    Lop: 20TCLC_DT2", 7); cout << endl;
	printLineColor("\t\t               Ho ten sinh vien 2: NGUYEN THANH HOANG"  "    Lop: 20TCLC_DT5", 7); cout << endl;
	printLineColor("\t\t               Nhom: 20.11", 7);                                                   cout << endl; 
	printLineColor("\t\t               ==========================================================", 7);    cout << endl;
	cout << endl;  
    cout << "\t\t\t\t      *********************************************"            << endl; 
    cout << "\t\t\t                  CHUONG TRINH HE THONG THI TRAC NGHIEM          "<< endl;
    cout << "\t\t\t\t      *********************************************"            << endl; 
    while(true)
    {
        printLineColor("\t\t\t\t              _____________________________ ", 10); cout << endl;
	    printLineColor("\t\t\t\t             |                             |", 10); cout << endl;
	    printLineColor("\t\t\t\t             |       TRANG DANG NHAP       |", 10); cout << endl;
	    printLineColor("\t\t\t\t             |_____________________________|", 10); cout << endl;   
        User x = DangNhap();

        if (kiemTraId("./CoSoDuLieu/HocSinh/HocSinh_id.txt", x.getId()) == true)
        {
            x.setChucVu(0);
            TrangHocSinh::HienThi(x.getId());
        } 
        else 
        {
            x.setChucVu(1);
            TrangGiaoVien::HienThi(x.getId());
        }
    }
}