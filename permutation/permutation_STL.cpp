#include<cstdio>
#include<algorithm>
#include<cstring>
int main()
{
    char a[100];
    scanf("%s", a);
    int n = strlen(a);
    std::sort(a,a+n);
    do
    {
        for(int i = 0; i < n; i++)
            printf("%c ", a[i]);
        printf("\n");
    }while(std::next_permutation(a,a+n));
    return 0;
}
