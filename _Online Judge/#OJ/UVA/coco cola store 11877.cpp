#include<stdio.h>
int main()
{
    int t,i,a,reminder,sum,m,n;
    while(scanf("%d",&a)&&a!=0)
    {
        reminder=0;
        sum=0;
        while(1)
        {
            m=(a+reminder)/3;
            n=(a+reminder)%3;
            sum+=m;
            a=m;
            reminder=n;
            if(a+reminder<3) break;
        }
        if(m+n==2)
        {
            sum=sum+1; printf("%d\n",sum);
        }
        else printf("%d\n",sum);
    }
    return 0;
}
