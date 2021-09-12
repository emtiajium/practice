#include<stdio.h>
#include<string.h>
char str[110],back[110],without_0[110],reverse[110],final[110],answer[110];
int main()
{
    int i,j,count;
    while(gets(str)&&(str[0]!='0' && str[2]!='0')){
        count=0;
        int len=strlen(str);
        for(i=len-1,j=0;i!=1;i--,j++)
            back[j]=str[i];

        back[j]='\0';

        i=0;
        while(1){
            if(back[i]=='0') count++;
            if(back[i]>'0') {break;}
            i++;
        }

        for(i=count,j=0;back[i]!='\0';i++,j++)
            without_0[j]=back[i];

        without_0[j]='\0';

        for(i=j-1,j=0;i>=0;i--,j++)
            reverse[j]=without_0[i];

        reverse[j]='\0';
        int reverse_len=j;

        for(i=0,j=0;i<reverse_len;i++){
            if(reverse[i]==str[0]) continue;
            else{
            answer[j]=reverse[i];
            j++;
            }
        }

        answer[j]='\0';
        if(j==0) puts("0");
        else if(answer[0]=='0'){
            for(i=0,j=0;answer[i]!='\0';i++){
                if(answer[i]=='0') continue;
                else{
                    final[j]=answer[i];
                    j++;
                }
            }
            final[j]='\0';
            puts(final);
        }
        else puts(answer);
    }
return 0;
}
