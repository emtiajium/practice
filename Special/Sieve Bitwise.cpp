// Prime between 0 to 10^8+10 is 5761456
// last two prime are 99999989 100000007
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

const int SIZE=100000010;
int status[SIZE>>5];
int prime[5761460]={2};
//vector<int>prime;

inline bool Check(int N,int pos){
    return N & (1<<pos);
}

inline int Set(int N,int pos){
    return N |= (1<<pos);
}

void sieve(){
    int i,j,r,cnd;
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(Check(status[i>>5],i&31)==0){
            r=i<<1;
            for(j=i*i;j<SIZE;j+=r){
                status[j>>5]=Set(status[j>>5],j&31);
            }
        }
    }
    for(i=3,j=1;i<SIZE;i+=2){
        if( Check(status[i>>5],i&31)==0){
           prime[j++]=i;
           //printf("%d\t",i);
        }
    }
    printf("last prime %d\n",prime[j-1]);
    printf("\n\nBetween 0 & %d, there are %d Prime numbers\n\n",SIZE,j);
}

int main()
{
    int n;
    sieve();
    while(scanf("%d",&n)==1){
        if( Check(status[n>>5],n&31)==0) puts("Prime");
        else puts("Composit");
    }
    return 0;
}
