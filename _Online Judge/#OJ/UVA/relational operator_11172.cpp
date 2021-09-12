#include<stdio.h>
int main()
{
    int a,b,t,i;
    scanf("%d",&i);
    for(t=0;t<i;t++){
        scanf("%d %d",&a,&b);
        if(a>b) printf(">\n");
        else if(a<b)printf("<\n");
        else printf("=\n");
    }
return 0;
}


