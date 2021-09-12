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
string arr[100005],str,str2;
map<string,int> MP;
char str3[25],str4[25],str5[25];
int x,asg;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(gets(str3) && strlen(str3)){
        sscanf(str3,"%s %s",str4,str5);
        str=str4;
        str2=str5;
        if(MP.find(str2)==MP.end()) MP[str2]=asg++;
        x=MP[str2];
        arr[x]=str;
    }
    while(cin>>str){
        if(MP.find(str)==MP.end()){
            puts("eh");
            continue;
        }
        x=MP[str];
        cout<<arr[x]<<endl;
    }
    MP.clear();
    return 0;
}
