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
bool visited[105][105],flag;
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
int row,col,i,j,k,u,v,c,d,coun;

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&row,&col)&&(row>0&&col>0)){
        getchar();
        for(i=0;i<row;i++)
            scanf("%s",grid[i]);

        coun=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                flag=false;
                if(grid[i][j]=='*'&&visited[i][j]==false){
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
                            if(is_safe(c,d)&&visited[c][d]==false&&grid[c][d]=='*'){
                                S.push(c);
                                s.push(d);
                                visited[c][d]=true;
                                flag=true;
                            }
                        }
                    }
                    if(!flag) coun++;
                }
            }
        }
        printf("%d\n",coun);
        memset(visited,0,sizeof(visited));
    }
    return 0;
}
