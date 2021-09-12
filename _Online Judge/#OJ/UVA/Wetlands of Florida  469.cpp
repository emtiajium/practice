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
char grid[105][105],ch;
bool visited[105][105],flag;
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
stack<int>S,s;
int t,row,col,k,u,v,c,d,rr,cc,coun;
bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}
void DFS(int rr,int cc){
    ch=grid[rr][cc];
    /*if(ch=='L' || is_safe(rr,cc)==false){
        puts("0");
        return;
        // no need of that
    }*/
    coun=1;
    S.push(rr);
    s.push(cc);
    visited[rr][cc]=true;
    while(!S.empty()){
        u=S.top();
        v=s.top();
        S.pop();
        s.pop();
        for(k=0;k<8;k++){
            c=u+xx[k];
            d=v+yy[k];
            if(is_safe(c,d) && grid[c][d]==ch && visited[c][d]==false){
                S.push(c);
                s.push(d);
                visited[c][d]=true;
                coun++;
            }
        }
    }
    printf("%d\n",coun);
    memset(visited,false,sizeof(visited));
}
int main()
{
    //freopen("input.txt","r",stdin);//input.in
    //freopen("output.txt","w",stdout);//output.out
    scanf("%d",&t);
    while(t--){
        if(flag==true) puts("");
        flag=true;
        scanf("%s",grid[0]);
        getchar();
        col=strlen(grid[0]);
        for(k=1;;k++){
            gets(grid[k]);
            if(isdigit(grid[k][0])) break;
        }
        row=k;
        sscanf(grid[k],"%d%d",&rr,&cc);
        DFS(rr-1,cc-1);
        while(scanf("%d%d",&rr,&cc)==2){
            DFS(rr-1,cc-1);
        }
    }
    return 0;
}
