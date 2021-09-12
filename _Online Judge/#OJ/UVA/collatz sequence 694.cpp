#include<stdio.h>
int main()
{
    long n,l,term,cas=1,x,i;
    while(scanf("%ld %ld",&n,&l)&&(!(n<0&&l<0))){
        term=1;
        x=n;
        while(n!=1){
            if(n&1)n=(n+n+n)+1;
            else n=n>>1;
            if(n<=l){
                term++;
            }
            else break;
        }
        printf("Case %ld: A = %ld, limit = %ld, number of terms = %ld\n",cas++,x,l,term);
    }
    return 0;
}
