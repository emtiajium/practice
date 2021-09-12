#include<stdio.h>

const int SIZE=1000005;
int div[SIZE+2]={0,1};
int maxdiv[SIZE+2]={0,1};

int t,c,x,i,j,k,r,num,max,count;

int main()
{
    for(i=2;i<SIZE;i++){
        for(j=i;j<SIZE;j+=i)
            div[j]++;
        div[i]++;
    }
    max=0;
    for(i=2;i<SIZE;i++){
        if(div[i]>=max){
            max=div[i];
            maxdiv[i]=i;
        }
        else maxdiv[i]=maxdiv[i-1];
    }
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&num);
        printf("%d\n",maxdiv[num]);
    }
    return 0;
}
