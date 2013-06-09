#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double E = 2.71828182846;
int main()
{
    //不动点法
    auto f = [](double x){return pow(E, -x);};
    double x = 0.0, _old_ = 0, _new_, eps;
    do
    {
        _new_ = x = f(x);
        eps = abs(_old_ - _new_);
        _old_ = _new_;
    }while(eps > 0.0001);
    cout<<x<<endl;
}
