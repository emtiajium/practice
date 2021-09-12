#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//const double PI=3.14159265358979323846264338327950288419716939937511;
const int SIZE=1000005;
bool flag[SIZE]={1,1};
int digit[SIZE];
int i,j,r,t,m,sum,a,b;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(i=4;i<SIZE;i+=2)
        flag[i]=true;
    for(i=3;i<1001;i+=2){
        if(flag[i]==false){
            r=i*2;
            for(j=i*i;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=2;i<SIZE;i++){
        if(flag[i]==false){
            t=i;
            sum=0;
            while(t!=0){
                m=t%10;
                t/=10;
                sum+=m;
            }
            if(flag[sum]==false) digit[i]=digit[i-1]+1;
            else digit[i]=digit[i-1];
        }
        else digit[i]=digit[i-1];
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        sum=digit[b]-digit[a-1];
        printf("%d\n",sum);
    }
    return 0;
}
