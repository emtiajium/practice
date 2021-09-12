#include<stdio.h>
int n,l;
int term,max,i;
int main(void)
{
    while(scanf("%d %d",&n,&l)==2){
        printf("%d %d ",n,l);
        max=0;
        if(n>l){
            n=n^l;
            l=n^l;
            n=n^l;
        }
        for(i=n;i<=l;i++){
            term=1;
            n=i;
            while(n!=1){
                if(n&1) n=n+n+n+1;
                else n=n>>1;
                term++;
            }
            if(term>max) max=term;
        }
        printf("%d\n",max);
    }
    return 0;
}
