#include<stdio.h>

int t,cases;
unsigned n,fact[40]={1};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(n=1;n<35;n++){
        fact[n]=fact[n-1]*n;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%u",&n);
        if(n>33) printf("Case %d: 0\n",++cases);
        else printf("Case %d: %u\n",++cases,fact[n]);
    }
	return 0;
}
