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

char grid[30][30];
bool visited[30][30];
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
stack<int>S,s;
int row,col,i,j,k,c,d,u,v,coun,cases;

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&row)==1){
        getchar();
        col=row;
        for(i=0;i<row;i++){
            scanf("%s",grid[i]);
        }
        coun=0;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                if(grid[i][j]=='1'&&visited[i][j]==false){
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
                            if(is_safe(c,d)&&grid[c][d]=='1'&&visited[c][d]==false){
                                S.push(c);
                                s.push(d);
                                visited[c][d]=true;
                            }
                        }
                    }
                    coun++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",++cases,coun);
        memset(visited,0,sizeof(visited));
    }
    return 0;
}
