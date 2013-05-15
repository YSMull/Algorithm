#include<iostream>
#include<string>
#include<sstream>
using namespace std;

typedef long long int LLI;

string N2S(const LLI& x)
{
    ostringstream o;
    if(o << x)
        return o.str();
    return "conversion error";//if error
}

LLI S2N(const string &s)
{
    istringstream i(s);
    LLI x;
    if(i >> x)
        return x;
    return 0.0;//if error
}

string sort_min(string s)
{
    int len = s.length();
    for(int i = 0; i < len-1; i++)
        for(int j = i+1; j < len; j++)
        {
            if(s[i] > s[j])
            {
                char Temp;
                Temp = s[i];
		s[i] = s[j];
                s[j] = Temp;
            }
        }
    return s;
}

string sort_max(string s)
{
    int len = s.length();
    for(int i = 0; i < len-1; i++)
        for(int j = i+1; j < len; j++)
        {
            if(s[i] < s[j])
            {
                char Temp;
                Temp = s[i];
                s[i] = s[j];
                s[j] = Temp;
            }
        }
    return s;
}

string Do(string s)
{
	string s_min = sort_min(s);
	string s_max = sort_max(s);
	string s_new = N2S(S2N(s_max)-S2N(s_min));
	cout<<s_max<<"-"<<s_min<<"="<<s_new<<endl;
	return s_new;
}

int main()
{
	string s;
	cin>>s;
	string s_new = s;
	while(1)
	{
		string Temp = s_new;
		s_new = Do(s_new); // update s_new
		if(Temp == s_new)
			break;
	}
	cout<<"The Number is "<<s_new<<endl;
	return 0;
}




