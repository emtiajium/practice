#include<stdio.h>
char str[110];
int t,c,i,sum;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    getchar();
    for(c=1;c<=t;c++){
        gets(str);
        sum=0;
        for(i=0;str[i];i++){
            if(str[i]=='a'||str[i]=='d'||str[i]=='g'||str[i]=='j'||str[i]=='m'||str[i]=='p'||str[i]=='t'||str[i]=='w'||str[i]==32)
            sum++;
            else if(str[i]=='b'||str[i]=='e'||str[i]=='h'||str[i]=='k'||str[i]=='n'||str[i]=='q'||str[i]=='u'||str[i]=='x')
            sum+=2;
            else if(str[i]=='c'||str[i]=='f'||str[i]=='i'||str[i]=='l'||str[i]=='o'||str[i]=='r'||str[i]=='v'||str[i]=='y')
            sum+=3;
            else if(str[i]=='s'||str[i]=='z')
            sum+=4;
        }
        printf("Case #%d: %d\n",c,sum);
    }
    return 0;
}
