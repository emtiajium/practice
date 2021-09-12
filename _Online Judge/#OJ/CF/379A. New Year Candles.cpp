#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=100005;
int t,cases,a,b,m,n,coun,mod;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d%d",&a,&b)==2){
        mod=0;
        coun=a;
        while(a){
            m=(a+mod)/b;
            n=(a+mod)%b;
            coun+=m;
            a=m;
            mod=n;
        }
        if(m+n==b) coun++;
        printf("%d\n",coun);
    }
    return 0;
}
