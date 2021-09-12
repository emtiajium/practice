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
struct TT{
    int aa,bb;
};
TT arr[500005];
bool flag[500005];
int N,i,j,coun;

bool comp(TT a,TT b){
    if(a.aa==b.aa) return a.bb<b.bb;
    return a.aa<b.aa;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d",&N)&&N){
        for(i=0;i<N;i++){
            scanf("%d%d",&arr[i].aa,&arr[i].bb);
        }
        sort(arr,arr+N,comp);
        //puts("after");for(i=0;i<N;i++) printf("%d %d\n",arr[i].aa,arr[i].bb);
        coun=0;
        for(i=0;i<N;i++){
            if(flag[i]==false){
                for(j=i+1;j<N;j++){
                    if(arr[j].aa>arr[i].bb) break;
                    else if(arr[i].aa==arr[j].bb && arr[i].bb==arr[j].aa && flag[j]==false){
                        flag[j]=true;
                        flag[i]=true;
                        coun+=2;
                        break;
                    }
                }
            }
        }
        //cout<<coun<<endl;
        if(coun==N) puts("YES");
        else puts("NO");
        memset(flag,false,sizeof(flag));
    }
    return 0;
}
