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
//const double PI=3.14159265358979323846264338327950288419716939937511;

stack<int>S,s;
char grid[105][105];
bool visited[105][105];
int arr[30];
int xx[]={0,0,-1,-1,-1,1,1,1};
int yy[]={-1,1,1,0,-1,0,-1,1};
int t,cases,row,i,j,k,m,p,c,d,u,v,count1,count2;

bool comp_i(int a,int b){
    return a>b;
}

bool is_safe(int c,int d){
    if(c<0||c>=row||d<0||d>=row) return false;
    return true;
}


int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&row);
        getchar();
        for(i=0;i<row;i++)
            scanf("%s",grid[i]);

        for(i=0;i<row;i++){
            for(j=0;j<row;j++){
                p=grid[i][j]-65;
                arr[p]=grid[i][j];
            }
        }
        sort(arr,arr+26,comp_i);
        for(i=0;i<26;i++){
            if(!arr[i]) break;
        }
        count1=i;
        m=0;
        count2=0;
        for(i=0;i<row;i++){
            for(j=0;j<row;j++){
                if(grid[i][j]==arr[m]&&visited[i][j]==false){
                    m++;
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
                            if(grid[c][d]=='.') count2++;
                            if(is_safe(c,d)&&grid[c][d]==arr[m]&&visited[c][d]==false){
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
        printf("Case %d: ",++cases);
        if(count2) printf("%d\n",count2);
        else puts("Impossible");
        memset(visited,0,sizeof(visited));
    }
    return 0;
}
