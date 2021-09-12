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
int coun(int,int);
bool flag[805]={1,1},xlag;
int prime[145]={2};
double digit[1048590],res;
int cnd,i,j,n,b,zero,coun2,coun3;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=1;i<1048590;i++){
        digit[i]=digit[i-1]+log10(i);
    }
    cnd=29;//sqrt(800)+1
    for(i=3;i<cnd;i+=2){
        b=i+i;
        if(flag[i]==false){
            for(j=i*i;j<800;j+=b)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<800;i+=2)
        if(flag[i]==false) prime[j++]=i;
    //prime 797 size 139
    while(scanf("%d%d",&n,&b)==2){
        res=digit[n]/log10(b)+1;
        cnd=sqrt(b)+1;
        zero=n;//infinite val
        for(i=0;prime[i]<cnd&&b!=1;i++){
            xlag=false;
            coun2=0;
            while(b%prime[i]==0){
                b/=prime[i];
                coun2++;
                xlag=true;
            }
            if(xlag){
                coun3=coun(n,prime[i]);
                zero=min(zero,coun3/coun2);//#include<iostream>
            }
        }
        if(b>1){
            coun2=1;
            coun3=coun(n,b);
            zero=min(zero,coun3/coun2);
        }
        printf("%d %d\n",zero,(int)res);
    }
    return 0;
}

int coun(int n,int x){
    long long zzz=x;
    int countt=0;
    while(n>=zzz){
        countt+=n/zzz;
        zzz*=x;
    }
    return countt;
}
