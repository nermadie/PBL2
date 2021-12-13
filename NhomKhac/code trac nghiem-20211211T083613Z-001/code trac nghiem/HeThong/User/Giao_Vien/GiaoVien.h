#include "../User.h"

class GiaoVien : public User 
{
    public:
        GiaoVien();
        GiaoVien(string id, string ten, int tuoi, bool gioiTinh, string matKhau);
        GiaoVien(const GiaoVien&);
        ~GiaoVien();

};
