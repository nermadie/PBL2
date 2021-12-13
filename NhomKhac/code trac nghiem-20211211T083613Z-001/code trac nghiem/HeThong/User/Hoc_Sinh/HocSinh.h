#include "../User.cpp"

class HocSinh : public User 
{
    private:
        User info;
    public:
        HocSinh();
        HocSinh(string id, string ten, int tuoi, bool gioiTinh, string matKhau);
        HocSinh(const HocSinh&);
        ~HocSinh();
};
