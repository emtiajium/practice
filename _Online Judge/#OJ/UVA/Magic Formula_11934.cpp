#include<stdio.h>
int a,b,c,d,l,i,count,fx;
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l)==5){
        if(a==0 && b==0 && c==0 && d==0 && l==0) break;

        for(i=0,count=0;i<=l;i++){
            fx= a*i*i+b*i+c;
            if(fx%d==0) count++;
        }
        printf("%d\n",count);
    }
}
