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
bool flag[10008];
int prime[1235]={2},arr[10008];
int i,j,r,k,cnd,coun,sum,n;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=4;i<10008;i+=2)
        flag[i]=true;
    for(i=3;i<101;i+=2){
        if(flag[i]==false){
            r=i+i;
            for(j=i*i;j<10008;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<10008;i+=2)
        if(flag[i]==false) prime[j++]=i;
    for(k=2;k<10002;k++){
        coun=0;
        cnd=k/2;
        for(i=0;prime[i]<=cnd;i++){
            sum=0;
            for(j=i;sum<=k;j++)
                sum+=prime[j];
            if(sum-prime[j-1]==k) coun++;
        }
        if(flag[k]==false) coun++;
        arr[k]=coun;
    }
    while(scanf("%d",&n)&&n){
        printf("%d\n",arr[n]);
    }
    return 0;
}
