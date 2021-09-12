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
vector<int>v;
char str[3];
int t,cases,n,q,num,i;

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
            scanf("%d",&num);
            v.push_back(num);
        }
        printf("Case %d:\n",++cases);
        while(q--){
            scanf("%s %d",str,&num);
            num--;
            if(strcmp(str,"c")==0){
                if(v.size()-1<num) puts("none");
                else{
                    printf("%d\n",v[num]);
                    v.erase(v.begin()+num);
                }
            }
            else{
                v.push_back(num+1);
            }
        }
        v.clear();
    }
    return 0;
}
