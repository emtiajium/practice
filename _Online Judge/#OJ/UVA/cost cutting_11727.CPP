#include<stdio.h>
int main(void)
{
	int a,b,c,t,m;
	scanf("%d",&m);
    for(t=1;t<=m;t++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a>b&&a>c&&b>c) printf("Case %d: %d\n",t,b);
        else if(a>b&&a>c&&b<c) printf("Case %d: %d\n",t,c);
        else if(b>c&&b>a&&c>a) printf("Case %d: %d\n",t,c);
        else if(b>c&&b>a&&c<a) printf("Case %d: %d\n",t,a);
        else if(c>a&&c>b&&a>b) printf("Case %d: %d\n",t,a);
        else if(c>a&&c>b&&a<b) printf("Case %d: %d\n",t,b);
    }
    return 0;
}
