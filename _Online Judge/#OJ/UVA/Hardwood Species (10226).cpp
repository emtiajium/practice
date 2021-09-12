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
struct TT{
    string tree;
    int tottree;
};
TT stt[10005];
string str;
char str2[35];
int t,test,countt,x,i,asg;
map<string,int>MP;
bool comp(TT a,TT b){
    return a.tree<b.tree;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    gets(str2);
    while(t--){
        if(test!=0) puts("");
        countt=asg=0;
        while(gets(str2) && strlen(str2)){
            str=str2;
            countt++;
            if(MP.find(str)==MP.end()) MP[str]=asg++;
            x=MP[str];
            stt[x].tree=str;
            stt[x].tottree++;
        }
        x=MP.size();
        sort(stt,stt+x,comp);
        for(i=0;i<x;i++){
            cout<<stt[i].tree;
            printf(" %.4lf\n",(stt[i].tottree*100.0)/countt);
        }
        MP.clear();
        str.clear();
        for(i=0;i<x;i++){
            stt[i].tottree=0;
        }
        test++;
    }
    return 0;
}
