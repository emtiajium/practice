#include<stdio.h>
#include<string.h>
char stack[100]={"ABCDE"};
int len,p;
int main()
{
    freopen("input.txt","r",stdin);
    len=strlen(stack);
    printf("top %c\n",stack[len-1]);
    while(1){
        printf("push->1\npop->2\nnothing->3\n\n");
        scanf("%d",&p);
        getchar();
        puts("");
        if(p==1){
            len++;
            scanf("%c",&stack[len-1]);
            printf("\ntop %c\n",stack[len-1]);
        }
        else if(p==2){
            len--;
            if(len<=0) puts("\nStack empty");
            else printf("\ntop %c\n",stack[len-1]);
        }
        else if(p==3) break;
        puts("");
    }
    return 0;
}
