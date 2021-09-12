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
map<string,int>MP;
string str;
int test,cases,n,xx,D,days;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&test);
    while(test--){
        scanf("%d",&n);
        while(n--){
            cin>>str>>days;
            MP[str]=days;
        }
        scanf("%d",&D);
        cin>>str;
        printf("Case %d: ",++cases);
        if(MP.find(str)!=MP.end()){
            xx=MP[str];
            if(xx<=D) puts("Yesss");
            else if(xx>D && xx<=D+5) puts("Late");
            else if(xx>D+5) puts("Do your own homework!");
        }
        else puts("Do your own homework!");
        MP.clear();
        str.clear();
    }
    return 0;
}
