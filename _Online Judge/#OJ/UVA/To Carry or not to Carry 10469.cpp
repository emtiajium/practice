// just do XOR of two number
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
const int SIZE=15;
char str[SIZE],stra[SIZE],strb[SIZE],tmp[SIZE];
unsigned a,b,t,deci;
int len1,len2,m,n,sum,i,j;

void binary(int a){
    int i=0,m,j;
    while(a!=0){
        m=a%2;
        tmp[i++]=m+48;
        a/=2;
    }
    tmp[i]=NULL;
    for(j=i-1,i=0;j>=0;j--,i++)
        str[i]=tmp[j];
    str[i]=NULL;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%u%u",&a,&b)==2){
        if(b>a){
            t=a;
            a=b;
            b=t;
        }
        binary(a);
        strcpy(stra,str);
        binary(b);
        strcpy(strb,str);
        len1=strlen(stra);
        len2=strlen(strb);
        m=len1-1;
        n=len2-1;
        for(i=0;i<len1;i++,m--,n--){
            if(n>=0) sum=(stra[m]-48)+(strb[n]-48);
            else sum=stra[m]-48;
            if(sum==2) str[i]=48;
            else str[i]=sum+48;
        }
        str[i]=NULL;
        for(i=deci=0,j=1;str[i];i++){
            if(str[i]==49) deci+=j;
            j*=2;
        }
        printf("%u\n",deci);
    }
    return 0;
}
