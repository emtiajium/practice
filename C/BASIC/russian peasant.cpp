#include<stdio.h>
main(void)
{
    int a,b,sum;
    scanf("%d %d",&a,&b);
    if(a%2==0)sum=0;
    else sum=b;
    while(a!=1){
        a/=2;
        b=b*2;
        if(a%2!=0) sum+=b;
    }
    printf("%d",sum);
}