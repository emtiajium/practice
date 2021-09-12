//Euclid divisor lemma: divident = divisor * quotient + remainder
#include<stdio.h>
int main()
{
    int divident,divisor,quotient,remainder,i;
    while(scanf("%d %d",&divident,&divisor)==2&&(divisor!=0)){
    int sum=0;
    for(i=1;;i++)
    {
        sum+=divisor;
        if(sum>divident) break;
    }
    quotient=i-1;
    remainder=(-1)*(sum-divisor-divident);
    printf("Quotient %d\nRemainder %d\n",quotient,remainder);
    }
    printf("Undefined\n");
    return 0;
}
