#include <iostream>
#include <fstream>
using namespace std;
#include <windows.h>
#include <iomanip>


void TextColor(int x){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute( color , x );
}
void InLine(int n){
    for (int i = 0; i < n; i++) 
        cout<<"=";
}

void menuchinh()
{
    system ("cls"); TextColor(14);
    cout<<"\n\n\t\t\t\t\t\t\t\t-MENU-"; TextColor(7);
    cout<<"\n\t\t\t\t\t\t _____________________________________";
    cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
    cout<<"\n\t\t\t\t\t\t|"<<"\t       1.Nhan vien            |";
    cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
    cout<<"\n\t\t\t\t\t\t|"<<"\t       2.Phim                 |";
	cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
	cout<<"\n\t\t\t\t\t\t|"<<"\t       3.Thoat                |";
	cout<<"\n\t\t\t\t\t\t|"<<"\t                              |";
    cout<<"\n\t\t\t\t\t\t|_____________________________________|";
}

void menuNhanVien()
{
    system("cls");TextColor(14);
	        cout<<"\n\n\t\t\t\t\t\t     -NHAN VIEN-"; TextColor(7);
		    cout<<"\n\t\t\t _______________________________________________________________________";
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                1.Hien Thi Danh Sach Nhan Vien         \t\t|";
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
            cout<<"\n\t\t\t|"<<"                2.Them Nhan Vien vao dau danh sach     \t\t|";
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                3.Them nhan vien vao cuoi danh sach    \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
		    cout<<"\n\t\t\t|"<<"                4.Them nhan vien vao vi tri bat ki     \t\t|";
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                5.Xoa nhan vien o dau danh sach        \t\t|";       
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                6.Xoa nhan vien o cuoi danh sach       \t\t|";       
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                7.Xoa nhan vien o vi tri bat ki        \t\t|";  
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                8.Thay doi thong tin nhan vien theo ID \t\t|";  
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                9.Tim kiem nhan vien theo ID           \t\t|";       
		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                10.Quay Lai                            \t\t|";       
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
		    cout<<"\n\t\t\t|"<<"                11.Thoat                               \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
		    cout<<"\n\t\t\t|_______________________________________________________________________|";
}

void MenuPhim()
{
            cout<<"\n\n\t\t\t\t\t\t     -NHAN VIEN-"; TextColor(7);
		    cout<<"\n\t\t\t _______________________________________________________________________";
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                1.Hien Thi Danh Sach Phim              \t\t|";
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
            cout<<"\n\t\t\t|"<<"                2.Them Phim vao dau danh sach          \t\t|";
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                3.Them Phim vao cuoi danh sach         \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
		    cout<<"\n\t\t\t|"<<"                4.Them Phim vao vi tri bat ki          \t\t|";
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                5.Xoa Phim o dau danh sach             \t\t|";       
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                6.Xoa Phim o cuoi danh sach            \t\t|";       
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                7.Xoa Phim o vi tri bat ki             \t\t|";  
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                8.Thay doi thong tin Phim theo IDP     \t\t|";  
            cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                9.Tim kiem Phim theo IDP               \t\t|";       
		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
	        cout<<"\n\t\t\t|"<<"                10.Quay Lai                            \t\t|";       
	        cout<<"\n\t\t\t|"<<"                                                       \t\t|";
		    cout<<"\n\t\t\t|"<<"                11.Thoat                               \t\t|";
		    cout<<"\n\t\t\t|"<<"                                                       \t\t|";
		    cout<<"\n\t\t\t|_______________________________________________________________________|";
}

void menu()
{
    Menu: 
    menuchinh();
    int chon;
    cout << "\n\n\t\t\t\t\t\tNhap lua chon :"; 
    cin >> chon;
    while(chon < 0 || chon > 3)
    {
        cout << "\n\n\t\t\t\t\t\tNhap lua chon :"; 
        cin >> chon;   
    }
    switch (chon)
    {
        case 1:
        {
            system ("cls");
            Nhanvien:
            menuNhanVien();
            int a;
            cout<<"\n\n\t\t\tNhap lua chon :"; 
            cin >> a;
            while (a < 0||a > 11)
            {
                cout << "\n\n\t\t\tNhap lua chon :";
                cin >> a; 
            }
            switch (a)
            {
            case 1:
                system ("cls");
                cout << "Hien thi thong tin Nhan vien";
                system ("pause");
                goto Nhanvien; 
                break;
            case 2:
                system("cls");
                cout << "Them dau";
                system ("pause");
                goto Nhanvien;
                break;
            case 3: 
                system("cls");
                cout << "Them cuoi";
                system ("pause");
                goto Nhanvien;
                break;
            case 4:
                system("cls");
                cout << "Them bat ki";
                system ("pause");
                goto Nhanvien;
                break;
            case 5:
                system("cls");
                cout << "Xoa dau";
                system ("pause");
                goto Nhanvien;
                break;
            case 6:
                system("cls");
                cout << "Xoa cuoi";
                system ("pause");
                goto Nhanvien;
                break;
            case 7: 
                system("cls");
                cout << "Xoa bat ki";
                system ("pause");
                goto Nhanvien;
                break;
            case 8:
                system("cls");
                cout << "Thay doi";
                system ("pause");
                goto Nhanvien;
                break;
            case 9:
                system("cls");
                cout << "Tim kiem";
                system ("pause");
                goto Nhanvien;
                break;
            case 10:
                goto Menu;
                break;
            case 11:
                exit(0);
                break;
            }
        }
        case 2:
        {
            system ("cls");
            Phim:
            MenuPhim();
            int b;
            cout<<"\n\n\t\t\t\tNhap lua chon :";
            cin >> b;
            while(b < 0 || b > 11)
            {
                cout<<"\n\n\t\t\t\tNhap lua chon :";
                cin >> b ;
            }
            switch (b)
            {
            case 1:
                system ("cls");
                cout << "Hien thi thong tin Phim";
                system ("pause");
                goto Phim; 
                break;
            case 2:
                system("cls");
                cout << "Them dau";
                system ("pause");
                goto Phim;
                break;
            case 3: 
                system("cls");
                cout << "Them cuoi";
                system ("pause");
                goto Phim;
                break;
            case 4:
                system("cls");
                cout << "Them bat ki";
                system ("pause");
                goto Phim;
                break;
            case 5:
                system("cls");
                cout << "Xoa dau";
                system ("pause");
                goto Phim;
                break;
            case 6:
                system("cls");
                cout << "Xoa cuoi";
                system ("pause");
                goto Phim;
                break;
            case 7: 
                system("cls");
                cout << "Xoa bat ki";
                system ("pause");
                goto Phim;
                break;
            case 8:
                system("cls");
                cout << "Thay doi";
                system ("pause");
                goto Phim;
                break;
            case 9:
                system("cls");
                cout << "Tim kiem";
                system ("pause");
                goto Phim;
                break;
            case 10:
                goto Menu;
                break;
            case 11:
                exit(0);
                break;
            }

        }
        case 3:
        exit(0);
        break;
    }
}

int main()
{
	system("cls");
    TextColor (14);
	cout << ("\t\t\t\t\t          DO AN CO SO LAP TRINH ");                                       cout << endl;
	cout << ("\t\t               ==========================================================");    cout << endl; 
	cout <<("\t\t               De tai: QUAN LY RAP CHIEU PHIM");                              cout << endl;
	cout << ("\t\t               Giao vien huong dan: Phan Thanh Tao");                               cout << endl;
	cout << ("\t\t               Ho ten sinh vien 1: Nguyen Duc Manh"  "    Lop: 20TCLC_Nhat1"); cout << endl;
	cout << ("\t\t               Ho ten sinh vien 2: Tran Nhat Minh"  "    Lop: 20TCLC_Nhat1"); cout << endl;
	cout << ("\t\t               Nhom: 20.11");                                                   cout << endl; 
	cout << ("\t\t               ==========================================================");    cout << endl;
	cout << endl;  
    cout << "\t\t\t\t      *********************************************"            << endl; 
    cout << "\t\t\t                  CHUONG TRINH QUAN LY RAP CHIEU PHIM          "<< endl;
    cout << "\t\t\t\t      *********************************************"            << endl; 
    menu();
    return 0;
}