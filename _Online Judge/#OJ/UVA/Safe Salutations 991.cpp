#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
int n,i,k,cata[15];
long long sum,sum2;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(k=1;k<12;k++){
        for(i=2,sum=sum2=1;i<=k;i++){
            sum*=k+i;
            sum2*=i;
            if(sum%sum2==0){
                sum=sum/sum2;
                sum2=1;
            }
        }
        cata[k]=sum/sum2;
    }
    k=0;
    while(scanf("%d",&n)==1){
        if(k!=0) puts("");
        printf("%d\n",cata[n]);
        k++;

    }
    return 0;
}


