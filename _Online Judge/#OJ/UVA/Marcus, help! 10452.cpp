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

char grid[105][105];
bool visited[105][105];
char str[]="@IEHOVA#";
int xx[]={0,0,-1};
int yy[]={-1,1,0};//L,R,F
stack<int>S,s;
int t,row,col,i,j,k,m,c,d,u,v;

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&row,&col);
        getchar();
        for(i=0;i<row;i++)
            scanf("%s",grid[i]);
        m=0;
        for(i=row-1;i>=0;i--){
            for(j=0;j<col;j++){
                if(grid[i][j]==str[m]&&visited[i][j]==false){
                    m++;
                    S.push(i);
                    s.push(j);
                    while(!S.empty()){
                        u=S.top();
                        v=s.top();
                        S.pop();
                        s.pop();
                        for(k=0;k<3;k++){
                            c=u+xx[k];
                            d=v+yy[k];
                            if(is_safe(c,d)&&grid[c][d]==str[m]&&visited[c][d]==false){
                                if(k==0) printf("left");
                                else if(k==1) printf("right");
                                else if(k==2) printf("forth");
                                if(grid[c][d]!='#') putchar(' ');
                                m++;
                                S.push(c);
                                s.push(d);
                                visited[c][d]=true;
                            }
                        }
                    }
                }
            }
        }
        puts("");
        memset(visited,0,sizeof(visited));
    }
    return 0;
}
