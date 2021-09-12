#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int SIZE=100005;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

struct TT{
    int num,indx;
};
LL arr[SIZE],tree[SIZE];
LL n,i,val,coun,asg,MOD=1000000007;
int t,cases;
map<LL,LL>MP;
TT arrb[SIZE];

bool comp(TT a, TT b){
    if(a.num==b.num) return a.indx>b.indx;
    return a.num<b.num;
}

LL read(LL idx){
    LL res=0;
    while(idx>0){
        res=(res+tree[idx])%MOD;
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

    scanf("%d",&t);
    while(t--){
        SLL(n);
        for(i=0;i<n;i++){
            SLL(arr[i]);
            arrb[i]={arr[i],i};
        }
        sort(arrb,arrb+n,comp);
        asg=1;
        for(i=0;i<n;i++){
            if(MP.find(arrb[i].num)==MP.end()) MP[arrb[i].num]=asg++;
        }
        for(i=0;i<n;i++){
            arr[i]=MP[arr[i]];
        }
        for(i=0,coun=0;i<n;i++){
            val=read(arr[i]-1)+1;
            coun=(coun+val)%MOD;
            update(arr[i],val);
        }
        printf("Case %d: %lld\n",++cases,coun%MOD);
        memset(tree,0,sizeof(tree));
        MP.clear();
    }
    return 0;
}
