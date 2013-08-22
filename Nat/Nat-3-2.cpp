#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
/*
1.±Ω±˚∞±À·£®AAA,AAG£©
2.¡¡∞±À·£®AAT£¨AAC£¨GAA£¨GAG£¨GAT£¨GAC£©
3.Àø∞±À·£®AGA£¨AGG£¨AGT£¨AGC£¨TCA,TCG£©
4.¿“∞±À·£®ATA£¨ATG£©
5.∞ÎÎ◊∞±À·£®ACA,ACG£©
6.…´∞±À·£®ACC£©
7.∏¨∞±À·£®GGA£¨GGG£¨GGT,GGC£©
8.◊È∞±À·£®GTA£¨GTG£©
9.π»∞±ı£∞∑£®GTT,GTC£©
10.æ´∞±À·£®GCA£¨GCG£¨GCT,GCC,TCT,TCC£©
11.“Ï¡¡∞±À·(TAA,TAG,TAT)
12.µ∞∞±À·£®TAC£©
13.¿µ∞±À·£®TTT,TTC£©
14.À’∞±À·£®TGA,TGG,TGT,TGC£©
15.±˚∞±À·£®CGA,CGG,CGT,CGC£©
16.ÃÏ∂¨∞±À·£®CTA,CTG£©
17.ÃÏ∂¨ı£∞∑£®TTA,TTG£©
18.∏ ∞±À·£®CCA,CCG,CCT,CCC£©
19.π»∞±À·£®CTT,CTC£©
20.Á”∞±À·(CAA,CAG,CAT,CAC)
*/

int n = 40;
struct DNA
{
    int statistics[20];
    int sum;
    float rstatis[20];
    DNA(){for(int i = 0; i <= 19; i++) statistics[i] = 0;sum = 0;}
    void getr()
    {
        for(int i = 0; i <= 19; i++)
            sum += statistics[i];
        for(int i = 0; i <= 19; i++)
            rstatis[i] = float(statistics[i]) / sum;
    }
};
DNA D[190];
void GetNext_AminoAcid(const string & s, int i, int k)
{
    if(i+2 < s.length()-1)
    {

        char t[4];
        t[0] = s[i]-32;
        t[1] = s[i+1]-32;
        t[2] = s[i+2]-32;
        t[3] = '\0';
        string temp = t;
        //cout<<temp<<endl;
        if(temp == "AAA" || temp == "AAG")
            D[k].statistics[0]++;
        if(temp == "AAT" || temp == "AAC" || temp == "GAA" || temp == "GAG" || temp == "GAT" || temp == "GAC")
            D[k].statistics[1]++;
        if(temp == "AGA" || temp == "AGG" || temp == "AGT" || temp == "AGC" || temp == "TCA" || temp == "TCG")
            D[k].statistics[2]++;
        if(temp == "ATA" || temp == "ATG")
            D[k].statistics[3]++;
        if(temp == "ACA" || temp == "ACG")
            D[k].statistics[4]++;
        if(temp == "ACC")
            D[k].statistics[5]++;
        if(temp == "GGA" || temp == "GGG" || temp == "GGT" || temp == "GGC")
            D[k].statistics[6]++;
        if(temp == "GTA" || temp == "GTG")
            D[k].statistics[7]++;
        if(temp == "GTT" || temp == "GTC")
            D[k].statistics[8]++;
        if(temp == "GCA" || temp == "GCG" || temp == "GCT" || temp == "GCC" || temp == "TCT" || temp == "TCC")
            D[k].statistics[9]++;
        if(temp == "TAA" || temp == "TAG" || temp == "TAT")
            D[k].statistics[10]++;
        if(temp == "TAC")
            D[k].statistics[11]++;
        if(temp == "TTT" || temp == "TTC")
            D[k].statistics[12]++;
        if(temp == "TGA" || temp == "TGG" || temp == "TGT" || temp == "TGC")
            D[k].statistics[13]++;
        if(temp == "CGA" || temp == "CGG" || temp == "CGT" || temp == "CGC")
            D[k].statistics[14]++;
        if(temp == "CTA" || temp == "CTG")
            D[k].statistics[15]++;
        if(temp == "TTA" || temp == "TTG")
            D[k].statistics[16]++;
        if(temp == "CCA" || temp == "CCG" || temp == "CCT" || temp == "CCC")
            D[k].statistics[17]++;
        if(temp == "CTT" || temp == "CTC")
            D[k].statistics[18]++;
        if(temp == "CAA" || temp == "CAG" || temp == "CAT" || temp == "CAC")
            D[k].statistics[19]++;
    }
}
void GetDNA(ifstream & file)
{
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
                //if(s[i] == '\n' || s[i] == '>' || s[i] == ':') s.erase(i,1); //…æ≥˝ø’∏Ò
                if(s[i] == '\n') s.erase(i,1);
                if(s[i] == ':') s.erase(i,1);
                if(s[i] == '>') s.erase(i,1);
            }
            int Nstrl = s.length();
            for(int i = 0; i < Nstrl; i++)
                GetNext_AminoAcid(s, i, k);
        }
    }
}
void ReadFile()
{
    ifstream file;
    file.open("Nat-model-data.txt",ios::in);
    GetDNA(file);
}
void Output()
{
    for(int i = 1; i <= n; i++)
        D[i].getr();
    ofstream save("answer2-2.txt");
    save<<"k\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16\t17\t18\t19\t20\t"<<endl;
    for(int i = 1; i <= n; i++)
    {
        save<<i<<"\t";
        for(int j = 0; j <= 18; j++)
            save<<setprecision(4)<<D[i].rstatis[j]<<"\t";
        save<<setprecision(4)<<D[i].rstatis[19]<<endl;
    }
}
int main()
{
    ReadFile();
    Output();
}



