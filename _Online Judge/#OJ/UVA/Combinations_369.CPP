// 369 - Combinations
#include<stdio.h>
const int SIZE=110;
int psc[SIZE+2][SIZE+2];
int n,m,i,j;
int main(void)
{
    psc[0][0]=psc[1][0]=psc[1][1]=1;
    for(i=2;i<SIZE;i++){
        psc[i][0]=1;
        m=i>>1;
        for(j=1;j<=m;j++){
            psc[i][j]= psc[i-1][j-1]+psc[i-1][j];
            psc[i][i-j]=psc[i][j];
        }
        psc[i][i]=1;
    }
    while(scanf("%d %d",&n,&m)&&(n!=0||m!=0)){
        printf("%d things taken %d at a time is %d exactly.\n",n,m,psc[n][m]);
    }
    return 0;
}
