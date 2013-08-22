#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
using namespace std;
class DNA
{
public:
    int length;
    float ra, rt, rg, rc;
    void setr(int a, int t, int g, int c)
    {
        length = a + t + g + c;
        ra = float(a) / length;
        rt = float(t) / length;
        rg = float(g) / length;
        rc = float(c) / length;
    }
};
int main()
{
    int n = 182;
    DNA D[190];
    ifstream file;
    file.open("Nat-model-data.txt",ios::in);
    int k = 0;
    char temp;
    while(k < n)
    {
        string s;
        while(1)
        {
            temp = file.get();
            if(temp >= 48 && temp <= 57 || temp == EOF)
            {
                break;
            }
            else
            {
                s += temp;
            }
        }
        if(!s.empty())
        {
            k++;

            int strl = s.length();
            int ia = 0, it = 0, ig = 0, ic = 0;
            for(int i = 0; i < strl; i++)
            {
                if(s[i] == 'a') ia++;
                if(s[i] == 't') it++;
                if(s[i] == 'g') ig++;
                if(s[i] == 'c') ic++;
            }
            D[k].setr(ia, it, ig, ic);
        }
    }
    ofstream save("answer.txt");
    save<<"k\tra\trt\trg\trc\tlength"<<endl;
    for(int i = 1; i <= n; i++)
    {
        save<<setprecision(4)<<i<<"\t"<<D[i].ra<<"\t"<<D[i].rt<<"\t"<<D[i].rg<<"\t"<<D[i].rc<<"\t"<<D[i].length<<endl;
    }
}



