#include<stdio.h>
#include<conio.h>
long int mlt(long int a,long int b);
main()
{

    long int a,b,c;
    scanf("%ld %ld",&a,&b);
    c=mlt(a,b);
    printf("%ld",c);
    getch();
    return 0;
}
long int mlt(long int x,long int y)
{
    int z=x*y;
    return z;
}        

