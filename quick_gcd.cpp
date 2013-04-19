//a quick algorithm of greatest common divisor(gcd) solving
int gcd(int a,int b)
{
    if(a<b) return gcd(b,a);
    if(b==0) return a;
    if(a & 1)
    {
        if(b & 1) return gcd(b,a-b);
        else return gcd(a,b >> 1);
    }
    else
    {
        if(b & 1) return gcd(a >> 1,b);
        else return gcd(a >> 1,b >> 1) << 1;
    }
}

