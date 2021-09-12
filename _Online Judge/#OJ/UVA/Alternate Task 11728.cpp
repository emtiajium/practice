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
const int SIZE=38;
bool flag[SIZE],xlag,zlag;
int prime[15]={2};
int i,j,r,cnd,coun,cases,t;
long long n,sum;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<6;i+=2){
        if(flag[i]==false){
            r=i+i;
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2)
        if(flag[i]==false) prime[j++]=i;
    while(scanf("%lld",&n)&&n){
        printf("Case %d: ",++cases);
        if(n==1){
            puts("1");
            continue;
        }
        zlag=false;
        for(i=n-1;i>1;i--){
            cnd=sqrt(i)+1;
            t=i;
			sum=1;
            for(j=0;prime[j]<cnd&&t!=1;j++){
                coun=0;
                xlag=false;
                while(t%prime[j]==0){
                    t/=prime[j];
                    coun++;
                    xlag=true;
                }
                if(xlag)
                    sum*=( (long long) ( pow( prime[j],coun+1 ) )-1 ) / (prime[j]-1);
            }
            if(t>1) sum*=( (long long) ( pow( t,2 ) )-1 ) / (t-1);
            if(sum==n){
                zlag=true;
                break;
            }
        }
        if(zlag) printf("%d\n",i);
        else puts("-1");
    }
    return 0;
}
