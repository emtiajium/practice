#include<stdio.h>
int main()
{
    long long a;
    while(scanf("%lld",&a)!=EOF){
        long long sum=0,i;
        for(i=1;i<=a;i++)
            sum+=i*i*i;

        printf("%lld\n",sum);
    }
return 0;
}
