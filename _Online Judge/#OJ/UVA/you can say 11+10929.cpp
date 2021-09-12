#include<stdio.h>
#include<string.h>
char number[1010];
int main()
{
    int k,length,sum;
    while(gets(number))
    {
        if(number[0]=='0'&&number[1]=='\0') break;
        sum=0;
        length=strlen(number);
        for(k=0;k<length;k++){
            if(k%2==0) sum+=number[k]-'0';
            else sum-=number[k]-'0';
        }
        //printf("%lld\n",sum);
        if(sum%11==0) printf("%s is a multiple of 11.\n",number);
        else printf("%s is not a multiple of 11.\n",number);
    }
    return 0;
}
