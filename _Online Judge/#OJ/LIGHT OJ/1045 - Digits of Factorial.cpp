#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int SIZE=1000005;
double sum[SIZE],res;//log10(1) = 0; not 1;
int t,cases,i,n,b;
int main()
{
    //freopen("input.txt","r",stdin);
    for(i=2;i<SIZE;i++)
        sum[i]=sum[i-1]+log10(i);

    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&b);
        printf("Case %d: ",++cases);
        res = sum[n];
        res = res/log10(b)+1;
        printf("%d\n",(int)res);
    }
    return 0;
}
