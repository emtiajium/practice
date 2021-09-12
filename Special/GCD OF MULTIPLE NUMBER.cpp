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
int  n,i,gcd,lcm,arr[100];
int GCD(int a,int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}
int LCM(int i,int j){
    int lcm=(i/GCD(i,j))*j;
    return lcm;
}

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        gcd=GCD(arr[0],arr[1]) ;
        lcm=(arr[0]*arr[1])/gcd;
        for(i=2;i<n;i++){
            gcd=GCD(gcd,arr[i]);
            lcm=LCM(lcm,arr[i]);
        }
        printf("GCD %d\n",gcd);
        printf("LCM %d\n",lcm);
    }
    return 0 ;
}
