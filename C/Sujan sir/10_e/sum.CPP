#include<stdio.h>
#include<conio.h>
int main()
{
//1+2+4+7+......
int a,i,k,j=1,s=0;
scanf("%d",&a);
for(i=0,k=1;i<a;i++,k++)
{
	s=s+j;
    j=j+k;

}
printf("%d",s);
getch();
return 0;
}