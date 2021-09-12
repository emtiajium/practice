#include<stdio.h>
int main()
{
    int a,right_digit,sum,temp_a;
    for(a=100;a<=1000;a++){
    temp_a=a,sum=0;
    while(a!=0)
        {
        right_digit=a%10;
        sum+=right_digit*right_digit*right_digit;
        a=a/10;
        }

    if(sum==temp_a)printf("%d  ",temp_a);
    a=temp_a;
	}
    return 0;
}
