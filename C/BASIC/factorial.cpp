#include<stdio.h>
#include<conio.h>
int main(void)
{
    __int64 n,fct,i;
	while(1)
	{
          scanf("%I64d",&n);
          fct=1;
          for(i=2;i<=n;i++)
          {
             fct*=i;

             }
             printf("Factorial is %I64d\n",fct);
	return 0;		 }

             }

