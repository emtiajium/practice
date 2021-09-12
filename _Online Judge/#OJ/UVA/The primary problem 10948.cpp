#include<stdio.h>
#include<math.h>
const int SIZE=1000005;
bool flag[SIZE]={1,1,0};
int i,j,r,n;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=4;i<SIZE;i+=2)
        flag[i]=1;
    for(i=3;i<1001;i+=2){
        r=i+i;
        if(flag[i]==0){
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }
    while(scanf("%d",&n)&&n!=0){
        j=r=0;
        for(i=n-2;i>=0;i--){
            if(!flag[i] && !flag[n-i]){
                j=i;
                r=n-i;
                break;
            }
        }
        printf("%d:\n",n);
        if(j==0&&r==0) puts("NO WAY!");
        else printf("%d+%d\n",r,j);
    }
return 0;
}
