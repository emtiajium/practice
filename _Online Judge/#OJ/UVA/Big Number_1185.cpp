#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
int t,i,n;
double sum;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n<=1) puts("1");
        else{
            sum=0.0;
            for(i=1;i<=n;i++)
                sum+=log10((double)i);

            printf("%0.lf\n",ceil(sum));
        }
    }
    return 0;
}
