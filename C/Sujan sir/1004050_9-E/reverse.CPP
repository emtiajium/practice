#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,k,arr[10]={10,15,20,25,30,35,40,45,50,55};
for(i=9,j=0;i>j;i--,j++)
{
k=arr[j];
arr[j]=arr[i];
arr[i]=k;
}
for(i=9;i>=0;i--)
{
printf(" ");
printf("[%d]= %d\t",i,arr[i]);
}
getch();
return 0;
}
