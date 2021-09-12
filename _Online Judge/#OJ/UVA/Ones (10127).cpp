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
string divident;
int divisor,i,k,temp,mod;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    while(scanf("%d",&divisor)==1){
        do{
            divident+="1";
            for(i=k=0;divident[i];i++){
                temp=(divident[i]-48)+k;
                mod=temp%divisor;
                k=mod*10;
            }
        }
        while(mod!=0);
        printf("%d\n",divident.size());
        divident.clear();
    }
    return 0;
}

