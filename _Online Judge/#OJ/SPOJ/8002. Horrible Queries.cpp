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
const int SIZE=100005;
struct TT{
    long long sum,prop;
};
TT tree[SIZE*3];
long long arr[SIZE];
long long t,N,q,a,b,c,d,val;

void update(long long node,long long low,long long high,long long i,long long j,long long val){
    if(i>high || j<low) return;
    if(low>=i && high<=j){
        tree[node].sum+=(high-low+1)*val;
        tree[node].prop+=val;
        return;
    }
    long long left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    update(left,low,mid,i,j,val);
    update(right,mid+1,high,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum+(high-low+1)*tree[node].prop;
}

long long query(long long node,long long low,long long high,long long i,long long j,long long carry=0){
    if(i>high || j<low) return 0;
    if(low>=i && high<=j) return tree[node].sum+carry*(high-low+1);
    long long left,right,mid;
    long long temp,temp2,add;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j,carry+tree[node].prop);
    temp2=query(right,mid+1,high,i,j,carry+tree[node].prop);
    add=temp+temp2;
    return add;

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&N,&q);
        memset(arr,0,sizeof(arr));
        memset(tree,0,sizeof(tree));
        while(q--){
            scanf("%lld%lld%lld",&a,&b,&c);
            if(a==0){
                scanf("%lld",&d);
                update(1,1,N,b,c,d);
            }
            else{
                val=query(1,1,N,b,c);
                printf("%lld\n",val);
            }
        }
    }
    return 0;
}

