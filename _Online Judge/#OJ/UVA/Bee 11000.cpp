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
long long bee[170]={0,1,2};
long long i,n;
int main()
{
    for(i=3;i<160;i++){
        bee[i]=bee[i-1]+bee[i-2]+1;
    }
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%lld",&n)&&n!=-1){
        printf("%lld %lld\n",bee[n],bee[n+1]);
    }
    return 0;
}
