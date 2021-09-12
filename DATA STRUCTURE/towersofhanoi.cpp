#include<stdio.h>
int htower(int n,char a,char b,char c)
{
    int ret;
    if(n==1){
        printf("%c->%c\n",a,c);
        ret=1;
        return ret;
    }
    else{
        ret=htower(n-1,a,c,b);
        ret++;
        printf("%c->%c\n",a,c);
        ret=ret+htower(n-1,b,a,c);
        return ret;
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    printf("=%d moves.",htower(n,'A','B','C'));
    return 0;
}
