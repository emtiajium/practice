#include<stdio.h>
int main()
{
    int a,b,reminder,sum,m,n;
    while(scanf("%d %d",&a,&b)==2){
        reminder=0;
        sum=a;
        while(a!=0){
            m=(a+reminder)/b;
            n=(a+reminder)%b;
            sum+=m;
            a=m;
            reminder=n;
        }
        printf("%d\n",sum);
    }
    return 0;
}
