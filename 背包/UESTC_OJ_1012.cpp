#include<cstdio>
#include<algorithm>
#include<cstring>
int Price[1010], money, n, dp[1010][1010];
int solve(int cur, int ss)//当前在买第cur道菜，卡里还剩ss元钱,最多能花的钱数
{
    int res;
    if(dp[cur][ss] != -1) return dp[cur][ss];
    if(cur == n - 1)
        res = 0;
    else if(ss < Price[cur])
        res = solve(cur+1,ss);
    else
        res = std::max(solve(cur+1,ss), solve(cur+1, ss-Price[cur]) + Price[cur]);
    return dp[cur][ss] = res;
}
int main()
{
    //freopen("aaa.txt", "r", stdin);
    while(1)
    {
        memset(dp, -1, sizeof(dp));
        memset(Price, 0, sizeof(Price));
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &Price[i]);
        }
        std::sort(Price, Price+n);
        int _Max = Price[n-1];
        scanf("%d", &money);if(money < 5) {printf("%d\n", money);continue;}
        int m = money-5;//减去5元之后跑背包，尽可能把卡里的钱花掉
        int res = money - solve(0, m) - _Max;
        printf("%d\n", res);
    }

    return 0;
}

