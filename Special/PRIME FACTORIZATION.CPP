#include<stdio.h>
#include<math.h>
const int SIZE=30;
int arr[SIZE][50];
int i,j,c,x,cnd,n,z;
int main()
{
    for(x=2;x<SIZE;x++){
        z=0;
        c=x;
        while (c%2==0){
            arr[x][z]=2;
            c=c/2;
            z++;
        }
        i=3;
        cnd=sqrt(c);
        while (i<=cnd){
            if(c%i==0){
                arr[x][z]=i;
                c=c/i;
                z++;
            }
            else i=i+2;
        }
        if (c > 1) arr[x][z]=c; // যাদের শেষ ভ্যালু প্রাইম
    }
    for(i=2;i<SIZE;i++){
        printf("[%d] >> ",i);
        for(j=0;arr[i][j];j++){
            printf("%d ",arr[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
