#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double E = 2.71828182846;
int main()
{
    //二分法
    double x = 0.0, y = 2.0, z;
    double _old_ = 0.0, eps;
    auto f = [](double x){return pow(E, -x) - x;};
    do
    {
        z = (x +y) / 2;
        double _new_ = f(z);
        eps = abs(_new_ - _old_);
        if(_new_ < 0) y = z;
        else x = z;
    }while(eps >= 0.0001);
    cout<<setprecision(5)<<z<<endl;
}
