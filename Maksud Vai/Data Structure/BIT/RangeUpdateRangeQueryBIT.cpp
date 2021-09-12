/*
While solving http://www.spoj.pl/submit/HORRIBLE , I came across that comment by sicasli and was thrilled to know that
BIT can be used for Range Update and Range Query also. I didn't understand his approach though. The following is how I
thought about it and solved. Its some what tricky to explain the working of BIT in simple text, I'll try my best.

Similar to Range Update - Point query, we maintain a BIT (say B1)
- Add v to [a..b] --> Update(a,v) and Update(b+1,-v) on the BIT B1
- Query(p) on B1 now gives the correct value of A[p]

The answer we want is ( Sum(0..b) - Sum(0..a-1) ), so lets design Sum(0..p). The thing with BIT is,
if you design it to work for one update ( which is easy to imagine ) and all possible queries on that
one update, mostly it should work for multiple updates ;)

Lets consider just one update : Add v to [a..b], rest all are 0

Now, consider Sum(0..p) for all possible p

1. 0 <= p <  a : 0
2. a <= p <= b : v * ( p - (a-1) )
3. b <  p <  n : v * ( b - (a-1) )

This suggests that, for a index p, if we have (v * p) we can get the Sum(0..p) by subtracting X from it

1. 0 <= p <  a : v = 0, X = 0
2. a <= p <= b : (v*p) - (v*(a-1)), X = v*(a-1)
3. b <  p <  n : v = 0, X = - v*b + v*(a-1)

So, we need to maintain something else too, to get that extra X factor and that should give
0 for p < a, v*(a-1) for p in [a..b], -v*b+v(a-1) for p > b.
Does this ring something ;) ? hoho ! one more BIT for keeping this X factor.

We need to maintain another BIT (say B2)
- Add v to [a..b] --> Update(a,v*(a-1)) and Update(b+1,-v*b) on the BIT B2
- Query(p) on B2 now gives the extra sum that should be subtracted from A[p]*p
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define SET(v,x) memset(v,x,sizeof v)
#define SI ({int x;scanf("%d",&x);x;})
#define MXN 100010

typedef long long LL;

LL B1[MXN], B2[MXN];
int n, q;

void U(LL B[MXN],int x, LL v)
{
       for(;x<MXN;x+=x&-x) B[x]+=v;
}

LL Q(LL B[MXN],int x)
{
        LL r=0;
        for(;x;x-=x&-x) r+=B[x];
        return r;
}

void upd(int a,int b,LL v)
{
	U(B1,a,v); U(B1,b+1,-v);
	U(B2,a,v*(a-1)); U(B2,b+1,-v*(b));
}

LL sum(int x){ return Q(B1,x)*x - Q(B2,x); }

LL get(int a,int b){ return sum(b) - sum(a-1); }

int main()
{
	for(int kase=1,kases=SI;kase<=kases;kase++)
	{
		n = SI; q = SI;
		int a, b, v;
		SET(B1,0), SET(B2,0);
		while(q--)
		{
			int op = SI; a = SI; b = SI;
			if(op) printf("%lld\n",get(a,b));
			else upd(a,b,SI);
		}
	}
	return 0;
}
