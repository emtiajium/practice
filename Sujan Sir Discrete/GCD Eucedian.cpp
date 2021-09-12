// GCD Eucedian
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
int cases,n,i,gcd,arr[107];
int GCD(int a,int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        gcd=GCD(arr[0],arr[1]) ;
        for(i=2;i<n;i++)
            gcd=GCD(gcd,arr[i]);
        printf("Case %d: GCD %d\n",++cases,gcd);
    }
    return 0 ;
}
/*
input
2
12 16
3
12 2 19
5
19098 12345 129876 8765 876543
output
Case 1: GCD 4
Case 2: GCD 1
Case 3: GCD 1
*/
