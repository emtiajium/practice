#include <bits/stdc++.h>
using namespace std;

//const double PI=2*acos(0.0);
const int SIZE=1027;
typedef long long LL;
#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)

int t,cases,n,q,i,a,b,c,d,t2,val;
char str[7];
int arr[SIZE][SIZE],tree[SIZE][SIZE];

void update(int r, int c, int val){
    int i,j;
    for(i=r;i<=n;i+=(i & -i)){
        for(j=c;j<=n;j+=(j & -j)){
            tree[i][j]+=val;
        }
    }
}

int query(int r, int c){
    int i,j,res=0;
    for(i=r;i>0;i-=(i & -i)){
        for(j=c;j>0;j-=(j & -j)){
            res+=tree[i][j];
        }
    }
    return res;
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
        while(scanf("%s",str)==1){
            if(strcmp(str,"END")==0) break;
            else if(strcmp(str,"SUM")==0){
                scanf("%d%d%d%d",&a,&b,&c,&d);
                a++;b++;c++;d++;
                t2=query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1);
                printf("%d\n",t2);
            }
            else{
                scanf("%d%d%d",&a,&b,&val);
                a++;b++;
                update(a,b,-arr[a][b]+val);
                arr[a][b]=val;
            }
        }
        memset(tree,0,sizeof(tree));
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
