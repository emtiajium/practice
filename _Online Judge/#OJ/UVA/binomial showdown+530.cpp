#include<stdio.h>
int n,r,j;
unsigned long long c;
int main()
{
    while(scanf("%d %d",&n,&r)&&(n!=0 || r!=0)){
        if(r>n/2) r=n-r;
        for(j=0,c=1;j<r;j++){
            c=c*(n-j);
            c=c/(1+j);
        }
        printf("%llu\n",c);
    }
return 0;
}
