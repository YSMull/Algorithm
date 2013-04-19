#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>//为了setpricision使能显示的位数变多些
#include<sstream>
using namespace std;
class BaseTool
{
public:
    static char a[100],*p;//定义静态变量a和字符指针p，a用来存储用户从键盘输入的字符串
    static char *head;//相当于全局指针，存储字符串a的头指针
    static string s[100];//存储处理后的字符串，便于核心函数递归调用
    BaseTool() {}
    string NumToString(const double &x);//工具：将数字转化为string字符串
    double StringToNum(const string &s);//工具：将string字符串转化为数字
    int strN(string ss[]);//统计string数组中有多少个有效元素（不为空的位置的个数）
    void CharToString();/**核心函数,处理用户输入的char型a[100]，将其转化为string存在s[100]中*/
    static long long gcd(long long a,long long b);//for rational::youhua() 计算最大公约数
private:
    static double getNextNum(char *);//for CharToString()
    static string getNextOperator(char *);//for CharToString()
};
//初始化静态成员
char BaseTool::a[100];
char* BaseTool::p=a;
char* BaseTool::head=a;
string BaseTool::s[100];

string BaseTool::NumToString(const double &x)
{
    ostringstream o;
    if(o << x)
        return o.str();
    return "conversion error";//if error
}
double BaseTool::StringToNum(const string &s)
{
    istringstream i(s);
    double x;
    if(i >> x)
        return x;
    return 0.0;//if error
}
int BaseTool::strN(string ss[])
{
    int k=0;
    for(int i=0; i<=99; i++)
    {
        if(ss[i]!="\0")
            k++;
    }
    return k;
}
void BaseTool::CharToString()
{
    //使指针p指向char头部
    BaseTool::head=BaseTool::a;
    BaseTool::p=BaseTool::a;
    for(int i=0; i<=99; i++)//清空s
        BaseTool::s[i]="\0";

    //开始chartostring
    int k=0;
    while(*p!='\0')
    {
        while(*p==')'||*p=='+'||*p=='*'||*p=='/')
        {
            s[k++]=getNextOperator(p);
        }
        if(*p=='\0')
            break;
        while(*p=='(')
        {
            s[k++]=getNextOperator(p);
            if(*p=='\0')
                break;
            if(*p=='-')
            {
                s[k++]=NumToString(-getNextNum(p));
                break;
            }
        }

        if(*p=='\0')
            break;
        while(*p==')'||*p=='+'||*p=='*'||*p=='/')
        {
            s[k++]=getNextOperator(p);
        }
        if(*p=='\0')
            break;
        if(*p=='-')
        {
            s[k++]=getNextOperator(p);
        }
        if(*p=='\0')
            break;
        while(*p=='(')
        {
            s[k++]=getNextOperator(p);
            if(*p=='\0')
                break;
            if(*p=='-')
            {
                s[k++]=NumToString(-getNextNum(p));
                break;
            }
        }
        if(*p=='\0')
            break;
        while(*p==')'||*p=='+'||*p=='*'||*p=='/')
        {
            s[k++]=getNextOperator(p);
        }
        if(*p=='\0')
            break;
        if(*p=='-')
        {
            s[k++]=getNextOperator(p);
        }
        if(*p=='\0')
            break;
        while(*p=='(')
        {
            s[k++]=getNextOperator(p);
            if(*p=='\0')
                break;
            if(*p=='-')
            {
                s[k++]=NumToString(-getNextNum(p));
                break;
            }
        }
        if(int(*p)>=48&&int(*p)<=57)
            s[k++]=NumToString(getNextNum(p));//除非这里是数字，我才读数字
        if(*p=='\0')
            break;
    }
}
long long BaseTool::gcd(long long x,long long y)
{
    if(y==0)
        return x;
    else
        return gcd(y,x%y);
}
double BaseTool::getNextNum(char *a)
{
    double m=0.0;
    char *t;
    t=a;
    for(unsigned int i=0; i<=strlen(a)-1; i++,t++)
    {
        if(int(a[i])>=48&&int(a[i])<=57)
        {
            int t1=i;//第一个数字字符的位置
            while(int(a[i])>=48&&int(a[i])<=57)
            {
                i++;
                t++;
            }
            int t2=i;//此时i为非数字字符的位置
            //此时指针t也指向了这个位置
            int k=t2-t1-1;//最高次的位数
            for(int j=t1; j<=t2-1; j++)
            {
                m+=(int(a[j])-48)*pow(10.0,k--);
            }
            //cout<<"m="<<m<<endl;
            if(int(a[i])==46)//小数点
            {
                i++;
                int t3=i;//小数点后头第一个数字字符的位置
                while(int(a[i])>=48&&int(a[i])<=57&&a[i]!='\0')
                {
                    i++;
                    t++;
                }
                t++;
                int t4=i;//此时i为非数字字符的位置
                //此时指针t也指向了这个位置
                //int _k=t4-t3;//最后一个数字的幂
                int mm=1;
                double n=0;//存小数
                for(int j=t3; j<=t4-1; j++)
                {
                    n+=(int(a[j])-48)/pow(10.0,mm++);
                }
                //cout<<"n="<<n<<endl;
                m+=n;
            }
        }
        else
        {
            continue;
        }
        break;
    }
    p=t;//让p指向当前字符串的位置
    return m;
}
string BaseTool::getNextOperator(char *a)
{
    if(int(*a)=='\0')
    {
        return "\0";
    }
    if(int(*a)<48||int(*a)>57)
    {
        string ss;
        ss=*a;
        //cout<<"ss="<<ss<<endl;
        p++;
        return ss;
    }
    return "\0";
}

//定义有理数类
class rational
{
public:
    rational();
    rational(long long a,long long b,double c):up(a),down(b),R(c){}
    double getR(){return R;}
    void setR(double R){this->R=R;}
    long long getup(){return up;}
    void setup(int up){this->up=up;}
    long long getdown(){return down;}
    //重载有理数的四则运算符
    double operator+(const rational &);
    double operator-(const rational &);
    double operator*(const rational &);
    double operator/(const rational &);
    bool operator==(const rational &);//for cmp
    bool operator<(const rational &);//for cmp
bool operator>(const rational &);//for cmp
void frac();//从有理数的有限小数表示求有理数的分数表示
    void youhua();//约分
    friend void cmpDisplay(rational& a,rational& b );
private:
    long long up;//分子
    long long down;//分母
    double R;//有理数小数
    void ratDisplay();//有理数的显示
    char cmp(const rational &);
};
char rational::cmp(const rational &s2)
{
    rational s1(up,down,R);
    if(s1>s2)
        return '>';
    if(s1==s2)
        return '=';
    if(s1<s2)
        return '<';
    return ' ';//if error

}
rational::rational()
{
    R=0.0;
    up=0;
    down=0;
}
bool rational::operator==(const rational &b)
{
    if(R==b.R)
        return true;
    return false;
}
bool rational::operator<(const rational &b)
{
    if(R<b.R)
        return true;
    return false;
}
bool rational::operator>(const rational &b)
{
    if(R>b.R)
        return true;
    return false;
}
void rational::frac()
{
    double S;
    S=R;
    S*=10000000;
    up=(long long)S;
    down=10000000;
}
void rational::ratDisplay()
{
    if(getdown()==1)
    {
        cout<<getup();
    }
    else
    {
        cout<<getup()<<"/"<<getdown();
    }
}
void rational::youhua()
{
    rational c;
    c.up=up;
    c.down=down;
    up=c.up/BaseTool::gcd(c.up,c.down);
    down=c.down/BaseTool::gcd(c.up,c.down);
}

void cmpDisplay(rational& a,rational& b)//友元函数
{
    a.ratDisplay();
    cout<<a.cmp(b);
    b.ratDisplay();
}

class Operate:public BaseTool,public rational
{
public:
    Operate() {}
    double Operation(string *a);/**核心函数,从字符串得出数值的计算函数*/
    bool IfRight();//检查表达式是否正确
    bool ifcmp(char a[]);//判断用户是否输入了cmp命令
    bool ifexit(char a[]);//判断是否退出

private:
    double BasicOperation(string a[]);/**核心函数 用来进行无括号运算*/
};
double Operate::BasicOperation(string a[])//无括号运算
{
    string ss[100];//存放新元素
    for(int i=0; i<=99; i++) //将s拷贝给ss
        ss[i]=a[i];
    int m=strN(ss);
    if(m==1)
    {
        double M;
        M=StringToNum(ss[0]);
        return M;
    }
    if(m==2)//只有两个元素,那么第一个一定是正负号，第二个位置为数字
    {
        double M;
        if(ss[0]=="+")
        {
            M=StringToNum(ss[1]);
            return M;
        }
        else if(ss[0]=="-")
        {
            M=StringToNum(ss[1]);
            return -M;
        }
    }
    if(m==3)//二元运算
    {
        double S;
        if(ss[1]=="+")
        {
            double s1=StringToNum(ss[0]);
            double s2=StringToNum(ss[2]);
            S=s1+s2;
            return S;
        }
        if(ss[1]=="-")
        {
            double s1=StringToNum(ss[0]);
            double s2=StringToNum(ss[2]);
            S=s1-s2;
            //cout<<"hello";
            return S;
        }
        if(ss[1]=="*")
        {
            double s1=StringToNum(ss[0]);
            double s2=StringToNum(ss[2]);
            S=s1*s2;
            return S;
        }
        if(ss[1]=="/")
        {
            double s1=StringToNum(ss[0]);
            double s2=StringToNum(ss[2]);
            S=s1/s2;
            return S;
        }
    }
    if(m>3)
    {
        if(ss[m-4]=="-")
        {
            double S;
            if(ss[m-2]=="+")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1-s2;
            }
            if(ss[m-2]=="-")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1+s2;
            }
            if(ss[m-2]=="*")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1*s2;
            }
            if(ss[m-2]=="/")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1/s2;
            }
            ss[m-3]=NumToString(S);
            for(int i=m-2; i<=m-1; i++)
            {
                ss[i]="\0";
            }
            return BasicOperation(ss);
        }
        if(ss[m-4]=="+")
        {
            double S;
            if(ss[m-2]=="+")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1+s2;
            }
            if(ss[m-2]=="-")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1-s2;
            }
            if(ss[m-2]=="*")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1*s2;
            }
            if(ss[m-2]=="/")
            {
                double s1=StringToNum(ss[m-3]);
                double s2=StringToNum(ss[m-1]);
                S=s1/s2;
            }
            ss[m-3]=NumToString(S);
            for(int i=m-2; i<=m-1; i++)
            {
                ss[i]="\0";
            }
            return BasicOperation(ss);
        }
        if(ss[m-4]=="*")
        {
            double S;
            if(m>5)
            {
                if(ss[m-6]=="/")
                {
                    double s1=StringToNum(ss[m-7]);
                    double s2=StringToNum(ss[m-5]);
                    S=s1/s2;
                    ss[m-7]=NumToString(S);
                    ss[m-6]=ss[m-4];
                    ss[m-5]=ss[m-3];
                    ss[m-4]=ss[m-2];
                    ss[m-3]=ss[m-1];
                    ss[m-2]="\0";
                    ss[m-1]="\0";
                    return BasicOperation(ss);
                }
                else
                {
                    double s1=StringToNum(ss[m-5]);
                    double s2=StringToNum(ss[m-3]);
                    S=s1*s2;
                    ss[m-5]=NumToString(S);
                    ss[m-4]=ss[m-2];
                    ss[m-3]=ss[m-1];
                    ss[m-2]="\0";
                    ss[m-1]="\0";
                    return BasicOperation(ss);
                }
            }
            else
            {
                double s1=StringToNum(ss[m-5]);
                double s2=StringToNum(ss[m-3]);
                S=s1*s2;
                ss[m-5]=NumToString(S);
                ss[m-4]=ss[m-2];
                ss[m-3]=ss[m-1];
                ss[m-2]="\0";
                ss[m-1]="\0";
                return BasicOperation(ss);
            }
        }
        if(ss[m-4]=="/")
        {
            double S;
            double s1=StringToNum(ss[m-5]);
            double s2=StringToNum(ss[m-3]);
            S=s1/s2;
            ss[m-5]=NumToString(S);
            ss[m-4]=ss[m-2];
            ss[m-3]=ss[m-1];
            ss[m-2]="\0";
            ss[m-1]="\0";
            return BasicOperation(ss);
        }
    }
    return 0.0;
}
double Operate::Operation(string *a)
{
    string ss[100];//存放新元素
    for(int i=0; i<=99; i++) //将s拷贝给ss
        ss[i]=a[i];
    int m=0;//统计左括号的个数
    int ii1;//记录最后一个左括号的位置
    for(int i=0; i<=99; i++)
    {
        if(ss[i]=="(")
        {
            ii1=i;
            m++;
        }
    }
    if(m==0)
    {
        return BasicOperation(ss);
    }
    int ii2;//记录第一个右括号的位置
    for(int j=ii1+1;; j++)
    {
        if(ss[j]==")")
        {
            ii2=j;
            break;
        }
    }
    string Temp[100];
    for(int i=0; i<=99; i++)
        Temp[i]="\0";
    for(int i=ii1+1; i<=ii2-1; i++)
    {
        Temp[i-ii1-1]=ss[i];
    }

    double xx;
    xx=BasicOperation(Temp);
    ss[ii1]=NumToString(xx);
    for(int i=1; ss[ii1+i]!="\0"; i++)
        ss[ii1+i]=ss[ii2+i];
    //此时ss已经被化简了
    return Operation(ss);
    return 0.0;
}
bool Operate::IfRight()
{
    int z=0;//统计右括号的个数
    int y=0;//统计左括号的个数
    for( int i=0; i<=99; i++)
    {
        if(a[i]=='(')
            z++;
        if(a[i]==')')
            y++;
    }
    if(z!=y)
        return false;
    for(int i=0; i<=99; i++)
    {
        if(a[i]=='\0')
            continue;
        if(a[i]=='('||a[i]==')'||a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='.')
            continue;
        if(int(a[i])<48||int(a[i])>57)//如果是非数字
        {
            return false;
        }
    }
    return true;
}
bool Operate::ifcmp(char a[])
{
    if(a[0]=='c'&&a[1]=='m'&&a[2]=='p')
        return true;
    return false;
}
bool Operate::ifexit(char a[])
{
    if(a[0]=='e'&&a[1]=='x'&&a[2]=='i'&&a[3]=='t')
        return true;
    return false;
}

int k=1;
int main()
{
    while(cout<<"In["<<k<<"]:= ")
    {
        //cin>>a之前必须先清空a

        for(int i=0; i<=99; i++)//清空a
        {BaseTool::a[i]='\0';}cin>>BaseTool::a;
        //判断是否退出程序
        Operate IFEXIT;
        if(IFEXIT.ifexit(BaseTool::a))
            break;
        Operate IFCMP;
        if(IFCMP.ifcmp(BaseTool::a))
        {
            cout<<endl;
            Operate aa,bb;
            cout<<"请输入第一个有理数:";
            for(int i=0; i<=99; i++)//清空a
            {BaseTool::a[i]='\0';}cin>>BaseTool::a;

            if(!aa.IfRight())
            {
                cout<<"Out["<<k++<<"]= "<<"输入错误"<<endl<<endl;
                continue;
            }

            aa.CharToString();
            aa.setR(aa.Operation(BaseTool::s));
            aa.frac();aa.youhua();

            cout<<"请输入第二个有理数:";
            for(int i=0; i<=99; i++)//清空a
            {BaseTool::a[i]='\0';}cin>>BaseTool::a;

            if(!bb.IfRight())
            {
                cout<<"Out["<<k++<<"]= "<<"输入错误"<<endl<<endl;
                continue;
            }

            bb.CharToString();

            bb.setR(bb.Operation(BaseTool::s));
            bb.frac();bb.youhua();
            cout<<endl;
            cout<<"Out["<<k++<<"]= ";cmpDisplay(aa,bb);
            cout<<endl<<endl;
            continue;
        }
        cout<<endl;

        //不比较大小则进行下述代码
        Operate op;
        //cin>>a之后必须check一下
        if(!op.IfRight())
        {
            cout<<"Out["<<k++<<"]= "<<"输入错误"<<endl<<endl;
            continue;
        }
        op.CharToString();
        
        op.setR(op.Operation(BaseTool::s));
        cout<<"Out["<<k++<<"]= ";

        cout<<setprecision(12)<<op.getR()<<endl;
        cout<<endl;

    }
}
