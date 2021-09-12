#include<stdio.h>
#include<string.h>
struct TT{
    int bst[50],lsize[50];
};
TT x;
int n,i,j,t,rank;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        memset(x.bst,-1,sizeof(x.bst));
        memset(x.lsize,0,sizeof(x.lsize));
        scanf("%d",&x.bst[0]);
        for(i=1;i<n;i++){
            scanf("%d",&t);
            for(j=0;x.bst[j]!=-1;){
                if(t<x.bst[j]){
                    x.lsize[j]++;
                    j=j*2+1;
                }
                else if(t>x.bst[j]) j=j*2+2;
            }
            x.bst[j]=t;
        }
        for(i=0;i<=j;i++){
            printf("[%d]-->%d  [%d]\n",i,x.bst[i],x.lsize[i]);
        }
        while(scanf("%d",&rank)==1){
            if(rank>=n){
                puts("No");
                continue;
            }
            for(j=0;rank!=x.lsize[j];){
                if(rank<x.lsize[j]) j=j*2+1;
                else{
                    rank=rank-x.lsize[j]-1;
                    j=j*2+2;
                }
            }
			printf("Yes %d\n",x.bst[j]);
        }
    }
    return 0;
}
