/**
    Chinese Remainder Theorem (The algorithm of Garner).

    Link: http://e-maxx.ru/algo/chinese_theorem
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

#define PB          push_back
#define LL          long long
#define SZ(a)       ((int)a.size())


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

const int S = 13;

LL R[S][S],x[S];

LL Garner_Algorithm(vector<LL> &p,vector<LL> &a)
{
    /// All p[i] are relatively prime.
    int i,j,n=SZ(p);
    LL inv;

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
            Find_ExtendedGCD(p[i],p[j],inv);
            R[i][j] = inv;
        }


    for(i=0;i<n;i++)
    {
        x[i]=a[i];
        for(j=0;j<i;j++ )
        {
            x[i] = R[j][i]*(x[i]-x[j]) ;
            x[i] = x[i]%p[i];
            if(x[i]<0) x[i] += p[i] ;
        }
    }

    LL A=0,cur;
    for(i=0;i<n;i++)
    {
        cur = x[i];
        for(j=0;j<i;j++)    cur*=p[j];

       A+=cur;
    }

    return A;
}


int main()
{
    int i,j,k,l,tks,ks=1,n,m;
    vector<LL>p;
    vector<LL>a;

    scanf("%d",&tks);

    while(tks--)
    {
        scanf("%d",&n);
        p.clear();
        a.clear();
        for(k=0;k<n;k++)
        {
            scanf("%d%d",&i,&j);
            p.PB(i);
            a.PB(j);
        }

        printf("Case %d: %lld\n",ks++,Garner_Algorithm(p,a));
    }

    return 0;
}



