#include<stdio.h>
#include<math.h>

const int SIZE=2;
int n,r,i,j,arr[200];
unsigned long long c;
double xx,sum;
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    for(i=0;i<SIZE;i++){
        arr[i]=(int)ceil(((double)(0.8*i))-1);
        //printf("%d %d\n",arr[i][0],arr[i][1]);
    }
    sum=0;
    for(i=1;i<SIZE;i++){
        n=i;
        r=arr[i];
        n=1024,r=819;
        if(r>n/2) r=n-r;
        for(j=0,c=1;j<r;j++){
            c=c*(n-j);
            c=c/(1+j);
        }
        printf("%llu\n",c);
        xx=double(c);
        xx=xx*pow(0.87,r)*pow(1-.87,n-r);
        sum+=xx;
        printf("%lf\n",xx);
    }
    printf("False negative error %lf\n",sum);
    //*/
    return 0;
}
