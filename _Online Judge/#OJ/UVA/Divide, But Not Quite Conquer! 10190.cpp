#include<stdio.h>
#include<math.h>
long long square[1000],m,i;
int main()
{
    long long n,j,temp_i;
    while(scanf("%lld %lld",&n,&m)==2){
        if(m==0||n==0) printf("Boring!\n");
        else if(m==1) printf("Boring!\n");
        else{
            square[0]=1;
            square[1]=m;
            i=2;
            do{
                square[i++]=pow(m,i);
            }
            while(square[i-1]<=n);
            temp_i=i;
            if(square[temp_i-2]==n){
                for(j=temp_i-2;j>=0;j--){
                    printf("%lld",square[j]);
                    if(j>0) printf(" ");
                }
                printf("\n");
            }
            else printf("Boring!\n");
        }
    }
    return 0;
}
