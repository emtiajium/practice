#include<stdio.h>
int t,c,i,j,len,arr[305];
char ch[305];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    for(c=1;c<=t;c++){
        for(i=0;;i++){
            ch[i]=getchar();
            if(ch[i]=='\n') break;
            scanf("%d",&arr[i]);
        }
        len=i;
        printf("Case %d: ",c);
        for(i=0;i<len;i++){
            for(j=0;j<arr[i];j++){
                putchar(ch[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
