#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
char divident[205];
int t,cases,p,i,ini;
long long divisor,res;
long long bigmod(long long ,long long,long long);
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--){
        scanf("%s %lld",divident,&divisor);
        if(divisor<0) divisor=-divisor;
        ini=0;
        p=strlen(divident)-1;
        if(divident[0]=='-') ini=1;
        res=0;
        for(i=ini;divident[i];i++){
            res+=bigmod(10,p,divisor)*((divident[i]-48)%divisor);
            res%=divisor;
            p--;
        }
        res%=divisor;
        printf("Case %d: ",++cases);
        if(res==0) puts("divisible");
        else puts("not divisible");
    }
    return 0;
}
long long bigmod(long long b,long long p,long long m){
    long long r=1;
    while(p!=0){
        if(p%2==1) r=(r*b)%m;
        b=(b*b)%m;
        p/=2;
    }
    return r;
}
