#include<stdio.h>
int main()
{
    int i,t,summation,subtraction,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
    scanf("%d %d",&summation,&subtraction);
    if(summation<subtraction) printf("impossible\n");
    else
    {
        x=(summation+subtraction)/2;
        y=(summation-subtraction)/2;
        if((x+y)==summation&&((x-y)==subtraction||(y-x)==subtraction))
        printf("%d %d\n",x,y);
        else printf("impossible\n");
        }
    }
    return 0;
}
