#include<stdio.h>
#include<conio.h>
#include<ctype.h>
main (void)
{
     char alphabat;
     printf("Enter an alphabat  ");
     putchar('\n');
     alphabat=getchar();
     if(islower(alphabat))
     putchar(toupper(alphabat));
     else
     putchar(tolower(alphabat));
     getch();
}
     
