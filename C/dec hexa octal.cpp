#include<stdio.h>
#include<conio.h>
main()
{
      int a[100],n,i=0,j;
	scanf("%d",&n);
	while(n!=0)
		{
			a[i]=n%2;
			n/=2;
			i++;
			
		}
		for(j=i-1;j>=0;j--)
			
				printf("Decimal     Hexadecimal     Octal     Binary\n");
      printf("%4d %14X %11o %d\n",n,n,n,a[j]);
      getch();
		
}
