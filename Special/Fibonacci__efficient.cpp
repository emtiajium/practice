#include<stdio.h>
long long fib[100]={0,1},i,n;
//int দিয়ে সর্বোচ্চ fib[46] হিসাব করা যাবে।
//long long দিয়ে সর্বোচ্চ fib[92] হিসাব করা যাবে।
int main()
{
    for(i=1;i<47;i++){
        fib[2*i-1]=fib[i-1]*fib[i-1]+fib[i]*fib[i];
        fib[2*i]=(2*fib[i-1]+fib[i])*fib[i];
        fib[2*i+1]=fib[i+1]*fib[i+1] + fib[i]*fib[i];
    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=0;i<93;i++){
        printf("[%lld] -> %lld\n",i,fib[i]);
    }
    return 0;
}
