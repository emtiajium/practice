#include<stdio.h>
int main (void)
{
    int coun=0;
    for(int a=3000;a<=3010;a++){
        if((a%4==0 && a%100!=0)|| a%400==0){
            printf("%d\n",a);
            coun++;
        }
    }
    printf("Count %d\n",coun);
    return 0;
}
//it is always divisible by 4,
//but century years are not leap years unless
//they are divisible by 400.
