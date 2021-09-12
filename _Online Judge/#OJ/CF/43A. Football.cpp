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
int n,i,j,t,high,ans;
string str[105],temp;
map<string,int>MP;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            cin>>str[i];
            temp=str[i];
            MP[temp]++;
        }
        for(i=high=0;i<n;i++){
            temp=str[i];
            t=MP[temp];
            if(t>high){
                ans=i;
                high=t;
            }
        }
        cout<<str[ans]<<endl;
        MP.clear();
    }
    return 0;
}
