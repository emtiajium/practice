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
int countz(int,int);
bool flag[75]={1,1},xlag;
int prime[25]={2};
int t,cases,m,n,coun,coun2,coun3,i,j,r,cnd;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=3;i<9;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<72;j+=r)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<72;i+=2)
        if(flag[i]==false) prime[j++]=i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&m,&n);
        cnd=sqrt(m)+1;
        coun=n;//infinite val
        for(i=0;prime[i]<cnd&&m!=1;i++){
            xlag=false;
            coun2=0;
            while(m%prime[i]==0){
                m/=prime[i];
                coun2++;
                xlag=true;
            }
            if(xlag){
                coun3=countz(n,prime[i]);
                coun=min(coun,coun3/coun2);//#include<iostream>
            }
        }
        if(m>1){
            coun2=1;
            coun3=countz(n,m);
            coun=min(coun,coun3/coun2);
        }
        if(coun) printf("Case %d:\n%d\n",++cases,coun);
        else printf("Case %d:\nImpossible to divide\n",++cases);
    }
    return 0;
}

int countz(int n,int x){
    long long zzz=x;
    int countt=0;
    while(n>=zzz){
        countt+=n/zzz;
        zzz*=x;
    }
    return countt;
}
