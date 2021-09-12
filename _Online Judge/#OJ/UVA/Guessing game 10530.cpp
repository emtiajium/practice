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
char str[105][15];
int val[105],i,size;
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    i=0;
    while(scanf("%d",&val[i])&&val[i]){
        getchar();
        gets(str[i]);
        if(!strcmp(str[0],"right on")){
            puts("Stan may be honest");
            continue;
        }
        for(i=1;;i++){
            scanf("%d",&val[i]);
            getchar();
            gets(str[i]);
            if(!strcmp(str[i],"right on")) break;
        }
        size=i;
        //printf("S %d val %d\n",size,val[size]);
        flag=false;
        for(i=0;i<size;i++){
            if(!strcmp(str[i],"too high")){
                if(val[i]>val[size]){
                    flag=false;
                }
                else{
                    flag=true;
                    break;
                }
            }
            if(!strcmp(str[i],"too low")){
                if(val[i]<val[size]){
                    flag=false;
                }
                else{
                    flag=true;
                    break;
                }
            }
        }
        if(flag) puts("Stan is dishonest");
        else puts("Stan may be honest");
        i=0;
    }
    return 0;
}

