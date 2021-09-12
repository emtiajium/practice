#include<stdio.h>

double arr[35][35],pivot,up,val;
int N,row,col,i,j,k;

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&N)==1){
        row=col=N;
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%lf",&arr[i][j]);
            }
        }
        for(k=1;k<row;k++){
            pivot=arr[k-1][k-1];
            for(i=k;i<row;i++){
                up=arr[i][k-1];
                for(j=0;j<col;j++){
                    arr[i][j]=arr[i][j]-(up/pivot)*arr[k-1][j];
                }
            }
        }
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                printf("%lf ",arr[i][j]);
            }
            puts("");
        }
        for(i=0,val=1.0;i<row;i++){
            val*=arr[i][i];
        }
        printf("%.0lf\n",val);
    }
    return 0;
}
