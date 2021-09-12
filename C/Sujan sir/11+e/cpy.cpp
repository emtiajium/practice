#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
    char a[10];
    scanf("%s",a);
    char b[10];
    scanf("%s",b);
    strcpy(a,b);
    printf("%s",a);
    getch();
}    
