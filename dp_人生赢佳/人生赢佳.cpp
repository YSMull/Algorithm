#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxN = 5;
int a[maxN+1][maxN+1];
int d[maxN+1];
void solve(int i, int j)//从第i行j列向下枚举结果
{
    if(i < maxN && j < maxN) d[i] = a[i][j];
    if(i == maxN-1)//已经是最底层了
    {
        int sum = 0;
        for(int i = 0; i < maxN; i++){
            sum += d[i];
            //cout<<"d["<<i<<"]="<<d[i]<<" ";
        }
        printf("%d\n", sum);
    }
    else
    {
        if(i >= j)
        {
            solve(i+1,j);
            solve(i+1,j+1);
        }
    }
}
int main()
{
    //freopen("aaa1.txt","r",stdin);
    for(int i =0; i < maxN; i++)
        for(int j = 0; j <= i; j++)
            scanf("%d", &a[i][j]);
    memset(d,0,sizeof(d));
    solve(2,2);
    return 0;
}
