/*
C(n,1) + C(n,2) + C(n,3) + ............ + C(n,n) = 2^(n) - 1;
C(n,1) + 2*C(n,2) + 3*C(n,3) + ............ + n*C(n,n) = n* 2^(n - 1);
Notes on Combinatorics ByTarik Adnan Moon page 5
intermediate book.
*/
#include<stdio.h>
int t,cases;
long long r,p,b;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&p);
        r=p%1000000007;
        b=2;
        p--;
        while(p){
            if(p&1) r=(r*b)%1000000007;
            b=(b*b)%1000000007;
            p=p>>1;
        }
        r=r%1000000007;
        printf("Case #%d: %lld\n",++cases,r);
    }
	return 0;
}
