#include<stdio.h>
#include<string.h>
#include<conio.h>
main()
{
 //clrscr();
 int i,j;
 char arr[5][10]={"white", "red", "green", "yellow", "blue"};
 char temp[10];

 printf("\n\n  Before SORTING..>:");
 for(i=0;i<5;i++)
 printf("%s   ",arr[i]);

 for(i=0;i<5;i++)
 {
 for(j=i+1;j<5;j++)
 {
 if(strcmp(arr[i], arr[j])>0)
 {
 strcpy(temp,arr[i]);
 strcpy(arr[i],arr[j]);
 strcpy(arr[j],temp);
 }
 }
 }

 printf("\n\n  AFTER SORTING..>:");
 for(i=0;i<5;i++)
 printf("%s   ",arr[i]);
 getch();
 return 0;
 }