#include <iostream>
using namespace std;
void solve(int h)
{
    for(int H = 1; H <= h; H++)
    {
        for(int E = 1; E <= H/6; E++)
        {
            int A = H - 6 * E;
            int B = H - 2 * A;
            if(B <= 0) continue;
            int C = H - 3 * B;
            if(C <= 0) continue;
            int D = H - 4 * C;
            if(D <= 0) continue;
            if(H == E + 5 * D)
            {
                cout<<"A家绳长:"<<A<<"\nB家绳长:"<<B<<"\nC家绳长:"
                    <<C<<"\nD家绳长:"<<D<<"\nE家绳长:"<<E<<"\n井深:"<<h<<endl;
            }
        }
    }
}
int main()
{
    solve(1000);//井深小于1000的解
    return 0;
}
