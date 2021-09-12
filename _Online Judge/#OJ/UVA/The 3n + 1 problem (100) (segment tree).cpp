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
const int SIZE=1000005;
int arr[SIZE],tree[SIZE*3];
int a,b,val;

int func(int n){
    if(arr[n]!=-1) return arr[n];
    int m=n,coun=1;
    while(n!=1){
        if(n&1) n=n+n+n+1;
        else n=n>>1;
        coun++;
    }
    arr[m]=coun;
    return arr[m];
}

void find(int node,int low,int high){
    int mid,maxx,left,right;
    if(low==high){
        arr[high]=func(high);
        tree[node]=arr[high];
        return;
    }
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    find(left,low,mid);
    find(right,mid+1,high);
    tree[node]=max(tree[left],tree[right]);
}

int query(int node,int low,int high,int i,int j){
    if(i>high || j<low) return -1;
    if(low>=i && high<=j) return tree[node];
    int left,right,mid,temp,temp2,maxx;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    temp=query(left,low,mid,i,j);
    temp2=query(right,mid+1,high,i,j);
    maxx=max(temp,temp2);
    return maxx;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    memset(arr,-1,sizeof(arr));
    while(scanf("%d%d",&a,&b)==2){
        printf("%d %d ",a,b);
        if(a>b) swap(a,b);
        find(1,a,b);
        val=query(1,a,b,a,b);
        printf("%d\n",val);
    }
    return 0;
}
