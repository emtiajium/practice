#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
char str[105];
char sto[105][105];
int len,i,k,upp,low,dig,cont,tr;
int main()
{
    //freopen("input.txt","r",stdin);
    cont=0;
    k=0;
    while(gets(str)){
        len=strlen(str);
        tr=0;
        upp=0;low=0;dig=0;
        if(len>5){
            for(i=0;i<len;i++){
                if(str[i]==':'||str[i]==';'||str[i]=='+'||str[i]=='-') break;
                if(isupper(str[i])) upp++;
                if(islower(str[i])) low++;
                if(isdigit(str[i])) dig++;
            }
            if(upp>=3&&low>=1&&dig>=2){
                tr=1;
                strcpy(sto[k],str);
                //puts(sto[k]);
                k++;
            }
        }
        if(tr) cont++;
        memset(str,'\0',sizeof(str));
    }
    printf("%d\n",cont);
    for(i=0;i<k;i++){
        puts(sto[i]);
    }
    return 0;
}
