#include<stdio.h>
#include<iostream>
using namespace std;
int t,c,a,b,count;
int main()
{
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        count=0;
        scanf("%d",&a);
        while(a>0){
            if(a&1) count++;
            a=a>>1;
        }
        if(count&1)printf("Case %d: odd\n",c);
        else printf("Case %d: even\n",c);
    }
    return 0;
}
