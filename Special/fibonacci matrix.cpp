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
int n,i,j;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        int fib[2][2]={{1,1},{1,0}},res[2][2]={{1,0},{1,0}},tmp[2][2]={0};
        while(n){
            if(n&1){
                tmp[0][0]=res[0][0]*fib[0][0] + res[0][1]*fib[1][0];
                tmp[0][1]=res[0][0]*fib[0][1] + res[0][1]*fib[1][1];
                tmp[1][0]=res[1][0]*fib[0][0] + res[1][1]*fib[1][0];
                tmp[1][1]=res[1][0]*fib[0][1] + res[1][1]*fib[1][1];
                for(i=0;i<2;i++){
                    res[i][0]=tmp[i][0];
                    res[i][1]=tmp[i][1];
                }
            }
            tmp[0][0]=fib[0][0]*fib[0][0] + fib[0][1]*fib[1][0];
            tmp[0][1]=fib[0][0]*fib[0][1] + fib[0][1]*fib[1][1];
            tmp[1][0]=fib[1][0]*fib[0][0] + fib[1][1]*fib[1][0];
            tmp[1][1]=fib[1][0]*fib[0][1] + fib[1][1]*fib[1][1];
            for(i=0;i<2;i++){
                fib[i][0]=tmp[i][0];
                fib[i][1]=tmp[i][1];
            }
            n=n>>1;
        }
        printf("%d\n",res[0][1]);
    }
    return 0;
}
