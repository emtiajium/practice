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
int t,cases,n,r,p,q,two,five,zero;
int coun(int n,int x){
    long long zzz=x;
    int countt=0;
    while(n>=zzz){
        countt+=n/zzz;
        zzz*=x;
    }
    return countt;
}
int factor(int n,int x){
    int countt=0;
    while(n%x==0){
        n/=x;
        countt++;
    }
    return countt;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&r,&p,&q);
        two=coun(n,2)-coun(r,2)-coun(n-r,2);
        five=coun(n,5)-coun(r,5)-coun(n-r,5);
        two=two+factor(p,2)*q;
        five=five+factor(p,5)*q;
        zero=min(two,five);
        printf("Case %d: %d\n",++cases,zero);
    }
    return 0;
}
