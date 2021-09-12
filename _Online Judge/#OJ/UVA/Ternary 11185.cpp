#include<stdio.h>
int main()
{
    long long dec,i,a,sum;
    while(scanf("%lld",&dec)&&(!(dec<0))){
        sum=0;
        i=1;
        while(dec>0){
            a=dec%3;
            dec=dec/3;
            sum+=(a*i);
            i=i*10;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
