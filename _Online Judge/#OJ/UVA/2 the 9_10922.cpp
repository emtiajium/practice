#include<stdio.h>
#include<math.h>
char str[1050];
int degree,sum,i,len,sum1,mod;
int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(str))
    {
        degree=0,sum=0;
        if(str[0]=='0'&&str[1]=='\0') break;
        for(i=0;str[i];i++)
            sum+=str[i]-48;

        if(sum%9==0){
            degree=1;
            len=log10(sum)+1;
            while(len>1){
                for(i=0,sum1=0;i<len;i++){
                    mod=sum%10;
                    sum1+=mod;
                    sum/=10;
                }
                degree++;
                len=log10(sum1)+1;
                sum=sum1;
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n",str,degree);
        }
        else printf("%s is not a multiple of 9.\n",str);
    }
    return 0;
}
