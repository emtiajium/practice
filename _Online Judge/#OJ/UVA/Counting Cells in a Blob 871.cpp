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
char grid[30][30];
bool visited[30][30];
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
int t,row,col,i,j,k,c,d,u,v,coun[30],z,b_line;

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}
bool comp(int a,int b){
    return a>b;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--){
        if(b_line) puts("");
        scanf("%s",grid[0]);
        col=strlen(grid[0]);
        if(!strcmp(grid[0],"1")){
            puts("1");
            b_line++;
            continue;
        }
        for(i=1;i<col;i++){
            scanf("%s",grid[i]);
        }
        getchar();
        row=i;
        z=0;
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
                                coun[z]++;
                                visited[c][d]=true;
                            }
                        }
                    }
                    z++;
                }
            }
        }
        sort(coun,coun+z,comp);
        printf("%d\n",coun[0]);
        b_line++;
        memset(visited,0,sizeof(visited));
        memset(coun,0,sizeof(coun));
    }
    return 0;
}
