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
struct TT{
    LL sum,prop;
};
TT tree[SIZE*3];

void initial(int node,int low,int high){
    if(low==high){
        tree[node].sum=arr[low];
        return;
    }
    int left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    initial(left,low,mid);
    initial(right,mid+1,high);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void update(int node,int low,int high,int i,int j,LL val){
    if(i>high || j<low) return;
    if(low>=i && high<=j){
        tree[node].sum+=(high-low+1)*val;
        tree[node].prop+=val;
    }
    int left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(low+high)>>1;
    update(left,low,mid,i,j,val);
    update(right,mid+1,high,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum+(high-low+1)*tree[node].prop;
}

int query(int node,int low,int high,int i,int j,int carry=0){
    if(i>high || j<low) return 0;
    if(low>=i && high<=j) return tree[node].sum+carry*(high-low+1);
    int left,right,mid,temp,temp2,add;
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
    return 0;
}

