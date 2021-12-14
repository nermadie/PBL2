#include "List.cpp"
int main()
{
    List arr(10);
    cout << arr;
    for (int i = 0; i < 10; i++)
        arr[i] = i + 1;
    cout << arr;
    arr.Resize(8);
    cout << arr;
    arr.Insert(0, 5);
    cout << arr;
    arr.Remove(8);
    cout << arr;
    arr.InsertFirst(0);
    cout << arr;
    arr.InsertLast(8);
    cout << arr;
    return 0;
}