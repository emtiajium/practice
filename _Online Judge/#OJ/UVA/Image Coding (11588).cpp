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
int arr[28];
char str[25];
int row,col,test,cases,M,N,i,j,xx,coun,sum;

bool comp(int a,int b){
    return a>b;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&test);
    while(test--){
        scanf("%d%d%d%d",&row,&col,&M,&N);
        for(i=0;i<row;i++){
            scanf("%s",str);
            for(j=0;j<col;j++){
                xx=str[j]-65;
                arr[xx]++;
            }
        }
        sort(arr,arr+26,comp);
        coun=0;
        for(i=0;i<26;i++){
            if(arr[i]==arr[0]) coun+=arr[i];
            else break;
        }
        sum=coun*M + ((row*col)-coun)*N;
        printf("Case %d: %d\n",++cases,sum);
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
