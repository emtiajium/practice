#include<stdio.h>
#include<iostream>
using namespace std;
int a,b,mod,x,y,gcd;
int main()
{
    while(scanf("%d %d",&a,&b)==2){
        x=a;
        y=b;
        while(b!=0){
            mod=a%b;
            a=b;
            b=mod;
        }
        gcd=a;
        printf("gcd %d\n",gcd);
        printf("%d/%d\n",x/gcd,y/gcd);
    }
    return 0;
}
