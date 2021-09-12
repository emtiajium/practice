#include<stdio.h>
#include<conio.h>
#include<string.h>
main(void)
{
    char a[200];
    char b;
    int i;
    scanf("%[^\n]",a);        
    int c=strlen(a);
    printf("\n%d\n",c);
    for(i=0;i<c;i++)
    {
        b=getch();
    if(b==a[i])
    putchar(b);
    else
    putchar('?');
    }
    
    getch();
}    
    
