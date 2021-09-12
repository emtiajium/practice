#include<stdio.h>
int main()
{
    int t,i;
    int a,b,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d  %d  %d",&a,&b,&c);
        if((a+b>c)&&(a+c>b)&&(c+b>a))
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }
    return 0;
}
