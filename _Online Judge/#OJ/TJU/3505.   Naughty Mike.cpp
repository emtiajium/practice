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
int t,cases,test,n,q,i,a,b,val;
char str[15];

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
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        find(1,1,n);
        scanf("%d",&q);
        while(q--){
            scanf("%s %d %d",str,&a,&b);
            if(strcmp(str,"Inquire")==0){
                val=query(1,1,n,a,b);
                printf("%d\n",val);
            }
            else if(strcmp(str,"Add")==0){
                val=query(1,1,n,a,a);
                update(1,1,n,a,b+val);
            }
            else{
                val=query(1,1,n,a,a);
                if(val<b) update(1,1,n,a,0);
                else update(1,1,n,a,val-b);
            }
        }
    }
    return 0;
}
