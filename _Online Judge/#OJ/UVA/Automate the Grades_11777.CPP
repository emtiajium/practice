#include<stdio.h>
int main()
{
    int t1,t2,ft,a,ct1,ct2,ct3,t,m,mark,sum;
    scanf("%d",&m);
    for(t=1;t<=m;t++){
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&ft,&a,&ct1,&ct2,&ct3);

        if(ct1>=ct2&&ct1>=ct3&&ct2>=ct3) mark=(ct1+ct2)/2;
        else if(ct1>=ct2&&ct1>=ct3&&ct3>=ct2) mark=(ct1+ct3)/2;
        else if(ct2>=ct3&&ct2>=ct1&&ct1>=ct3) mark=(ct2+ct1)/2;
        else if(ct2>=ct3&&ct2>=ct1&&ct3>=ct1) mark=(ct2+ct3)/2;
        else if(ct3>=ct1&&ct3>=ct2&&ct1>=ct2) mark=(ct3+ct1)/2;
        else if(ct3>=ct1&&ct3>=ct2&&ct2>=ct1) mark=(ct3+ct2)/2;

        sum=t1+t2+ft+a+mark;

        if(sum>=90) printf("Case %d: A\n",t);
        else if(sum>=80) printf("Case %d: B\n",t);
        else if(sum>=70) printf("Case %d: C\n",t);
        else if(sum>=60) printf("Case %d: D\n",t);
        else printf("Case %d: F\n",t);
    }
    return 0;
}
