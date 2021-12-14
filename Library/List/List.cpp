#include "List.h"
#include <assert.h>
#include <iostream>
using namespace std;
template <class T>
List<T>::List() : length(0), data(nullptr)
{
}
template <class T>
List<T>::List(int length) : length(length)
{
    assert(this->length >= 0);
    if (length > 0)
        this->data = new int[this->length];
    else
        this->data = nullptr;
}
template <class T>
List<T>::~List()
{
    delete[] this->data;
}
template <class T>
void List<T>::Erase()
{
    delete[] this->data;
    this->data = nullptr;
    this->length = 0;
}
template <class T>
int &List<T>::operator[](int index)
{
    assert(index >= 0 && index < this->length);
    return this->data[index];
}
template <class T>
int List<T>::GetLength() const
{
    return this->length;
}
template <class T>
void List<T>::Reallocate(int newLength)
{
    Erase();
    if (newLength <= 0)
        return;
    this->data = new int[newLength];
    this->length = newLength;
}
template <class T>
void List<T>::Resize(int newLength)
{
    if (newLength == this->length)
        return;
    if (newLength <= 0)
    {
        Erase();
        return;
    }
    int *data = new int[newLength];
    if (this->length > 0)
    {
        int maxlength = (newLength > this->length) ? this->length : newLength;
        for (int i = 0; i < maxlength; ++i)
            data[i] = (*this)[i];
    }
    delete[] this->data;
    this->data = data;
    this->length = newLength;
}
template <class T>
void List<T>::Insert(int value, int index)
{
    assert(index >= 0 && index <= this->length);
    int *data = new int[this->length + 1];
    for (int i = 0; i < index; i++)
        data[i] = (*this)[i];
    data[index] = value;
    for (int j = index; j < this->length; j++)
        data[j + 1] = (*this)[j];
    delete[] this->data;
    this->data = data;
    ++this->length;
}
template <class T>
void List<T>::Remove(int index)
{
    assert(index >= 0 && index < this->length);
    if (this->length == 1)
    {
        Erase();
        return;
    }
    int *data = new int[this->length - 1];
    for (int i = 0; i < index; i++)
        data[i] = (*this)[i];
    for (int j = index + 1; j < this->length; j++)
        data[j] = (*this)[j];
    delete[] this->data;
    this->data = data;
    --(this->length);
}
template <class T>
void List<T>::InsertFirst(int value)
{
    Insert(value, 0);
}
template <class T>
void List<T>::InsertLast(int value)
{
    Insert(value, this->length);
}