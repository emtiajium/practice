#include<stdio.h>
int n,i,j,cases;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)&&n>0){
        printf("Case %d: ",++cases);
        if(n==1){
            puts("0");
            continue;
        }
        i=1;
        j=0;
        while(2*i<n){
            i=2*i;
            j++;
        }
        printf("%d\n",j+1);
    }
    return 0;
}
/*
printf("Case %d: %.0lf\n", cno++, ceil(log2(n)));
*/
