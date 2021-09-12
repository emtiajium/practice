#include<stdio.h>
#include<string.h>
int main()
{

    char a[100];
    int l,c,d,i,j,f,cnd;
    scanf("%s",a);
    l=strlen(a);
    cnd=l/2;
    for(i=0,j=l-1;i<cnd;i++,j--){
        c=a[i];
        d=a[j];
        if(c==d) f=1;
        else break;
    }
        if(f==1) printf("Palindrome");
        else printf("not Palindrome");
    return 0;
}
