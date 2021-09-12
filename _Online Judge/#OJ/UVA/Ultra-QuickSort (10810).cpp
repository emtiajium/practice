#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int SIZE=500005;
typedef long long LL;

LL arr[SIZE],arrb[SIZE],tree[SIZE];
LL n,i,rnk,val,coun;

LL read(LL idx){
    LL res=0;
    while(idx>0){
        res+=tree[idx];
        idx-=(idx & -idx);
    }
    return res;
}

void update(LL idx,LL val){
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

    while(scanf("%lld",&n)&&n){
        for(i=0;i<n;i++){
            scanf("%lld",&arr[i]);
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
        printf("%lld\n",coun);
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
