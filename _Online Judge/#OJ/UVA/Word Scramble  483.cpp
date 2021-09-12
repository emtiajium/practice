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

char str[1005],str2[1005];
int i,j,k,m,pos;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(gets(str)){
        for(i=0;;i++){
            if(str[i]==' '||str[i]=='\0') break;
        }
        for(j=i-1,k=0;j>=0;j--){
            str2[k++]=str[j];
        }
        if(str[i]=='\0'){
            str2[k]='\0';
            puts(str2);
            continue;
        }
        pos=i;
        while(1){
            if(str[pos]==' ') str2[k++]=' ';
            for(j=pos+1;;j++){
                if(str[j]==' '||str[j]=='\0') break;
            }
            for(m=j-1;m>pos;m--){
                str2[k++]=str[m];
            }
            pos=j;
            if(str[pos]=='\0'){
                str2[k]='\0';
                break;
            }
        }
        puts(str2);
    }
    return 0;
}
