#include<stdio.h>
int main()
{
    long long t,i,x,y;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%lld %lld",&x,&y);
        if(y%x==0) printf("%lld %lld\n",x,y);
        else printf("%d\n",-1);
    }
    return 0;
}
