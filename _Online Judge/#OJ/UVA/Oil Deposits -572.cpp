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

stack<int>S,s;
char grid[105][105];
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
int row,col,i,j,k,c,d,u,v,coun;

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&row,&col)&&row){
        getchar();
        for(i=0;i<row;i++){
            scanf("%s",grid[i]);
        }
        coun=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(grid[i][j]=='@'){
                    S.push(i);
                    s.push(j);
                    while(!S.empty()){
                        u=S.top();
                        v=s.top();
                        S.pop();
                        s.pop();
                        for(k=0;k<8;k++){
                            c=u+xx[k];
                            d=v+yy[k];
                            if(is_safe(c,d)&&grid[c][d]=='@'){
                                S.push(c);
                                s.push(d);
                                grid[c][d]='n';
                            }
                        }
                    }
                    coun++;
                }
            }
        }
        printf("%d\n",coun);
    }
    return 0;
}
