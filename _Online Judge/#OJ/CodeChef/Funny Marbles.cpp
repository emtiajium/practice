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
const int SIZE=1000005;
LL arr[SIZE],tree[SIZE*3];
LL t,cases,test,n,q,i,a,b,val;
char str[5];

void initial(LL node,LL low,LL high){
    if(low==high){
        tree[node]=arr[high];
        return;
    }
    LL mid,add,left,right;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    initial(left,low,mid);
    initial(right,mid+1,high);
    tree[node]=tree[left]+tree[right];
}

LL query(LL node,LL low,LL high,LL i,LL j){
    if(i>high || j<low) return 0;
    if(low>=i && high<=j) return tree[node];
    LL left,right,mid,temp,temp2,add;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    add=temp+temp2;
    return add;
}

void update(LL node,LL low,LL high,LL i,LL val){
    if(i>high || i<low) return;
    if(low>=i && high<=i){
        tree[node]+=val;
        return;
    }
    LL left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    update(left,low,mid,i,val);
    update(right,mid+1,high,i,val);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%lld%lld",&n,&q)==2){
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        initial(1,0,n-1);
        while(q--){
            scanf("%s %lld%lld",str,&a,&b);
            if(strcmp(str,"S")==0){
                val=query(1,0,n-1,a,b);
                printf("%lld\n",val);
            }
            else if(strcmp(str,"G")==0){
                //val=query(1,0,n-1,a,a);
                //update(1,0,n-1,a,val+b);
                update(1,0,n-1,a,b);
            }
            else{
                //val=query(1,0,n-1,a,a);
                //update(1,0,n-1,a,val-b);
                update(1,0,n-1,a,-b);
            }
        }
    }
    return 0;
}
