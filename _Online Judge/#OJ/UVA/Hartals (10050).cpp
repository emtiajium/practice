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

//const double PI=3.14159265358979323846264338327950288419716939937511;
int arr[105],test,N,para,i,j,countt;
bool flag[3655];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&test);
    while(test--){
        scanf("%d%d",&N,&para);
        for(i=0;i<para;i++){
            scanf("%d",&arr[i]);
        }
        for(i=0;i<para;i++){
            for(j=arr[i];j<=N;j+=arr[i]){
                //if(j%7==6) continue; // friday
                //else if(j%7==0) continue; // sat
                if((j+1)%7 < 2) continue;
                flag[j]=true;
            }
        }
        for(i=1,countt=0;i<=N;i++){
            if(flag[i]==true) countt++;
        }
        printf("%d\n",countt);
        memset(flag,false,sizeof(flag));
    }
    return 0;
}

