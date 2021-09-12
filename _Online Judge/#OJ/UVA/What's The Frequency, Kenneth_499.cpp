#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int SIZE=200;
char str[1050];
int t,i,j,p;

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
int main()
{
    //freopen("input.txt","r",stdin);
    TT fre[SIZE];
    memset(fre,0,sizeof(fre));
    while(gets(str))
    {
        for(i=0,j=0;str[i];i++){
            if(isalpha(str[i])) str[j++]=str[i];
        }
        str[j]='\0';
        for(i=0;str[i];i++){
            p=str[i];
            fre[p].x=p;
            fre[p].y++;
        }
        sort(fre,fre+SIZE,comp);
        for(i=0;i<j;i++){
            if(fre[i+1].y<fre[i].y) break;
        }
        for(j=0;j<=i;j++){
            putchar(fre[j].x);
        }
        printf(" %d\n",fre[i].y);
        memset(fre,0,sizeof(fre));
    }
    return 0;
}
