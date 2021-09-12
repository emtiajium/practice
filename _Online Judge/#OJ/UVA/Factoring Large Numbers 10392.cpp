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
char s[6]={"    "};
long long n,i,sq;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%lld",&n)&&n>0){
        if(n==1){
            printf("%s1\n",s);
            continue;
        }
        while(n%2==0){
            n/=2;
            printf("%s2\n",s);
        }
        sq=sqrt(n);
        i=3;
        while(i<=sq){
            if(n%i==0){
                n/=i;
                printf("%s%lld\n",s,i);
            }
            else i+=2;
        }
        if(n>1) printf("%s%lld\n",s,n);
        puts("");
    }
    return 0;
}
