#include<stdio.h>
int main()
{
    int t,i,n,h;
    register int f,g;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        f=(((((n*567)/9)+7492)*235)/47)-498;
        g=(f/10)%10;
        if(g<0)
        {
            h=-(g);
            printf("%d\n",h);
        }
        else printf("%d\n",g);
    }
    return 0;
}
