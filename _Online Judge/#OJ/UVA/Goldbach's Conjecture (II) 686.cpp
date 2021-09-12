#include<stdio.h>
#include<math.h>
const int SIZE=32770;
bool flag[SIZE]={1,1,0};
int i,j,r,n;
int main()
{
    for(i=4;i<SIZE;i+=2)
        flag[i]=1;
    for(i=3;i<182;i+=2){
        r=i+i;
        if(flag[i]==0){
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }
    while(scanf("%d",&n)&&n!=0){
        r=0;
        for(i=n-2,j=2;i>=j;i--,j++){
            if(!flag[i] && !flag[j]) r++;
        }
        printf("%d\n",r);
    }
return 0;
}
