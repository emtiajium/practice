#include<stdio.h>
int t;
long long r,m,p,b;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&b,&p,&m);
        r=1;
        while(p!=0){
            if(p&1) r=(r*b)%m;
            b=(b*b)%m;
            p=p>>1;
        }
        printf("%lld\n",r);
    }
    scanf("%d",&t);
	return 0;
}
