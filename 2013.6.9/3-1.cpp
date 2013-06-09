#include<iostream>
#include<cmath>
using namespace std;
//套公式
void solve(int n)
{
    if(n%2 == 1)
    {
        int T = 1;
        for(int i = 1; i <= floor((n-3)/6)*2+1; i++)
            T *= 3;
        for(int i = 1; i <= floor((n-3)%6)/2; i++)
            T *= 2;
        cout << "2^" << floor((n-3)%6)/2 << "*3^" << floor((n-3)/6)*2+1 << "=" << T <<endl;
    }
    else
    {
        int T = 1;
        for(int i = 1; i <= floor(n/6)*2; i++)
            T *= 3;
        for(int i = 1; i <= floor(n%6)/2; i++)
            T *= 2;
        cout << "2^" << floor(n%6)/2 << "*3^" << floor(n/6)*2 << "=" << T <<endl;
    }
}
int main()
{
    int a;
    while(cin>>a)
    {
        solve(a);
    }
}
