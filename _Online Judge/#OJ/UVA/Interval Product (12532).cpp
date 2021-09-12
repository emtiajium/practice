#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;

//const double PI=2*acos(0.0);
typedef long long LL;
const int SIZE=100005;
LL arr[SIZE],tree[SIZE*3];
char str[3];
LL t,cases,n,q,i,a,b,val;

void initial(LL node,LL low,LL high){
    if(low==high){
        tree[node]=arr[high];
        return;
    }
    LL mid,mlt,left,right;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    initial(left,low,mid);
    initial(right,mid+1,high);
    tree[node]=tree[left]*tree[right];
}

LL query(LL node,LL low,LL high,LL i,LL j){
    if(i>high || j<low) return 1;
    if(low>=i && high<=j) return tree[node];
    LL left,right,mid,temp,temp2,mlt;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    mlt=temp*temp2;
    return mlt;
}

void update(LL node,LL low,LL high,LL i,LL val){
    if(i>high || i<low) return;
    if(low>=i && high<=i){
        tree[node]=val;
        return;
    }
    LL left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    update(left,low,mid,i,val);
    update(right,mid+1,high,i,val);
    tree[node]=tree[left]*tree[right];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%lld%lld",&n,&q)==2){
        for(i=1;i<=n;i++){
            scanf("%lld",&val);
            if(val>0) val=1;
            else if(val<0) val=-1;
            arr[i]=val;
        }
        initial(1,1,n);
        while(q--){
            scanf("%s %lld%lld",str,&a,&b);
            if(strcmp(str,"C")==0){
                if(b>0) b=1;
                else if(b<0) b=-1;
                update(1,1,n,a,b);
            }
            else{
                val=query(1,1,n,a,b);
                if(val==0) putchar('0');
                else if(val<0) putchar('-');
                else putchar('+');
            }
        }
        puts("");
    }
    return 0;
}
