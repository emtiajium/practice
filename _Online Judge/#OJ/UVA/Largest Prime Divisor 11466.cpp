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
long long n,i,sq,high,tot_pf;
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%lld",&n)&&n){
        tot_pf=0;
        if(n<0) n=-n;
        if(n==1) tot_pf=1;
        flag=false;
        while(n%2==0){
            n/=2;
            flag=true;
        }
        if(flag) tot_pf++;
        sq=sqrt(n)+1;
        high=0;
        for(i=3;i<sq&&n!=1;i+=2){
            flag=false;
            while(n%i==0){
                n/=i;
                flag=true;
            }
            if(flag){
                tot_pf++;
                high=i;
            }
        }
        if(n>1){
            tot_pf++;
            high=n;
        }
        if(tot_pf==1) puts("-1");
        else printf("%lld\n",high);
    }
    return 0;
}
