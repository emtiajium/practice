/*
ax + by = c;
d = gcd(a,b);
If c % d =0 , then one solution may be found by determining u and v such that d = ua + vb
then setting x0 = uc/d and y0 = vc/d.
All other solutions are given by
x = x0 + (b/d)t, y = y0 − (a/d)t; t belongs to Z
Extended Euclid finds u and v
*/
#include <stdio.h>
#include<iostream>
using namespace std;

struct TT{
    long long X,Y,G;
};
TT Extended_Euclid(long long fir,long long sec)
{
    long long x, y, u, v, m, n, quot, mod;
    x = 0; y = 1;
    u = 1; v = 0;
    while(fir){
        quot = sec / fir;
        mod = sec % fir;
        m = x - (u * quot);
        n = y - (v * quot);
        sec = fir, fir = mod, x = u, y = v, u = m, v = n;
    }
    TT local={x,y,sec};
    return local;
}

int main()
{
    TT input;
    long long a,b,c;
    while(cin>>a>>b>>c){
        c=-c;
        input = Extended_Euclid(a,b);
        if(c%input.G!=0) printf("-1\n");
        else cout<<(input.X*c)/input.G<<" "<<(input.Y*c)/input.G<<endl;;

    }
    return 0;
}
