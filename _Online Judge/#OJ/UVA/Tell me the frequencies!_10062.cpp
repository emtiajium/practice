#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int SIZE=200;
char str[1050];
int t,i,j,p,len,b_line;

struct TT
{
    int x;//char
    int y;//count
};
bool comp(TT a,TT b)
{
    if(a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}
int main()
{
    //freopen("input.txt","r",stdin);
    TT fre[SIZE];
    memset(fre,0,sizeof(fre));
    b_line=1;
    while(gets(str))
    {
        if(b_line!=1) putchar('\n');
        len=strlen(str);
        for(i=0;i<len;i++){
            p=str[i];
            fre[p].x=p;
            fre[p].y++;
        }
        sort(fre,fre+SIZE,comp);
        for(i=0;i<SIZE;i++){
            if(fre[i].y==0) continue;
            printf("%d %d\n",fre[i].x,fre[i].y);
        }
        b_line++;
        memset(fre,0,sizeof(fre));
    }
return 0;
}
