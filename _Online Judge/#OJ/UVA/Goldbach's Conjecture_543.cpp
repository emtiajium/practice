#include<stdio.h>
#include<math.h>
const int SIZE=1000005;
bool flag[SIZE]={1,1,0};
int i,j,r,n;
int main()
{
    for(i=4;i<SIZE;i+=2)
        flag[i]=1;
    n=sqrt((double)SIZE);
    for(i=3;i<=n;i+=2){
        if(flag[i]==0){
			r=i+i;
            for(j=i*i;j<SIZE;j+=r)//j+=2*i;
                flag[j]=1;
        }
    }

    while(scanf("%d",&n)&&n!=0){
        j=r=0;
        for(i=n-2;i>=0;i--){
            if(!flag[i] && !flag[n-i]){
                j=i;
                r=n-i;
                break;
            }
            if(n%2==1 && (j==0 && r==0)) break;
            // বিজোড়কে হয় 2 + (n-2) আকারে প্রকাশ করা যাবে, নাহয় যাবেনা।
        }
        if(j==0&&r==0) puts("Goldbach's conjecture is wrong.");
        else printf("%d = %d + %d\n",n,r,j);
    }
return 0;
}
