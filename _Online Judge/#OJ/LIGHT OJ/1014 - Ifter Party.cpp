#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,i,j,x,y,cnd,arr[1555];
int t,cases,p,q;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&p,&q);
        printf("Case %d:",++cases);
        n=p-q;
        if(!n) puts("impossible");
        else{
            cnd=sqrt((double)n);
            x=n%2;
            for(i=1,j=0;i<=cnd;){
                y=n%i;
                if(y==0){
                    arr[j]=i;
                    arr[j+1]=n/i;
                    j+=2;
                }
                if(x==0) i++;
                else i+=2;
            }
            if(cnd*cnd==n)j=j-1;//for perfect square
            sort(arr,arr+j);
            for(i=0,x=0;i<j;i++){
                if(arr[i]<=q) continue;
                printf(" %d",arr[i]);
                x++;
            }
            if(x)puts("");
            else if(!x) puts("impossible");
        }
    }
    return 0;
}
