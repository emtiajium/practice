#include<stdio.h>
int main()
{
    int w,x,y,z,n,sum;
    int a[8],b[8],c[2],d[8];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&w,&x,&y,&z);
        a[0]=(w/1000)*2;
        a[1]=(x/1000)*2;
        a[2]=(y/1000)*2;
        a[3]=(z/1000)*2;

        a[4]=((w%100)/10)*2;
        a[5]=((x%100)/10)*2;
        a[6]=((y%100)/10)*2;
        a[7]=((z%100)/10)*2;

        b[0]=(a[0]/10)+(a[0]%10);
        b[1]=(a[1]/10)+(a[1]%10);
        b[2]=(a[2]/10)+(a[2]%10);
        b[3]=(a[3]/10)+(a[3]%10);
        b[4]=(a[4]/10)+(a[4]%10);
        b[5]=(a[5]/10)+(a[5]%10);
        b[6]=(a[6]/10)+(a[6]%10);
        b[7]=(a[7]/10)+(a[7]%10);

        c[0]=b[0]+b[1]+b[2]+b[3]+b[4]+b[5]+b[6]+b[7];

        d[0]=w%10;
        d[1]=x%10;
        d[2]=y%10;
        d[3]=z%10;

        d[4]=(w%1000)/100;
        d[5]=(x%1000)/100;
        d[6]=(y%1000)/100;
        d[7]=(z%1000)/100;

        c[1]=d[0]+d[1]+d[2]+d[3]+d[4]+d[5]+d[6]+d[7];

        sum=c[0]+c[1];
        if((sum%10)!=0) printf("Invalid\n");
        else printf("Valid\n");
    }
    return 0;

}
