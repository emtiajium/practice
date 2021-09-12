/**
    FINDING INVERSE OF a MODULING WITH b.
    solution of following equation.
    ax+by = gcd(a,b);

    Link: http://e-maxx.ru/algo/extended_euclid_algorithm
*/

#include<iostream>
using namespace std;

#define LL          long long


LL ExtendedGCD(LL a,LL b,LL &x,LL &y)
{
    if(a==0)
    {
        x=0;y=1;
        return b;
    }
    LL x1,y1,g=ExtendedGCD(b%a,a,x1,y1);
    x = y1-(b/a)*x1;
    y = x1;
    return g;
}


void Find_ExtendedGCD(LL a,LL b,LL &x)
{
    LL y;
    LL g=ExtendedGCD(a,b,x,y);
    if(g!=1)    cout<<"No Solution"<<endl;
    else x = (x%b+b)%b;
}


int main()
{
    int n,m;
    LL x;

    while(cin>>n>>m)
    {
        Find_ExtendedGCD(n,m,x);
        cout<<x<<endl;
    }

    return 0;
}



