#include<stdio.h>
char str[1000];
bool flag;
int i,count;
int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(str)){
        if(str[0]=='*'&&str[1]=='\0') break;
        for(i=0,count=0;str[i];i++){
            if(str[i]>96&&str[i]<123) str[i]=65+(str[i]-97);//toupper
            if(str[i]==32) count++;
        }
        for(i=0;str[i];i++){
            if(str[i]==32){
                if(str[0]==str[i+1]) flag=1;
                else{
                    flag=0;
                    break;
                }
            }
        }
        if(count==0) puts("Y");
        else if(flag==1) puts("Y");
        else puts("N");
    }
    return 0;
}
