#include<stdio.h>
int main()
{
    int t,a,b,i,sum,x,y,m;
    scanf("%d",&m);
    for(t=1;t<=m;t++){
        scanf("%d %d",&x,&y);
        sum=0;
        if(x%2==0&&y%2==0){
            a=x+1;
            b=y-1;
        }
        else if(x%2!=0&&y%2!=0){
            a=x;
            b=y;
        }
        else if(x%2==0&&y%2!=0){
            a=x+1;
            b=y;
        }
        else if(x%2!=0&&y%2==0){
            a=x;
            b=y-1;
        }
        for(i=a;i<=b;i+=2)
            sum+=i;
        printf("Case %d: %d\n",t,sum);
    }
    return 0;
}
