#include <bits/stdc++.h>
using namespace std;

const int SIZE=100005;
int tree[SIZE];
int t,cases,i,n,q,a,b,choice,val;

int query(int idx){
    int res=0;
    while(idx>0){
        res+=tree[idx];
        idx-=(idx & -idx); // or idxx & (idx ^ (idx - 1));
    }
    return res;
}

void update(int idx,int val){
    printf("%d ",idx);
    while(idx<=n){
        tree[idx]+=val;
        idx+=(idx & -idx);
        printf("%d ",idx);
    }
    puts("");
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
        //for(i=0;i<=n;i++) printf("%d %d\n",i,tree[i]);puts("");
        puts("1 for query, 2 for update");
        while(q--){
            scanf("%d",&choice);
            if(choice==1){
                scanf("%d%d",&a,&b);
                val=query(b)-query(a-1);
                printf("%d\n",val);
            }
            else{
                scanf("%d%d",&a,&val);
                update(a,val);
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
