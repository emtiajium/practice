#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;

//const double PI=3.14159265358979323846264338327950288419716939937511;
double arr[10][10],pivot;
int N,i,j,k,row,col;
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&N)==1){
        row=N;
        col=N+1;
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                scanf("%lf",&arr[i][j]);
            }
        }
        for(k=1;k<=row;k++){
            pivot=arr[k][k];
            for(i=1;i<=row;i++){
                if(i==k) continue;
                double pivotdown=arr[i][k];
                for(j=1;j<=col;j++){
                    //printf("(%d,%d) = %.2lf(%.2lf) - %.2lf(%.2lf)",i,j,pivot,arr[i][j],pivotdown,arr[k][j]);
                    arr[i][j]=pivot*arr[i][j]-pivotdown*arr[k][j]; // r2/r3.. = pivot r2/r3/.. - pivotdown*pivotrow
                    //printf(" = %.2lf\n",arr[i][j]);
                }
                //puts("");
            }
        }/*
        for(i=1;i<=row;i++){
            for(j=1;j<=col;j++){
                printf("%lf ",arr[i][j]);
            }
            puts("");
        }*/
        for(i=1,j=1;i<=row;i++,j++){
            pivot=arr[i][j];
            arr[i][j]=arr[i][j]/pivot;
            arr[i][col]=arr[i][col]/pivot;
        }
        for(i=1;i<=row;i++){
            printf("%.2lf\n",arr[i][col]);
        }
        puts("");
    }
    return 0;
}
