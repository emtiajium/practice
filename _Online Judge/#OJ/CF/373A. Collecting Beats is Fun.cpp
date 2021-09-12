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

const double PI=2*acos(0.0);
const int SIZE=100005;
typedef long long LL;
int arr[15];
char str[7];
int k,i,j,p,coun;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&k)==1){
        for(i=0;i<4;i++){
            scanf("%s",str);
            for(j=0;str[j];j++){
                if(str[j]=='.') continue;
                p=str[j]-48;
                arr[p]++;
            }
        }
        p=k*2;
        for(i=coun=0;i<12;i++){
            if(arr[i]==0) continue;
            if(arr[i]>p) coun++;
        }
        if(coun) puts("NO");
        else puts("YES");
    }
    return 0;
}
