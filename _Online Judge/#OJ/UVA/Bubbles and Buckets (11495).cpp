#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int SIZE=100005;
typedef long long LL;

int arr[SIZE],arrb[SIZE],tree[SIZE];
int n,i,rnk,val,coun;

int read(int idx){
    int res=0;
    while(idx>0){
        res+=tree[idx];
        idx-=(idx & -idx);
    }
    return res;
}

void update(int idx,int val){
    while(idx<=SIZE){
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
            arrb[i]=arr[i];
        }
        sort(arrb,arrb+n);
        for(i=0;i<n;i++){
            rnk=lower_bound(arrb,arrb+n,arr[i])-arrb;
            arr[i]=rnk+1;
        }
        for(i=n-1,coun=0;i>=0;i--){
            val=read(arr[i]-1);
            coun+=val;
            update(arr[i],1);
        }
        if((coun&1)==0) puts("Carlos");
        else puts("Marcelo");
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
