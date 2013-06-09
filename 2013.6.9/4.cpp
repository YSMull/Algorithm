#include<iostream>
using namespace std;
//这题可能可以用动态规划，我这个方法暴搜只适用于小数据情形
int d[5], vis[5];
struct person
{
    float price[5];
    void init(float i1, float i2, float i3, float i4)
    {
        price[1] = i1; price[2] = i2;
        price[3] = i3; price[4] = i4;
    }
}P[5];
float _max_ = 0;
void dfs(int l, int depth)//其实是个深度优先搜索
{
    if(l == depth)
    {
        float sum = 0.0;
        for(int i = 0; i < depth; i++)
            sum += P[i].price[d[i]];
        if(sum >= _max_)
        {
            _max_ = sum;


            /*将就着先这么搞吧*/
            cout<<"当前最优结果为:"<<endl;
            for(int i = 0; i < depth; i++)
            {
                cout<<"第"<<i+1<<"个人买第"<<d[i]<<"件名画"<<endl;
            }
            cout<<sum<<endl;
        }
    }
    else
    {
        for(int i = 1; i <= depth; i++)
        {
            if(vis[i]) continue;
            vis[i] = 1;
            d[l] = i;
            dfs(l+1, depth);
            vis[i] = 0;
        }
    }
}
int main()
{
//  每个人买每件物品能支付的价格
    P[0].init(13.5  ,   8.5 ,   20  ,   14);
    P[1].init(14    ,   7   ,   19  ,   13);
    P[2].init(17    ,   5   ,   20  ,   16);
    P[3].init(15    ,   6.5 ,   21  ,   13.5);
    dfs(0,4);
}
