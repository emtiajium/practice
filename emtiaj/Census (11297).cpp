#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=505,INF=1<<30;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

struct TT{
    int high,low;
};
TT t2,t3,t4,t5;
int t,cases,row,col,q,i,j,a,b,c,d,val;
char str[7];
int arr[SIZE][SIZE],max_tree[SIZE][SIZE],min_tree[SIZE][SIZE];

void update(int r, int c, int val){
    int i,j;
    for(i=r;i<=row;i+=(i & -i)){
        for(j=c;j<=col;j+=(j & -j)){
            max_tree[i][j]=max(max_tree[i][j],val);
            min_tree[i][j]=min(min_tree[i][j],val);        }
    }
}

TT query(int r, int c){
    int i,j,res=-INF,res2=INF;
    for(i=r;i>0;i-=(i & -i)){
        for(j=c;j>0;j-=(j & -j)){
            res=max(res,max_tree[i][j]);
            res2=min(res,min_tree[i][j]);
        }
    }
    TT local={res,res2};
    return local;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d%d",&row,&col)==2){
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                scanf("%d",&arr[i][j]);
                update(i,j,arr[i][j]);
            }
        }
        scanf("%d",&q);
        while(q--){
            scanf("%s",str);
            if(str[0]=='q'){
                scanf("%d%d%d%d",&a,&b,&c,&d);
                t2=query(c,d);
                t3=query(a-1,d);
                t4=query(c,b-1);
                t5=query(a-1,b-1);
                printf("%d %d\n",max(t2.high,t5.high),min(t2.low,t5.low));
            }
            else{
                scanf("%d%d%d",&a,&b,&val);
                update(a,b,-arr[a][b]+val);
                arr[a][b]=val;
            }
        }
        memset(max_tree,0,sizeof(max_tree));
        memset(min_tree,0,sizeof(min_tree));
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
