#include<stdio.h>
#include<conio.h>
main (void)
{
     
     int answer,count;
     for(count=1;count<11;count+=1)
     {printf("what is %d + %d ?\n",count,count);
     scanf("%d",&answer);
     }
     if(answer==count+count)
     printf("Right ! ");
     else
     {
         printf("Sorry, you are wrong.");
         printf("\nThe answer is %d.",count+count);
     }
     getch();
}
