#include<stdio.h>
int t,c,a,b,d;
int main()
{
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        scanf("%d %d",&a,&b);
        d=a+b;
        printf("Case %d: %d\n",c,d);
    }
    return 0;
}
