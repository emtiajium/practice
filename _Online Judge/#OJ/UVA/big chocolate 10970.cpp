#include<stdio.h>
int main()
{
    int row,column;
    while(scanf("%d %d",&row,&column)==2){
        printf("%d\n",(row*column)-1);
    }
    return 0;
}
