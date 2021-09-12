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
const int INF=1<<30,SIZE=30005;
int arr[SIZE],tree[3*SIZE],pos[3*SIZE];
int t,cases,i,m,n;

void find(int node,int low,int high){
	if(low==high){
		tree[node]=arr[low];
		pos[node]=low;
		return;
	}
	int left,right,mid;
	left=node<<1;
	right=left+1;
	mid=(low+high)>>1;
	find(left,low,mid);
	find(right,mid+1,high);
	if(tree[left]<tree[right])
        pos[node]=pos[left];
	else
		pos[node]=pos[right];
	tree[node]=min(tree[left],tree[right]);
}

int query(int node,int low,int high,int i,int j){
	if(i>high||j<low) return INF;
	if(low>=i&&high<=j) return pos[node];
	int left,right,mid,temp,temp2;
	left=node<<1;
	right=left+1;
	mid=(low+high)>>1;
	temp=query(left,low,mid,i,j);
	temp2=query(right,mid+1,high,i,j);
	if(temp==INF || temp2==INF) return min(temp,temp2);
	if(arr[temp]<arr[temp2]) return temp;
	return temp2;
}

int area(int low,int high){
    if(low==high) return arr[low];
    if(low<0 || high>m || high<low) return 0;
    int temp,Aa,Ab,Ba,Bb,len,ans;
    temp=query(1,0,n-1,low,high);
    Aa=low;
    Ab=temp-1;
    Ba=temp+1;
    Bb=high;
    len=high-low+1;
    ans=max(arr[temp]*len,max(area(Aa,Ab),area(Ba,Bb)));
    return ans;
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
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        find(1,0,n-1);
        m=n-1;
        printf("Case %d: %d\n",++cases,area(0,n-1));
	}
	return 0;
}
