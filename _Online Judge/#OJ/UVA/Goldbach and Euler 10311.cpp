#include<stdio.h>
#include<math.h>
const int SIZE=100000002;
int status[3125000];
bool Check(int N,int pos){
    return N & (1<<pos);
}
int Set(int N,int pos){
    return N | (1<<pos);
}
void sieve(){
    int i,j,r,cnd;
    status[0>>5]=Set(status[0>>5],0&31);
    status[1>>5]=Set(status[1>>5],1&31);
    for(i=4;i<SIZE;i+=2)
        status[i>>5]=Set(status[i>>5],i&31);
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(Check(status[i>>5],i&31)==0){
            r=i<<1;
            for(j=i*i;j<SIZE;j+=r)
                status[j>>5]=Set(status[j>>5],j&31);
        }
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,i,j,r;
    sieve();
    while(scanf("%d",&n)==1){
        if(n<5)
            printf("%d is not the sum of two primes!\n",n);// 4=2+2
        else if(n&1){
            if(Check(status[(n-2)>>5],(n-2)&31)==0)
                printf("%d is the sum of 2 and %d.\n",n,n-2);
            else printf("%d is not the sum of two primes!\n",n);
        }
        else if((n&1)==0){
            j=r=0;
            for(i=n>>1;i>1;i--){
                if(Check(status[i>>5],i&31)==0 && Check(status[(n-i)>>5],(n-i)&31)==0){
                    j=i;
                    r=n-i;
                    if(j==r){ // 26=13+13
                        j=r=0;
                        continue;
                    }
                    else break;
                }
            }
            if(j==0 && r==0)printf("%d is not the sum of two primes!\n",n);
            else printf("%d is the sum of %d and %d.\n",n,j,r);
        }
    }
    return 0;
}
