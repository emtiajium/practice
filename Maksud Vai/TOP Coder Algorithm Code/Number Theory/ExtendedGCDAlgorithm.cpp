//Extended GCD Algorithm
#include<stdio.h>
int lastx,lasty,x,y;

int extended_gcd(int a, int b)
{   int temp , quotient;
	x = 0; 	y = 1;
	lasty = 0;  lastx = 1;
	while( b != 0)
	{
		temp = b;
        quotient = a / b;
        b = a % b;
        a = temp;

        temp = x;
        x = lastx - quotient*x;
        lastx = temp;

        temp = y;
        y = lasty - quotient*y;
        lasty = temp;
	}
    return  a;
}

int main()
{	int n,A,B;
	while(scanf("%d%d",&A,&B)==2)
	{
		n=extended_gcd(A,B);
		printf("%d %d %d\n",lastx,lasty,n);
	}
	return 0;
}
