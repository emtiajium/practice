#include <stdio.h>
#include <math.h>
#include <iostream>
#include<string.h>

using namespace std;

#define  SIZE_N 1000001
#define SIZE_P 100000

int prime[SIZE_P],store[SIZE_N];
long long dp[SIZE_N];
bool flag[SIZE_N];
void sieve()
{
	long i=0,j=0,r=0,c=0,len;
	prime[0]=2;

	for(i=4,j=SIZE_N-1;i<j;i+=2,j-=2)
		flag[i]=flag[j]=1;
	flag[i]=flag[j]=1;

	for(i=3,c=1;i<=SIZE_N;i+=2)
		if(flag[i]==0)
		{
			prime[c]=i;
			++c;
			if(i<SIZE_N/i)
			{
				r=i<<1;
				for(j=i*i;j<=SIZE_N;j+=r)
					flag[j]=1;
			}
		}
}

void r_prime()
{
    int i,j,k,v,count,val;

    dp[1]=0;
    dp[2]=store[1]=store[2]=1;
    dp[3]=3;
    store[3]=2;

    for(i=4;i<SIZE_N;i++)
    {
        if(flag[i]==0)
            store[i]=i-1;
        else
        {
            val=sqrt(i)+1;
            for(j=0;prime[j]<val;j++)
                if(i%prime[j]==0)
                {
                    count=0;
                    v=i;
                    while(v%prime[j]==0)
                    {
                        v/=prime[j];
                        count++;
                    }
                    store[i]=(prime[j]-1)*(pow(prime[j],count-1))*store[v];
                    break;
                }
            if(prime[j]>=val)
                store[i]=i-1;
        }
        dp[i]=dp[i-1]+store[i];
    }
}

int main()
{
	sieve();
	r_prime();
	long long q,i,m,temp,j,p,k,t,r;

    //scanf("%lld",&t);
    cin>>t;
    while(t--)
    {
			//scanf("%lld",&r);
			cin>>r;
			//printf("%lld\n",dp[r]);
			cout<<dp[r]<<endl;
    }

	return 0;
}
/*
Input & Output:
10      //test case
25
199
365
40623
78
1855
598
108730
364
40335
2154
1410815
78745
1884817298
100000
3039620709
813254
201035671594
56748
978867412
*/

