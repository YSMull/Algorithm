#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 100;///这里有bug- -，将10000改成1000或100,输出会遇到问题
void init(char*, const string);//初始化字符串数组，逆序排列方便进位
void add(char*, char*, char*);//高精度加法
void Bmult(char*, int, char*);//一个数乘以一个数字的高精度运算(for mult())
void rightmv(char *, int);//将数组左移动，并在前方添零(for mult())
void mult(char*, char*, char*);//高精度乘法
void Display(char *);

int main()
{
    char s[MAXN], t[MAXN];
    char res[MAXN];
    string ss,tt;
    while(cin>>ss>>tt)
    {
        memset(s, 0, sizeof(s));
        memset(t, 0, sizeof(t));
        memset(res, 0, sizeof(res));
        init(s,ss);init(t,tt);
        mult(s,t,res);
        Display(res);
    }
}

void init(char *s, string ss)
{
    int len = ss.length();
    for(int i = 0; i < len; i++)
        s[i] = ss[len-i-1];
}

void add(char *s, char *t, char *res)
{
    int slen = strlen(s), tlen = strlen(t);
    char ss[MAXN],tt[MAXN];
    for(int i = 0; i < slen; i++)
        ss[i] = s[i];
    for(int i = 0; i < tlen; i++)
        tt[i] = t[i];
    //memset(res,0,sizeof(res));
    for(int i = 0,g = 0; g || i < max(slen, tlen); i++)//g为进位数，条件保证在求完最后一位时，如果有进位，则继续运算
    {
        int x = g;
        if(i < slen) x += ss[i]-'0';
        if(i < tlen) x += tt[i]-'0';
        res[i] = x % 10 + 48;
        g = x / 10;
    }
}
void Bmult(char *s, int m, char *res)
{
    //memset(res,0,sizeof(res));
    int slen = strlen(s);
    for(int i = 0, g = 0; g || i < slen; i++)
    {
        int x = g;
        if(i < slen) x += (s[i]-'0') * m;
        res[i] = x % 10 + 48;
        g = x / 10;
    }
}
void rightmv(char *data, int n)
{
    int dlen = strlen(data);
    for(int i = 0; i < dlen; i++)
    {
        data[dlen-i-1+n] = data[dlen-i-1];
    }
    for(int i = 0; i < n; i++)
    {
        data[i] = '0';
    }
}
void mult(char *s, char *t, char *res)
{
    char c1[MAXN];
    int tlen = strlen(t);
    for(int i = 0; i < tlen; i++)
    {
        Bmult(s,t[i]-'0',c1);//竖式中的第i行数c1
        rightmv(c1,i);//给这行数字的尾巴上添0(由于是逆序存储的，所以要先向右移动，再在前端添零)
        //Display(c1);
        add(c1,res,res);//means res+=c1;
        memset(c1,0,sizeof(c1));//清空c1供下次使用
        //Display(res);
    }
}
void Display(char *res)
{
    int rlen = strlen(res);
    //cout<<rlen<<endl;
    for(int i = rlen-1; i >= 0; i--)
        cout<<(char)res[i]-'0';
    cout<<endl;
}
