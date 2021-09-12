#include <bits/stdc++.h>
using namespace std;

const double PI=2*acos(0.0);
const int SIZE=100005;
int tree[SIZE];
int t,cases,i,n,q,a,b,c,val;

int query(int idx){
    int res=0;
    while(idx>0){
        res+=tree[idx];
        idx-=(idx & -idx);
    }
    return res;
}

void update(int idx,int val){
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
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++){
            scanf("%d",&val);
            update(i+1,val);
        }
        printf("Case %d:\n",++cases);
        while(q--){
            scanf("%d%d",&a,&b);
            if(a==1){
                b++;
                val=query(b)-query(b-1);
                printf("%d\n",val);
                update(b,-val);
            }
            else if(a==2){
                b++;
                scanf("%d",&c);
                update(b,c);
            }
            else{
                scanf("%d",&c);
                b++; c++;
                val=query(c)-query(b-1);
                printf("%d\n",val);
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
