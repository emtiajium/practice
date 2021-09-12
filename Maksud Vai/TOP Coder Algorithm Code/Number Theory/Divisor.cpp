//Compute How many Number Of Divisor Of a Number
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define SIZE_N 100000
#define SIZE_P 66457

bool flag [SIZE_N] ;
int prime [SIZE_P] ;

void seive ()
{
	int i,j,r,c=0,p ;

	for (i=3;i<=SIZE_N;i+=2)    flag[i] = true;

	flag[2]=true;
	prime[++c]=2;
	p=SIZE_N+1;
	for(i=3;i<p;i+=2)
		if ( flag[i] )
		{
			prime[++c]=i;
            if ( SIZE_N / i >= i )
            {
                r=i*2;
                for(j=i*i;j<p;j+=r)
						flag[j]=false;
            }
		}
    //printf( "Total prime: %d\n", c ) ;
}

int divisor(int n)
{
    int i,val,count,sum;

    val=sqrt(n)+1;
    sum=1;
    for(i=1;prime[i]<val;i++)	    {
        if(n%prime[i]==0)
        {
            count=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                count++;
            }
            sum*=(count+1);
        }
    }
    if(n!=1)
        sum=sum*2;
    return sum;
}

int main()
{
    seive();
    int n;

    while(scanf("%d",&n)==1)
    {
        printf("%d No Of divisor:%d\n",n,divisor(n));
    }
    return 0;
}

/*
Input:
5
8
100
568
Output:
5 No Of divisor:2
8 No Of divisor:4
100 No Of divisor:9
568 No Of divisor:8
*/
