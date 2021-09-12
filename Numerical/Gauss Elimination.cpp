// The determinant of a triangular matrix is the product of the entries on the diagonal
#include<stdio.h>
double arr[15][15],sol[15],pivot,up;
int N,row,col,i,j,k;
int main()
{
    freopen("input.txt","r",stdin);
    while(scanf("%d",&N)==1){
        row=N;
        col=N+1;
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
        for(i=row-1;i>=0;i--){
            sol[i]=arr[i][col-1];
            for(j=col-2;j>=0;j--){
                if(j==i) continue;
                sol[i]=sol[i]-arr[i][j]*sol[j];
            }
            sol[i]=sol[i]/arr[i][i];
        }
        for(i=0;i<row;i++){
            printf("%.2lf\n",sol[i]);
        }
        puts("");
    }
    return 0;
}
