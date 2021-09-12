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
int arr[5],t,cases;

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);
        sort(arr,arr+3);
        if(arr[0]*arr[0]+arr[1]*arr[1]==arr[2]*arr[2]) printf("Case %d: yes\n",++cases);
        else printf("Case %d: no\n",++cases);
    }
    return 0;
}
