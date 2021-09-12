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
const int SIZE=2005;
struct TT{
    int ch,coun;
};
TT frq[65];
char str[SIZE];
bool flag[SIZE]={1,1},xlag;
int i,j,r,t,cases,p;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=4;i<SIZE;i+=2)
        flag[i]=true;
    for(i=3;i<45;i+=2){
        r=i+i;
        if(flag[i]==false){
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(str);
        for(i=0;str[i];i++){
            if(isdigit(str[i])) p=str[i]-48;
            else if(isupper(str[i])) p=str[i]-65+10;
            else if(islower(str[i])) p=str[i]-97+36;
            frq[p].ch=str[i];
            frq[p].coun++;
        }
        xlag=false;
        printf("Case %d: ",++cases);
        for(i=0;i<62;i++){
            if(frq[i].coun==0) continue;
            if(flag[frq[i].coun]==false){
                xlag=true;
                printf("%c",frq[i].ch);
            }
        }
        if(xlag==false) printf("empty");
        puts("");
        memset(frq,0,sizeof(frq));
    }
    return 0;
}
