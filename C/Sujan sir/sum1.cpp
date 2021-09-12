#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    int sum=0;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
      sum+=i;
    }
    printf("SUM IS %d",sum); 
    printf("\n");
    getch();
    return 0;
}
