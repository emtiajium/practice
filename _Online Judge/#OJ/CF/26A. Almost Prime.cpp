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

//const double PI=2*acos(0.0);
const int SIZE=3005;
bool flag[SIZE]={true,true};
int arr[3005];
int cnd,i,j,k,r,coun,n,a,b;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    cnd=sqrt(SIZE)+1;
    for(i=3;i<cnd;i+=2){
        if(flag[i]==false){
            for(j=i*i,r=i<<1;j<SIZE;j+=r)
                flag[j]=true;
        }
    }
    for(i=4;i<SIZE;i+=2){
        flag[i]=true;
    }
    for(k=1;k<3002;k++){
        cnd=sqrt(k);
        n=k;
        coun=0;
        if(cnd*cnd==k) cnd--;
        for(i=1;i<=cnd;i++){
            if(n%i==0){
                a=i;
                b=n/i;
                if(flag[a]==false) coun++;
                if(flag[b]==false) coun++;
            }
        }
        if(cnd*cnd==k && flag[cnd]==false) coun++;
        if(coun==2) arr[k]=arr[k-1]+1;
        else arr[k]=arr[k-1];
    }

    while(scanf("%d",&n)==1){
        printf("%d\n",arr[n]);
    }
    return 0;
}
