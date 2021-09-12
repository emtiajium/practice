#include<stdio.h>
int f91(int  );

int main()
{
    int n,x;
    while(scanf("%d",&n)&&n){
        x=f91(n);
        printf("f91(%d) = %d\n",n,x ) ;
    }
    return 0;
}

int f91(int n)
{
    if(n==0) return 0;
    else if (n <= 100) return f91(f91(n+11));
    else if(n >= 101) return n-10;
}
