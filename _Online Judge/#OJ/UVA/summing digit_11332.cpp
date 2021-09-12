#include<stdio.h>

int summing(int a)
{
    int b,sum=0;
    while(a!=0){
        b=a%10;
        a=a/10;
        sum+=b;
    }
    if(sum>9) summing(sum);
    else if(sum<=9)return sum;
}

int main()
{
    int n;
    while(scanf("%d",&n)&&n){
        printf("%d\n",summing(n));
    }
    return 0;
}
