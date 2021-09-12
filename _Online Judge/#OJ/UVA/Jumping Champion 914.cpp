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
struct TT{
    int val,countt;
};
TT coun[78501];
bool comp(TT a,TT b){
    return a.countt>b.countt;
}

const int SIZE=1000005;
bool flag[SIZE]={true,true};
int prime[78501]={2},arr[78501];
int i,j,m,t,l,u,diff;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=4;i<SIZE;i+=2)
        flag[i]=true;
    for(i=3;i<1001;i+=2){
        m=i+i;
        if(flag[i]==false){
            for(j=i*i;j<SIZE;j+=m)
                flag[j]=true;
        }
    }
    for(i=3,j=1;i<SIZE;i+=2)
        if(flag[i]==false)prime[j++]=i;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&u);
        for(i=j=0;;i++){
            if(prime[i]>=l&&prime[i]<=u){
                arr[j++]=prime[i];
            }
            else if(prime[i]>u) break;
        }
        j--;
        for(i=m=0;i<j;i++){
            diff=arr[i+1]-arr[i];
            if(diff>m) m=diff;
            coun[diff].val=diff;
            coun[diff].countt++;
        }
        sort(coun,coun+m+1,comp);
        if(coun[0].countt==coun[1].countt) puts("No jumping champion");//only most frequent diff is ans
        else if(coun[0].countt>0&&coun[1].countt==0) printf("The jumping champion is %d\n",coun[0].val);//generate only one diff
        else if(coun[0].countt>0&&coun[1].countt<coun[0].countt) printf("The jumping champion is %d\n",coun[0].val);
        else puts("No jumping champion");
        memset(coun,0,sizeof(coun));
    }
    return 0;
}
