#include<stdio.h>
#include<conio.h>
int main()
{
    int i,n,b,j,x,y;
    printf("enter number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("enter the numbers:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                b=a[j+1];
                a[j+1]=a[j];
                a[j]=b;
            }
        }
    }
    for(j=0;j<n;j++)
    {
        printf("%d ",a[j]);
    } 
    if(n%2!=0)
    {
        x=(n/2);
        printf("middle number=%d",a[x]);
    }
    else
    {
        x=(n-1)/2;
        y=n/2;
        printf("middle number %d %d",a[x],a[y]);
    }               
    getch();
}                   
