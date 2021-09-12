#include<stdio.h>
#include<conio.h>
int binary(int n);
int hexa(int n);
int oct(int n);
int main()
{
	int n,a;
	printf("Enter a Decimal number to convert it \n");
	scanf("%d",&n);
	int c=binary(n);
	hexa(n);
	oct(n);
	printf(" Decimal-->  %d  Hexadecimal-->  %X  Octal-->  %o   Binary--> %d\n",n,n,n,c);
	getch();
	return 0;
}
int binary(int n)
{
    int a,i=1,c=0,b;
    while(n>0)
    {
        b=n%2;
        n=n/2;
        c+=(b*i);
        i=i*10;
    }
    return c;

}
int hexa(int n)
{
    return 0;
}
int oct(int n)
{
    return 0;
}


