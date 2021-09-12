#include<stdio.h>
int main()
{
    int t,i,a,b,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&a,&b,&c);
        if((a+b<=c)||(a+c<=b)||(c+b<=a)) printf("Case %d: Invalid\n",i);
        else if((a==b)&&(b==c)&&(a==c)) printf("Case %d: Equilateral\n",i);
        else if((a!=b)&&(a!=c)&&(b!=c)) printf("Case %d: Scalene\n",i);
        else printf("Case %d: Isosceles\n",i);
    }
return 0;
}
