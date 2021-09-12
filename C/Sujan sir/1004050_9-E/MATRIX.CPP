#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,a[10][10];
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
scanf("%d",&a[i][j]);
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf("\t%d",a[i][j]);
printf("\n");

}
getch();
return 0;
}
