//使用并查集实现kruskal最小生成树算法
//-1默认为不连通
#include<cstdio>
#include<cstring>
#include<algorithm>
const int N = 1001;//The Number of Vertex
int p[N];
int findset(int x)//递归写法，其实有更凶残的非递归写法
{
    return p[x] == -1 ? x : p[x] = findset(p[x]);//带路径压缩的查找
}
/*
void unionset(int x, int y)
{
    int fx = findset(x);
    int fy = findset(y);
    if(fx != fy)
        p[x] = y;
}
*/
struct Road
{
    int u, v, w;//u,v表示两个端点的值，w表示路的权
}road[N*N];
bool cmp(Road a, Road b)//仿函数
{
    return a.w < b.w;
}
int main()
{
    int T;scanf("%d", &T);//测试样例数
    while(T--)
    {
        memset(p,-1,sizeof(p));
        int n, m;scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].w);
        }
        std::sort(road,road+m,cmp);//把路按权排序
        memset(p,-1,sizeof(p));//初始化为所有的点都不连通
        int sum = 0;
        for(int i = 0; i < m; i++)
        {
            //union过程
            int t,k;
            t = findset(road[i].u);
            k = findset(road[i].v);
            if(t != k)//如果不连通，否则添加后回成环
            {
                sum += road[i].w;//则添加这条路
                p[t] = k;//union操作
            }
        }
        printf("%d\n", sum);
    }
}
