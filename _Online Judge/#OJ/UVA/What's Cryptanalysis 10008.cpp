#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<algorithm>
using namespace std;

struct TT{
    int x;//char
    int y;//count
};
bool comp(TT a,TT b){
    if(a.y==b.y) return a.x<b.x;
    return a.y>b.y;
}

TT fre[100];
char str[210][210];
int t,i,j,k,p;

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    for(i=0;i<t;i++){
        gets(str[i]);
    }
    for(k=0;k<t;k++){
        for(i=0;str[k][i];i++){
            if(isupper(str[k][i])){
                p=str[k][i]-64;
                fre[p].x=str[k][i];
            }
            else if(islower(str[k][i])){
                p=str[k][i]-96;
                fre[p].x=toupper(str[k][i]);
            }
            else continue;
            fre[p].y++;
        }
    }
    sort(fre,fre+26,comp);
    for(i=0;i<26;i++){
        if(!fre[i].y) break;
        printf("%c %d\n",fre[i].x,fre[i].y);
    }
    return 0;
}
