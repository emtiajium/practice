//The most important thing is never stop questioning ~ Albert Einstein
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int arr[3020],abstract[3020];
using namespace std;
int main()
{
    int n,i,x;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        if(n==2){
            x=abs(arr[0]-arr[1]);
        }
        else if(n>2){
        for(i=0;i<=n-2;i++){
            abstract[i]=abs(arr[i]-arr[i+1]);
        }
        sort(abstract,abstract+(n-1));
        for(i=0;i<n-2;i++){
            if(abstract[i]>0||abstract[i]<n){
                if(abstract[i+1]-abstract[i]==1) x=1;
                else{
                x=2;break;}
            }
        }
        }

        if(n==1) printf("Jolly\n");
        else if(n==2&&x==1) printf("Jolly\n");
        else if(n==2&&x!=1) printf("Not jolly\n");
        else if(n>2&&x==1) printf("Jolly\n");
        else if(n>2&&x==2) printf("Not jolly\n");
    }
    return 0;
}
