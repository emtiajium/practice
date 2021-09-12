#include<stdio.h>                                                                                                                       #include<stdio.h>
#include<string.h>
const int MAX=1500;
char str[MAX];
int main()
{
    freopen("input.txt","r",stdin);
    gets(str);
    int len=strlen(str);
    printf("Length %d.\n",len);
    return 0;
}
