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
int arr[55],cases,N,i,sum,t,avg;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d",&N)&&N){
        for(i=sum=0;i<N;i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        avg=sum/N;
        for(i=sum=0;i<N;i++){
            t=arr[i]-avg;
            if(t>0) sum+=t;
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n",++cases,sum);
        puts("");
    }
    return 0;
}

