#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;

struct TT
{
    int x;//char
    int y;//count
};
bool comp(TT a,TT b)
{
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}
bool comp_i(int a,int b){
    return a>b;
}

TT fre[30];
stack<int>S,s;
bool visited[105][105];
char grid[105][105];
int arr[30];
int xx[]={0,0,1,-1};
int yy[]={-1,1,0,0};
int t,cases,i,j,k,m,p,row,col,count1,count2,u,v,c,d;

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

        for(i=0;i<row;i++){
            for(j=0;grid[i][j];j++){
                p=grid[i][j]-97;
                arr[p]=grid[i][j];
            }
        }
        sort(arr,arr+26,comp_i);
        for(i=0;i<26;i++){
            if(arr[i]==0) break;
        }
        count1=i;
        printf("World #%d\n",++cases);
        for(m=0;m<count1;m++){
            p=arr[m]-97;
            fre[p].x=arr[m];
            fre[p].y=0;
            for(i=0;i<row;i++){
                for(j=0;j<col;j++){
                    if(grid[i][j]==arr[m]&&visited[i][j]==false){
                        S.push(i);
                        s.push(j);
                        while(!S.empty()){
                            u=S.top();
                            v=s.top();
                            S.pop();
                            s.pop();
                            for(k=0;k<4;k++){
                                c=u+xx[k];
                                d=v+yy[k];
                                if(is_safe(c,d)&&grid[c][d]==arr[m]&&visited[c][d]==false){
                                    S.push(c);
                                    s.push(d);
                                    visited[c][d]=true;
                                }
                            }
                        }
                        fre[p].y++;
                    }
                }
            }
        }
        sort(fre,fre+26,comp);
        for(i=0;i<26;i++){
            if(fre[i].y==0) break;
            printf("%c: %d\n",fre[i].x,fre[i].y);
        }
        memset(fre,0,sizeof(fre));
        memset(arr,0,sizeof(arr));
        memset(visited,0,sizeof(visited));
    }
return 0;
}
