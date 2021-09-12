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

//const double PI=2*acos(0.0);
char str[105],str2[105],res[105];
int i,t,t2;

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%s %s",str,str2)==2){
        for(i=0;str[i];i++){
            t=str[i]-48;
            t2=str2[i]-48;
            t=t^t2;
            res[i]=t+48;
        }
        res[i]=NULL;
        puts(res);
    }
    return 0;
}
