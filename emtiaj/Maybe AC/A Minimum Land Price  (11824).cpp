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
int test,arr[43],i,size,sum;

bool comp(int a, int b){
    return a>b;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    scanf("%d",&test);
    while(test--){
        i=0;
        while(scanf("%d",&arr[i++])&&arr[i-1]){}
        size=i-1;
        sort(arr,arr+size,comp);
        for(i=sum=0;i<size;i++){
            sum+=2*(int)pow((double)arr[i],i+1);
        }
        if(sum>5000000) puts("Too expensive");
        else printf("%d\n",sum);
    }
    return 0;
}
