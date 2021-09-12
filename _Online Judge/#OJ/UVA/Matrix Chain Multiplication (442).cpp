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
    int row,col;
};
TT st[130];
stack<char>stk;
int N,xx,yy,row2,col2,row3,col3,countt,i,COST;
bool flag;
char str[65];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&N)==1){
        while(N--){
            scanf("%s",str);
            xx=str[0];
            scanf("%d%d",&st[xx].row,&st[xx].col);
        }
        while(scanf("%s",str)==1){
            countt=97;
            COST=0;
            flag=false;
            for(i=0;str[i];i++){
                if(str[i]>64&&str[i]<91) stk.push(str[i]);
                else if(str[i]==')'){
                    xx=stk.top();
                    stk.pop();
                    yy=stk.top();
                    stk.pop();
                    swap(xx,yy);
                    row2=st[xx].row;
                    col2=st[xx].col;
                    row3=st[yy].row;
                    col3=st[yy].col;
                    if(col2!=row3){
                        flag=true;
                        break;
                    }
                    else{
                        stk.push(countt);//push product matrix
                        COST+=row2*col2*col3;
                        st[countt].row=row2;
                        st[countt].col=col3;
                        countt++;
                    }
                }
            }
            while(!stk.empty()){
                stk.pop();
            }
            if(flag) puts("error");
            else printf("%d\n",COST);
        }
    }
    return 0;
}
/*
2
A 1 2
B 3 1
(AB)
*/
