#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int MOD=10000007;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int t,cases,a,b,c,d,e,f;
LL arr[10005];

LL func(LL n){
    if(n==0) return a;
    if(n==1) return b;
    if(n==2) return c;
    if(n==3) return d;
    if(n==4) return e;
    if(n==5) return f;
    if(arr[n]!=-1) return arr[n];
    LL p,q,r,s,u,v,ans;
    p=func(n-1)%MOD;
    q=func(n-2)%MOD;
    r=func(n-3)%MOD;
    s=func(n-4)%MOD;
    u=func(n-5)%MOD;
    v=func(n-6)%MOD;
    arr[n]=ans=(p+q+r+s+u+v)%MOD;
    return arr[n];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    LL n;
    scanf("%d",&t);
    while(t--){
        memset(arr,-1,sizeof(arr));
        scanf("%d%d%d%d%d%d%lld",&a,&b,&c,&d,&e,&f,&n);
        printf("Case %d: %lld\n",++cases,func(n)%MOD);
    }
    return 0;
}
