#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=100005;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int t,cases;
LL x,y,up,down;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        up=2*(x*x*x-3*x*y*y);
        down=x*x+y*y;
        printf("Case %d: %lld/%lld\n",++cases,abs(up),abs(down));
    }
    return 0;
}
