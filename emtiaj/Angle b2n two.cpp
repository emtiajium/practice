#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int SIZE=100005;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int t,cases;
int x,y,x2,y2,DP;
double absA,absB,angle;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d%d%d%d",&x,&y,&x2,&y2)==4){
        DP=x*x2+y*y2;
        absA=sqrt((double)(x*x+y*y));
        absB=sqrt((double)(x2*x2+y2*y2));
        angle=acos((double)(DP/absA/absB));
        angle=angle*180.0/PI;
        printf("(%d %d) (%d %d) -> %.2lf\n",x,y,x2,y2,angle);
    }
    return 0;
}
