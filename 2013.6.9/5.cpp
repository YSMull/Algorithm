#include <iostream>
#include <iomanip>
using namespace std;
//也许有问题，看跟大家结果是否一样吧
class Pool
{
public:
    double water;
    double solt;
    double concentration;
    double T  = 0.0001;//时间间隔

    Pool(){water = 2000; solt = 2; concentration = solt / water;}
    void update(){water += 2 * T; solt += 6 * T * 0.5 - 4 * T * concentration; concentration = solt / water;}

    void TenMinute() {for(int i = 1; i <= 10 / T; i++) {update();} }
};
int main()
{
    Pool p;
    int i = 1;
    cout<<"时间(min)\t体积(m^3)\t含盐量(kg)\t含盐率(kg/m^3)"<<endl;
    while(p.concentration < 0.2)
    {
        p.TenMinute();

        cout << 10*(i++) << "\t\t" << p.water << "\t\t"
                <<p.solt<< "\t\t" << p.concentration << endl;

    }
}
