template <class T>
class List
{
private:
    int length;
    T *data;

public:
    List();
    List(int); // So phan tu cua mang ->length
    ~List();
    void Erase();
    int &operator[](int);
    int GetLength() const;
    void Reallocate(int); // fast
    void Resize(int);     // slow
    void Insert(int, int);
    void Remove(int);
    void InsertFirst(int);
    void InsertLast(int);
};
