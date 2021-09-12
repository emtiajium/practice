#include<stdio.h>
int main()
{
    int t,i,a,b,c,empty,reminder,sum,m,n;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        empty=a+b;
        reminder=0;
        sum=0;
        m=(empty+reminder)/c;
        n=(empty+reminder)%c;
        while(m+n>=c)
        {
            m=(empty+reminder)/c;
            n=(empty+reminder)%c;
            sum+=m;
            empty=m;
            reminder=n;
        }
        printf("%d\n",sum);
    }
    return 0;
}
