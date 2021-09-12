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
char str[12],temp;
long long len,n1,n2,n,i;
bool comp(char a,char b){
    return a>b;
}
long long num(char str[],long long len){
    long long i,j=1,num=0;
    for(i=len-1;i>=0;i--){
        num+=(str[i]-48)*j;
        j*=10;
    }
    return num;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(gets(str)){
        len=strlen(str);
        sort(str,str+len,comp);
        n1=num(str,len); // atoi();
        sort(str,str+len);
        for(i=0;i<len;i++){
            if(str[i]>48){
                temp=str[i];
                str[i]=str[0];
                str[0]=temp;
                break;
            }
        }
        n2=num(str,len);
        n=n1-n2;
        printf("%lld - %lld = %lld = 9 * %lld\n",n1,n2,n,n/9);
    }
    return 0;
}
