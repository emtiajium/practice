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
long long n,m,x,last,sum;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%lld",&n)==1){
        m=(n+1)/2;
        x=m*(m+1)-m;
        last=2*x-1;
        sum=3*last-6;
        printf("%lld\n",sum);
    }
    return 0;
}
