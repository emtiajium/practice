#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int street[520];
int main()
{
    int t,i,j,relative,distance,sum,median;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        sum=0;
        scanf("%d",&relative);
        for(j=0;j<relative;j++)
            scanf("%d",&street[j]);

        sort(street,street+relative);
        if(relative%2==0) median=(street[relative/2]+street[relative/2-1])/2;
        else median=street[relative/2];
        for(j=0;j<relative;j++){
            distance=abs(median-street[j]);
            sum+=distance;
        }
        printf("%d\n",sum);
    }
    return 0;
}
