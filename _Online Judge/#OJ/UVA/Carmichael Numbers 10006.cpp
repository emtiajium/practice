// A positive composite integer n is a Carmichael number if and only if
// n is square-free, and for all prime factor (n-1)%(p-1)=0
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
bool flag[260],xlag;
int prime[58]={2};
int i,j,r,cnd,n,t,coun,tot_pf,carm;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<17;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<260;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<260;i+=2)
        if(flag[i]==false) prime[j++]=i;
    while(scanf("%d",&n)&&n){
        t=n;
        cnd=sqrt(n)+1;
        tot_pf=carm=0;
        for(i=0;prime[i]<cnd&&t!=1;i++){
            xlag=false;
            coun=0;
            while(t%prime[i]==0){
                t/=prime[i];
                coun++;
                xlag=true;
            }
            if(xlag) tot_pf++;
            if(coun==1 && ((n-1) % (prime[i]-1))==0) carm++;
        }
        if(t>1){
            tot_pf++;
            if(((n-1) % (t-1))==0) carm++;
        }
        if(tot_pf==1) printf("%d is normal.\n",n);
        else if(tot_pf>1&&tot_pf==carm) printf("The number %d is a Carmichael number.\n",n);
        else printf("%d is normal.\n",n);
    }
    return 0;
}
