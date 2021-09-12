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
int arr[SIZE]={INF},tree[SIZE*3];
int t,cases,n,q,i,a,b,val;

void find(int node,int low,int high){
    int mid,minn,left,right;
    if(low==high){
        tree[node]=arr[high];
        return;
    }
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    find(left,low,mid);
    find(right,mid+1,high);
    tree[node]=min(tree[left],tree[right]);
}

int query(int node,int low,int high,int i,int j){
    if(i>high || j<low) return INF;
    if(low>=i && high<=j) return tree[node];
    int left,right,mid,temp,temp2,minn;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    minn=min(temp,temp2);
    return minn;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        printf("Case %d:\n",++cases);
        find(1,1,n);
        while(q--){
            scanf("%d%d",&a,&b);
            val=query(1,1,n,a,b);
            printf("%d\n",val);
        }
    }
    return 0;
}
