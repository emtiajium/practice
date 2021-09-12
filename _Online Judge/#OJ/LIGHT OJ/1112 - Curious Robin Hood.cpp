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
int arr[SIZE],tree[SIZE*3];
int t,cases,n,q,i,a,b,c,val;

void find(int node,int low,int high){
    int mid,add,left,right;
    if(low==high){
        tree[node]=arr[high];
        return;
    }
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    find(left,low,mid);
    find(right,mid+1,high);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int low,int high,int i,int j){
    if(i>high || j<low) return 0;
    if(low>=i && high<=j) return tree[node];
    int left,right,mid,temp,temp2,add;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    add=temp+temp2;
    return add;
}

void update(int node,int low,int high,int i,int val){
    if(i>high || i<low) return;
    if(low>=i && high<=i){
        tree[node]=val;
        return;
    }
    int left,right,mid;
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

    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        printf("Case %d:\n",++cases);
        find(1,1,n);
        while(q--){
            scanf("%d%d",&a,&b);
            if(a==1){
                val=query(1,1,n,b+1,b+1);
                printf("%d\n",val);
                update(1,1,n,b+1,0);
            }
            else if(a==2){
                scanf("%d",&c);
                val=query(1,1,n,b+1,b+1);
                update(1,1,n,b+1,c+val);
            }
            else{
                scanf("%d",&c);
                val=query(1,1,n,b+1,c+1);
                printf("%d\n",val);
            }
        }
    }
    return 0;
}
/*
1
5 2
1 2 3 4 5
1 2
1 2
*/
