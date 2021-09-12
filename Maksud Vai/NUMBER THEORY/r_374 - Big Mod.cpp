#include<stdio.h>


long long BigMod(long long b,long long p,long long m)
{
    long long  x=1,power;

    power = b%m;
    while(p)
    {
        if(p&1)    x = (x * power) % m ;
        power = (power *power) % m ;
        p >>= 1 ;
    }
    return x;
}

int main()
{
    int b,p,m,x,z,power,i;

    while(scanf("%d%d%d",&b,&p,&m)==3)
    {
//        power = b%m;
//        x=1;
//        i=0;
//        while(p)
//        {
//            if(p&1)    x = (x * power) % m ;
//            power = (power *power) % m ;
//            p >>= 1 ;
//        }
        x = BigMod(b,p,m);
        printf("%d\n",x);
    }
    return 0 ;
}
