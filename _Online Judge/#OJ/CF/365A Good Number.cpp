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
char str[15];
bool flag[13];
int n,k,i,j,t,coun,coun2,ans;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d%d",&n,&k)==2){
        ans=0;
        for(i=0;i<n;i++){
            scanf("%s",str);
            for(j=0;str[j];j++){
                t=str[j]-48;
                flag[t]=true;
            }
            for(j=coun=0;j<=k;j++){
                if(flag[j]==true) coun++;
            }
            memset(flag,false,sizeof(flag));
            if(coun==k+1) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
