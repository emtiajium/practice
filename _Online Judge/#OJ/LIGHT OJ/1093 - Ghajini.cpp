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
const int SIZE=100005,INF=1<<30;
struct TT{
    int aa,bb;
};
int arr[SIZE];
TT tree[SIZE*3],val;
int t,cases,n,d,i,a,b,high;

void find(int node,int low,int high){
    int mid,minn,left,right;
    if(low==high){
        tree[node]={arr[high],arr[high]};
        return;
    }
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    find(left,low,mid);
    find(right,mid+1,high);
    tree[node].aa=min(tree[left].aa,tree[right].aa);
    tree[node].bb=max(tree[left].bb,tree[right].bb);
}

TT query(int node,int low,int high,int i,int j){
    if(i>high || j<low){
        TT ll={INF,-1};
        return ll;
    }
    if(low>=i && high<=j) return tree[node];
    int left,right,mid,minn,maxx;
    TT temp,temp2,local;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    minn=min(temp.aa,temp2.aa);
    maxx=max(temp.bb,temp2.bb);
    local={minn,maxx};
    return local;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        find(1,0,n-1);
        high=0;d--;
        for(i=0;i<n;i++){
            a=i;
            b=i+d;
            if(b>=n) break;
            val=query(1,0,n-1,a,b);
            high=max(high,val.bb-val.aa);
        }
        printf("Case %d: %d\n",++cases,high);
    }
    return 0;
}
