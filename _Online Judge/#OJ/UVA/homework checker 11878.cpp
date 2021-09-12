#include<stdio.h>
#include<stdlib.h>
int main()
{
    int int1,int2,convert,count=0;
    char a,str[100];
    while(scanf("%d%c%d=%s",&int1,&a,&int2,str)!=EOF)
    {
        convert=atoi(str);
        if(int1+int2==convert||int1-int2==convert) count++;
    }
    printf("%d\n",count);
    return 0;
}
