#include<stdio.h>
#include<conio.h>
#include<ctype.h>
main (void)
{
     char character;
     printf("Press any key  ");
     character=getchar();
     if(isalpha(character)>0)
     printf("\nThe character is a alphabat");
     else if(isdigit(character)>0)
     printf("\nThe character is a digit");
     else if(ispunct(character>0))
     printf("\nThe character is a punctuation");
     else
     printf("\nThe character is not a alphanumeric");
     getch();
}
