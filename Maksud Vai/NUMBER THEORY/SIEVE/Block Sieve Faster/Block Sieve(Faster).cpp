#include <iostream>
#include <math.h>
#include<stdio.h>
#include<algorithm>

using namespace std;

#define SET0(i) List[i>>5]&=~(1<<i)
#define SET1(i) List[i>>5]|=(1<<i)
#define GET(i)  ((List[i>>5]>>i)&1)

#define NUM 300000000 //expected upper limit of the required prime num
#define SQRT ((int)ceil(sqrt(NUM))) //ceeling of the squar root of the NUM

unsigned long List[NUM>>5] = {0};

void FillList(long num)
{
    long t;
    num = (num << 1) + 1;
    t = (num*num - 1) >> 1;
    while(t<(NUM>>1))
    {
        SET1(t);
        t += num;
    }
}

void MakeList()
{
    SET1(0);
    for(long i = 1; i<=((SQRT-1)>>1); i++)
    {
        if(!GET(i))
        {
            FillList(i);
        }
    }
}

void Sieve()
{
    int counter = 1; //number two counted

    MakeList();
    ///Except 2
    for(long i=1; i<(NUM>>1); i++)
    {
        if(!GET(i))
        {
            counter++;
            ///The Prime number is i*2+1
        }
    }

    /// if(!GET(x/2))   then x is prime where x is odd number.

    //printf("%d\n",counter);
}

