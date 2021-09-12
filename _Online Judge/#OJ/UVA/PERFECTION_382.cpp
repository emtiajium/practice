#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int SIZE=60005;
int arr1[SIZE+SIZE],arr2[SIZE];
int n,mod,cdn1,k,l,m,cdn2,size;

int inp[SIZE],i,len,sum;
int main()
{
    //freopen("input.txt","r",stdin);
    for(i=0;;i++){
        scanf("%d",&inp[i]);
        if(inp[i]==0) break;
    }
    len=i;
    puts("PERFECTION OUTPUT");
    for(i=0;i<len;i++){
        cdn1=(int)(sqrt((double)inp[i]));
        for(k=1,l=0,m=0;k<=cdn1;k++){
            mod=inp[i]%k;
            if(mod==0){
                arr1[l++]=k;
                arr2[m++]=inp[i]/k;
            }
        }
        if(cdn1*cdn1==inp[i]) l=l-1; // perfect square
        cdn2=l+m;
        for(k=l,m=0;k<cdn2;k++,m++)
            arr1[k]=arr2[m];

        size=k;
        sort(arr1,arr1+k);

        for(k=0,sum=0;k<size-1;k++)//not included last one
            sum+=arr1[k];

        if(sum==inp[i]) printf("%5d  PERFECT\n",inp[i]);//two space
        else if(sum>inp[i]) printf("%5d  ABUNDANT\n",inp[i]);
        else printf("%5d  DEFICIENT\n",inp[i]);
    }
    puts("END OF OUTPUT");
    return 0;
}
