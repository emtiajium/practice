#include<stdio.h>
int main()
{
    int a,reminder,sum,m,n;
    while(scanf("%d",&a)==1)
    {
        reminder=0;
        sum=a;
        while(a!=0)
        {
            m=(a+reminder)/3;
            n=(a+reminder)%3;
            sum+=m;
            a=m;
            reminder=n;
        }
        if(m+n==2)
        {
            sum=sum+1; printf("%d\n",sum);
        }
        else printf("%d\n",sum);
    }
    return 0;
}
