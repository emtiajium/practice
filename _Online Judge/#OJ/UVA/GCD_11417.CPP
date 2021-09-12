#include<stdio.h>
int gcd(int,int);
int main()
{
    int i,j,n;
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        int G=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                G+=gcd(i,j);
        printf("%d\n",G);
    }
    return 0;
}



int gcd(int x,int y)
{
    int g;
    while(y!=0){
        g=x%y;
        x=y;
        y=g;
    }
    return x;
}
