// #include "QLP.h"

// bool GD(int a, int b)
// {
//     return a < b;
// }
// bool TD(int a, int b)
// {
//     return a > b;
// }

// QLP::QLP()
// {
//     this->_QLP = nullptr;
//     this->_Quantity = 0;
// }

// QLP::QLP(Film *_QLP, int _Quantity) : _QLP(_QLP), _Quantity(_Quantity) {}

// QLP::QLP(const QLP &f)
// {
//     this->_QLP = f._QLP;
//     this->_Quantity = f._Quantity;
// }

// QLP::~QLP()
// {
//     delete[] this->_QLP;
// }

// void QLP::Show()
// {
//     cout << "Danh Sach Phim:" << endl;
//     for (int i = 0; i < this->_Quantity; i++)
//         _QLP[i].ShowPhim();
// }

// // Them doi tuong-------------------------------------------------
// //  + Them vao cuoi danh sach
// void QLP::AddtotheEnd(const Film &f)
// {
//     if (this->_Quantity == 0)
//     {
//         this->_QLP = new Film[this->_Quantity + 1];
//         *(this->_QLP + this->_Quantity) = f;
//     }
//     else
//     {
//         Film *temp = new Film[this->_Quantity];
//         for (int i = 0; i < this->_Quantity; i++)
//             *(temp + i) = *(this->_QLP + i);
//         delete[] this->_QLP;
//         this->_QLP = new Film[this->_Quantity + 1];
//         for (int i = 0; i < this->_Quantity; i++)
//             *(this->_QLP + i) = *(temp + i);
//         delete[] temp;
//         *(this->_QLP + this->_Quantity) = f;
//     }
//     this->_Quantity++;
// }
// //  + Them vao dau danh sach
// void QLP::AddtoTop(const Film &f)
// {
//     if (this->_Quantity == 0)
//     {
//         this->_QLP = new Film[this->_Quantity + 1];
//         *(this->_QLP + this->_Quantity) = f;
//     }
//     else
//     {
//         Film *temp = new Film[this->_Quantity];
//         for (int i = 0; i < this->_Quantity; i++)
//             *(temp + i) = *(this->_QLP + i);
//         delete[] this->_QLP;
//         this->_QLP = new Film[this->_Quantity + 1];
//         for (int i = 1; i <= this->_Quantity; i++)
//             *(this->_QLP + i) = *(temp + i - 1);
//         delete[] temp;
//         *(this->_QLP) = f;
//     }
//     this->_Quantity++;
// }
// //+ Them vao vi tri bat ky
// void QLP::AddtoPosition(const Film &f, int position)
// {
//     if (this->_Quantity == 0)
//     {
//         if (position > 0 || position < 0)
//             cout << "Loi vi tri!" << endl; // Vi tri>_Quantity hoac Vi tri<0
//         else
//         {
//             this->_QLP = new Film[this->_Quantity + 1];
//             *(this->_QLP + this->_Quantity) = f;
//             this->_Quantity++;
//         }
//     }
//     else
//     {
//         if (position > _Quantity || position < 0)
//             cout << "Loi vi tri!" << endl; // Vi tri >_Quantity hoac Vi tri<0
//         else
//         {
//             Film *temp = new Film[this->_Quantity];
//             for (int i = 0; i < this->_Quantity; i++)
//                 *(temp + i) = *(this->_QLP + i);
//             delete[] this->_QLP;
//             this->_QLP = new Film[this->_Quantity + 1];
//             for (int i = 0; i < position; i++)
//                 *(this->_QLP + i) = *(temp + i);
//             for (int i = position + 1; i <= this->_Quantity; i++)
//                 *(this->_QLP + i) = *(temp + i - 1);
//             delete[] temp;
//             *(this->_QLP + position) = f;
//             this->_Quantity++;
//         }
//     }
// }

// // Xoa doi tuong---------------------------------------------------------
// //  + Xoa doi tuong dau tien
// void QLP::DeleteTop()
// {
//     int index = 0;
//     if (this->_Quantity == 1)
//     {
//         delete[] this->_QLP;
//     }
//     else
//     {
//         Film *temp = new Film[this->_Quantity];
//         for (int i = 0; i < this->_Quantity; i++)
//             *(temp + i) = *(this->_QLP + i);
//         delete[] this->_QLP;
//         this->_QLP = new Film[this->_Quantity - 1];
//         for (int i = 0; i < this->_Quantity - 1; i++)
//         {
//             if (i < index)
//             {
//                 *(this->_QLP + i) = *(temp + i);
//             }
//             else
//             {
//                 *(this->_QLP + i) = *(temp + i + 1);
//             }
//         }
//     }
//     this->_Quantity--;
// }
// //  + Xoa doi tuong cuoi cung
// void QLP::DeleteEnd()
// {
//     int index = _Quantity - 1;
//     if (this->_Quantity == 1)
//     {
//         delete[] this->_QLP;
//     }
//     else
//     {
//         Film *temp = new Film[this->_Quantity];
//         for (int i = 0; i < this->_Quantity; i++)
//             *(temp + i) = *(this->_QLP + i);
//         delete[] this->_QLP;
//         this->_QLP = new Film[this->_Quantity - 1];
//         for (int i = 0; i < this->_Quantity - 1; i++)
//         {
//             if (i < index)
//             {
//                 *(this->_QLP + i) = *(temp + i);
//             }
//             else
//             {
//                 *(this->_QLP + i) = *(temp + i + 1);
//             }
//         }
//     }
//     this->_Quantity--;
// }
// //  + Xoa tai vi tri k bat ky
// void QLP::DeleteatPosition(const int &position)
// {
//     int index = position;
//     if (this->_Quantity == 1)
//     {
//         delete[] this->_QLP;
//     }
//     else
//     {
//         Film *temp = new Film[this->_Quantity];
//         for (int i = 0; i < this->_Quantity; i++)
//             *(temp + i) = *(this->_QLP + i);
//         delete[] this->_QLP;
//         this->_QLP = new Film[this->_Quantity - 1];
//         for (int i = 0; i < this->_Quantity - 1; i++)
//         {
//             if (i < index)
//             {
//                 *(this->_QLP + i) = *(temp + i);
//             }
//             else
//             {
//                 *(this->_QLP + i) = *(temp + i + 1);
//             }
//         }
//     }
//     this->_Quantity--;
// }

// // Tim kiem(BinarySearch)-----------------------------------
// //  + Tim Index tuong ung voi ID
// int QLP::BinarySearch(int l, int r, int id) // Vi ID chua sort nen xet ca 2 phia
// {
//     if (r >= l)
//     {
//         int mid = l + (r - l) / 2;
//         if ((this->_QLP + mid)->IDP() == id)
//             return mid;
//         int A = BinarySearch(l, mid - 1, id);
//         int B = BinarySearch(mid + 1, r, id);
//         if (A != -1)
//             return A;
//         else if (B != -1)
//             return B;
//         else
//             return -1;
//     }
//     return -1;
// }

// // Tim kiem(BinarySearch)-----------------------------------
// //+ Tim Index tuong ung voi ID

// int QLP::IndexOf(int id)
// {
//     return BinarySearch(0, _Quantity - 1, id);
// }

// // Sap xep(InsertionSort) voi thuoc tinh _ID----------------
// // Ham TD và GD đã được định nghĩa ở phía bên trên cùng
// void QLP::Sort(bool (*CTH)(int a, int b) = TD)
// {
//     int *tempIndex = new int[_Quantity];
//     for (int i = 0; i < _Quantity; i++)
//         *(tempIndex + i) = i; // Mang index
//     int i, j;
//     for (i = 1; i < _Quantity; i++)
//     {
//         j = i - 1;
//         while (j >= 0 && CTH((this->_QLP + j)->IDP(), (this->_QLP + i)->IDP()))
//         {
//             tempIndex[j + 1] = tempIndex[j];
//             j--;
//         }
//         tempIndex[j + 1] = i;
//     }
//     Film *temp = new Film[this->_Quantity];
//     for (int i = 0; i < this->_Quantity; i++)
//         *(temp + i) = *(this->_QLP + i);
//     for (int i = 0; i < this->_Quantity; i++)
//         *(this->_QLP + i) = *(temp + *(tempIndex + i));
//     delete[] temp;
// }