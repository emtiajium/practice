#include<stdio.h>
#include<conio.h>
main()
{
	//1+2+4+7+......
    int sum=1,count,total=0,n;
    scanf("%d",&n);
    for(count=0;count<n;count++)
    {
        sum+=count;
        total+=sum;
    }
        printf("%d\n",total);

    getch();
}

