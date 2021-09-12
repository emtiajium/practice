#include<stdio.h>
int main(void)
{
    register long n,l;
    long term,max,i,max_value;
    while(scanf("%ld %ld",&n,&l)&&n&&l){
        printf("Between %ld and %ld, ",n,l);
        max=0;
        if(n>l){
            n=n^l;
            l=n^l;
            n=n^l;
        }
        for(i=n;i<=l;i++){
            term=0;
            n=i;
            do{
                if(n&1) n=(n+n+n)+1;
                else n=n>>1;
                term++;
            }
            while(n!=1);
            if(term>max){
                max=term;
                max_value=i;
            }
        }
        printf("%ld generates the longest sequence of %ld values.\n",max_value,max);
    }
return 0;
}
