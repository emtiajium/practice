#include<stdio.h>

/*	Limit--------No. of Primes
100			    25
1000			168
10,000			1229
100,000			9592
1,000,000		78498
10,000,000		664579		*/


#define SIZE_N 1001000
#define SIZE_P 81000

bool flag [SIZE_N];
int prime [SIZE_P];

void sieve ()
{
	int i, j, r, c = 1;

	for ( i = 3; i < SIZE_N; i += 2 )
        flag[i] = true ;
	flag [2] = true ;

	prime [c++] = 2 ;

	for ( i = 3; i <SIZE_N; i += 2 )
        if ( flag[i] )
		{
			prime[c++] = i ;

            if ( SIZE_N/i >= i )
            {
                r = i * 2 ;
                for ( j = i * i; j <SIZE_N; j += r )
                    flag[j] = false ;
            }
		}
}

int main()
{
    sieve();

}
