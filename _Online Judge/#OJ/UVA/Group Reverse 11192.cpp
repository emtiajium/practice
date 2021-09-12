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

char ch,str[105],str2[105];
int num,i,k,pos1,pos2,por,len;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&num)&&num){
        scanf("%c%s",&ch,str);
        len=strlen(str);
        por=len/num;
        pos1=por-1;
        pos2=0;
        k=0;
        while(1){
            for(i=pos1;i>=pos2;i--){
                str2[k++]=str[i];
            }
            pos2=pos1+1;
            pos1=pos1+por;
            if(str[pos2]=='\0'){
                str2[k]='\0';
                break;
            }
        }
        puts(str2);
    }
    return 0;
}
