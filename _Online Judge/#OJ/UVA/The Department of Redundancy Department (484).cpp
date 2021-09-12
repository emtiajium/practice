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
stringstream sstr;
map<int,int>MP;
char str[100005];
struct TT{
    int val,countt;
};
TT stt[100005];
int asg,x,i,temp;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(gets(str)){
        sstr<<str;
        while(sstr>>temp){
            if(MP.find(temp)==MP.end()) MP[temp]=asg++;
            x=MP[temp];
            stt[x].val=temp;
            stt[x].countt++;
        }
        sstr.clear();
    }
    x=MP.size();
    for(i=0;i<x;i++){
        printf("%d %d\n",stt[i].val,stt[i].countt);
    }
    MP.clear();
    return 0;
}
