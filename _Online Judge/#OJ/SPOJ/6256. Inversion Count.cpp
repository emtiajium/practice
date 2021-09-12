#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int SIZE=200005;
typedef long long LL;

LL arr[SIZE],arrb[SIZE],tree[SIZE];
LL t,n,i,val,coun,asg;
map<LL,LL>MP;

LL read(LL idx){
    LL res=0;
    while(idx>0){
        res+=tree[idx];
        idx-=(idx & -idx);
    }
    return res;
}

void update(LL idx,LL val){
    while(idx<=n){
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

    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            arrb[i]=arr[i];
        }
        sort(arrb,arrb+n);
        asg=1;
        for(i=0;i<n;i++){
            if(MP.find(arrb[i])==MP.end()) MP[arrb[i]]=asg++;
        }
        for(i=0;i<n;i++){
            arr[i]=MP[arr[i]];
        }
        for(i=n-1,coun=0;i>=0;i--){
            val=read(arr[i]-1);
            coun+=val;
            update(arr[i],1);
        }
        printf("%lld\n",coun);
        memset(tree,0,sizeof(tree));
        MP.clear();
    }
    return 0;
}
/*
Take care about two things:
1. The output would exceed INT_MAX, use long long instead
2. Duplicate numbers
*/
