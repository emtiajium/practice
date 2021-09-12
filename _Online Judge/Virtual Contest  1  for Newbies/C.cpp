#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
int t,c,n,i,cont,arr[30];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    for(c=1;c<=t;c++){
        cont=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<n;i++){
            while(arr[i]!=0){
                arr[i]/=2;
                cont++;
            }
        }
        printf("Case %d: %d\n",c,cont);
    }
    return 0;
}
