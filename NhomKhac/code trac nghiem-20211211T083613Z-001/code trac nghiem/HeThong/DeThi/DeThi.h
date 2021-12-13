#include <iostream>
using namespace std;

class DeThi {
    private:
        int soCau;
        string id;
        string* cauHoi;
        string* dapAnA;
        string* dapAnB;
        string* dapAnC;
        string* dapAnD;
        char* dapAn; // A B C D
    public:
        DeThi();
        DeThi(int, string, string*, string*, string*, string*, string*, char*);
        ~DeThi();

        //get-set
        
        int getSoCau();
        string getId();
        string* getCauHoi();
        string* getDapAnA();
        string* getDapAnB();
        string* getDapAnC();
        string* getDapAnD();
        char* getDapAn();

        string getCauHoi(int);
        string getDapAnA(int);
        string getDapAnB(int);
        string getDapAnC(int);
        string getDapAnD(int);
        char getDapAn(int);

        void setCauHoi(string*);
        void setDapAnA(string*);
        void setDapAnB(string*);
        void setDapAnC(string*);
        void setDapAnD(string*);
        void setDapAn(char*);

        void setCauHoi(string, int);
        void setDapAnA(string, int);
        void setDapAnB(string, int);
        void setDapAnC(string, int);
        void setDapAnD(string, int);
        void setDapAn(char, int);
};