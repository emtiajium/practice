#include<stdio.h>
#include<ctype.h>
char str[1000];
int main()
{
    int i,word;
    while(gets(str)){
        word=0;
        for(i=0;str[i]!='\0';i++){
            if(isalpha(str[i])==0&&isalpha(str[i+1])>0){
                word++;
            }
        }
        if(isalpha(str[0])>0) word=word+1;
        else word=word;
        printf("%d\n",word);
    }
    return 0;
}
