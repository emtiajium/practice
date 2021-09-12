#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>
#include <climits>
#include <cmath>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#define mx 300000000
int S=sqrt(mx)+5;
const int SQRT = 30000;  ///Greater than sqrt(mx).
bool seive[SQRT];

int chk[((mx+10)>>7)+100];

#define Ch(i) (chk[i>>7]&(1<<((i>>2)&31)))
#define Se(i) (chk[i>>7]|=(1<<((i>>2)&31)))
#define Re(i) (chk[i>>7]&=~((1<<((i>>2)&31))))

void Sieve()
{
    int i,j,k,t;

    for(i=1;i<=S;i++) for(j=i+1,k=i*i;(t=(k+j*j))<=mx;j+=2) Se(t);

    for(i=3;i<=S;i+=2) if(!seive[i])
    {
        for(j=i*i,k=i<<1;j<=S;j+=k)
        {
            seive[j]=1;
            if((j&3)==1) Re(j);
        }
        for(;j<=mx;j+=k) if((j&3)==1) Re(j);
    }

        /// if(Ch(x/2))   then x is prime.
}


int main()
{
    Sieve();
    printf("End");
}
