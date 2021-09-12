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
#include<iomanip>
using namespace std;

//const double PI=3.14159265358979323846264338327950288419716939937511;
int arr[17][17],i,j,N,sum,test;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&N)==1){
        if(test!=0) puts("");
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                arr[i][j]=N*((i+j-1+(int)(N/2))%N) + ((i+2*j-2)%N)+1;
            }
        }
        for(i=1,sum=0;i<=N;i++){
            sum+=arr[1][i];
        }// sum=n*(n*n+1)/2
        printf("n=%d, sum=%d\n",N,sum);
        if(N<4){
            for(i=1;i<=N;i++){
                for(j=1;j<=N;j++){
                    printf(" %d",arr[i][j]);
                }
                puts("");
            }
        }
        else if(N>=5&&N<10){
            for(i=1;i<=N;i++){
                for(j=1;j<=N;j++){
                    printf(" %2d",arr[i][j]);
                }
                puts("");
            }
        }
        else if(N>=11&&N<16){
            for(i=1;i<=N;i++){
                for(j=1;j<=N;j++){
                    printf(" %3d",arr[i][j]);
                }
                puts("");
            }
        }
        test++;
    }
    return 0;
}
