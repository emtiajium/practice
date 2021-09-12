#include<stdio.h>
long long r,m,p,b;
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%lld %lld %lld",&b,&p,&m)==3){
        r=1;
        b=b%m;
        while(p){
            if(p&1) r=(r*b)%m;
            b=(b*b)%m;
            p=p>>1;
        }
        printf("%lld\n",r);
    }
	return 0;
}
