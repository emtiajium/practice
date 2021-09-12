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
int n,i,mod;
int power[25]={1};
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=1;i<21;i++)
        power[i]=power[i-1]*2;
    while(scanf("%d%d",&n,&mod)==2){
        long long fib[2][2]={{1,1},{1,0}},res[2][2]={{1,0},{1,0}},tmp[2][2]={0};
        while(n){
            if(n&1){
                tmp[0][0]=(res[0][0]*fib[0][0] + res[0][1]*fib[1][0])%power[mod];
                tmp[0][1]=(res[0][0]*fib[0][1] + res[0][1]*fib[1][1])%power[mod];
                tmp[1][0]=(res[1][0]*fib[0][0] + res[1][1]*fib[1][0])%power[mod];
                tmp[1][1]=(res[1][0]*fib[0][1] + res[1][1]*fib[1][1])%power[mod];
                for(i=0;i<2;i++){
                    res[i][0]=tmp[i][0];
                    res[i][1]=tmp[i][1];
                }
            }
            tmp[0][0]=(fib[0][0]*fib[0][0] + fib[0][1]*fib[1][0])%power[mod];
            tmp[0][1]=(fib[0][0]*fib[0][1] + fib[0][1]*fib[1][1])%power[mod];
            tmp[1][0]=(fib[1][0]*fib[0][0] + fib[1][1]*fib[1][0])%power[mod];
            tmp[1][1]=(fib[1][0]*fib[0][1] + fib[1][1]*fib[1][1])%power[mod];
            for(i=0;i<2;i++){
                fib[i][0]=tmp[i][0];
                fib[i][1]=tmp[i][1];
            }
            n=n>>1;
        }
        printf("%lld\n",res[0][1]%power[mod]);
    }
    return 0;
}
