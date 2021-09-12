//Normal Prime Seive Algorithm
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    printf( "Total prime: %d\n", c ) ;
}
int main()
{
    seive();
    return 0;
}
