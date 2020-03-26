
using namespace std;
class Money {
private:
    int rub;
    int kop;
    int kop1;
    int rub1;
    int r;
    int k;
public:
    Money(int,int,int,int) {
        rub = 0; kop = 0; r = 0; k = 0;
    }
    friend Money operator+(const Money& k, const Money& n);
    void Money::Input_money();
    void Money::Output_money();
    friend Money operator*(const Money& s, int n);
    friend Money operator==(const Money& s, const Money& s1);
    friend Money operator/(const Money& s, int n);
   

};
