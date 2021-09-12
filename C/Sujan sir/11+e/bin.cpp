#include<stdio.h>
#include<conio.h>
int bin(int a);
main()
{
      int a,b;
      scanf("%d",&a);
      b=bin(a);
      getch();
      
            }
int bin(int a)
{
          int i=0,y[100];
          while(a!=0)
		{
			y[i]=a%2;
			a/=2;
			i++;
			
		}
		for(int j=i-1;j>=0;j--)
				printf("%d",y[j]);
				return a;
		
}
      
      
