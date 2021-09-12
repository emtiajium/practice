#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
bool flag[46355]={1,1};
int prime[4795]={2};
long long i,j,r,n,tn,t,p,cnd;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=4;i<46352;i+=2)
        flag[i]=true;
    for(i=3;i<216;i+=2){
        r=i+i;
        if(flag[i]==0){
            for(j=i*i;j<46352;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }
    for(i=3,j=1;i<46352;i+=2)
        if(flag[i]==false) prime[j++]=i;
    while(scanf("%lld",&n)&&n){
        if(flag[n]==true)
            puts("Given number is NOT prime! NO perfect number is available.");
        else{
            t=pow(2,n)-1;
            tn=t;
            cnd=sqrt(t)+1;
            for(i=0;tn!=1&&prime[i]<cnd;i++){
                while(tn%prime[i]==0)
                    tn/=prime[i];
            }
            if(tn==t){
                p=t* pow(2,n-1);
                printf("Perfect: %lld!\n",p);
            }
            else puts("Given number is prime. But, NO perfect number is available.");
        }
    }
    return 0;
}
/*
    Binary representation of Perfect number
    6 = 110 (1 zero 2 one)
    28 = 11100 (2 zero 3 one)
    496 = 111110000 (4 zero 5 one)
    8128 = 1111111000000 (6 zero 7 one)
    33550336 = 1111111111111000000000000 (12 zero 13 one)
    8589869056 = 111111111111111110000000000000000 (16 zero 17 one)
    137438691328 = 1111111111111111111000000000000000000 (18 zero 19 one)
    2305843008139952128 = 1111111111111111111111111111111000000000000000000000000000000 (30 zero 31 one)
    ** 2^11 -1, 2^23 -1, 2^29-1 are not Mersain prime
*/
