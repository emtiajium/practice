#include<stdio.h>
int fct(int a)
{
	int i,f=1;
	for(i=1;i<=a;i++)
	{
		f*=i;
	}
	return f;
}
main()
{
	int a,b;
	scanf("%d",&a);
	b=fct(a);
	printf("%d",b);
	return 0;
}



