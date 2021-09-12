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
const int SIZE=1000005;
bool flag[SIZE]={true,true};
long long cnd,i,j,r,n,m;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    for(i=4;i<SIZE;i+=2)
        flag[i]=true;
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(flag[i]==false){
            for(j=i*i,r=i<<1;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    while(cin>>m){
        while(m--){
            cin>>n;
            cnd=sqrt(n);
            if(cnd*cnd==n && flag[cnd]==false) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
