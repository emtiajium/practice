#include<stdio.h>
#include<iostream>
using namespace std;
short int t,c,a,b,d;
int main()
{
    scanf("%hd",&t);
    while(t--){
        scanf("%hd",&a);
        b=a/2;
        if(a&1) d=b+1;
        else d=b;
        printf("%hd %hd\n",b,d);
    }
    return 0;
}
