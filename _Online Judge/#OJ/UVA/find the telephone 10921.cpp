#include<stdio.h>
char ch;
int main()
{
    while((ch=getchar())!=EOF)
    {
        if(ch=='\n')printf("\n");
        else if(ch>64&&ch<68) printf("2");
        else if(ch>67&&ch<71) printf("3");
        else if(ch>70&&ch<74) printf("4");
        else if(ch>73&&ch<77) printf("5");
        else if(ch>76&&ch<80) printf("6");
        else if(ch>79&&ch<84) printf("7");
        else if(ch>83&&ch<87) printf("8");
        else if(ch>86&&ch<91) printf("9");
        else printf("%c",ch);

    }
    return 0;
}
