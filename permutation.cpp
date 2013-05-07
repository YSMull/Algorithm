/*
产生某个集合元素的全排列
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
const int max_N = 100;
void permutation(int n, char *a, char *d, int cur)//其实就是个深度优先搜索
{
    if(cur == n)
    {
        for(int i = 0; i < n; i++)
            printf("%c ", d[i]);
        printf("\n");
    }
    else
    {
        for(int i = 0; i < n; i++) if(a[i] != a[i+1]) //否则就重复递归了，结果会重复
                                                        //注意如果a是数组，那么如果a[0] = 0,则无法进入递归，
                                                        //因此要改为if(!i || a[i] != a[i-1]
        {
            int c1 = 0, c2 = 0;
            for(int j = 0; j < cur; j++) if(d[j] == a[i]) c1++;//统计结果数组中a[i]出现的次数
            for(int j = 0; j < n; j++) if(a[j] == a[i]) c2++;//统计集合中a[i]出现的次数
            if(c1 < c2)
            {
                d[cur] = a[i];
                permutation(n, a, d, cur+1);
            }
        }
    }
}
int main()
{
    char a[max_N];
    char d[max_N];
    scanf("%s", a);
    std::sort(a,a+strlen(a));//为了字典序，因此将集合元素排序
    permutation(strlen(a),a,d,0);//从第0层开始
    return 0;
}
