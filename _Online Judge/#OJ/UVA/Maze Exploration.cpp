#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
stack<int>S,s;
char grid[35][85];
bool visited[35][85];
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
int t,row,col,i,j,k,c,d,u,v;

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=col) return false;
    return true;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    getchar();
    while(t--){
        for(i=0;;i++){
            gets(grid[i]);
            if(grid[i][0]=='_') break;
        }
        row=i+1;
        for(i=0;i<row;i++){
            col=strlen(grid[i])+1;
            for(j=0;grid[i][j];j++){
                if(grid[i][j]=='*'||grid[i][j]=='#'){
                    S.push(i);
                    s.push(j);
                    grid[i][j]='#';
                    while(!S.empty()){
                        u=S.top();
                        v=s.top();
                        S.pop();
                        s.pop();
                        for(k=0;k<8;k++){
                            c=u+xx[k];
                            d=v+yy[k];
                            if(is_safe(c,d)&&grid[c][d]==32){
                                S.push(c);
                                s.push(d);
                                grid[c][d]='#';
                            }
                        }
                    }
                }
            }
        }
        for(i=0;i<row;i++){
            puts(grid[i]);
        }
    }
    return 0;
}
