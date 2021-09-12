#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<algorithm>
using namespace std;
char str[210];
int t,i,j,p;

struct TT{
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
    TT fre[100];
    scanf("%d",&t);
    getchar();
    while(t--){
        memset(fre,0,sizeof(fre));
        gets(str);
        for(i=0,j=0;str[i];i++){
            if(str[i]>64&&str[i]<91){
                str[j++]=tolower(str[i]);
            }
            else if(str[i]>96&&str[i]<123) str[j++]=str[i];
        }
        str[j]='\0';
        //puts(str);
        for(i=0;str[i];i++){
            p=str[i]-97;
            fre[p].x=(int)str[i];
            fre[p].y++;
        }
        sort(fre,fre+26,comp);
        for(i=0;i<j;i++){
            if(fre[i+1].y<fre[i].y) break;
        }
        for(j=0;j<=i;j++){
            putchar(fre[j].x);
        }
        putchar('\n');
    }
return 0;
}
