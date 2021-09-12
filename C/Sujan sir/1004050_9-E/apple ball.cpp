#include<stdio.h>
#include<string.h>
void main()
{
	char a[3][15],t[15];
	int i=0,j=0;
	while(i<3)
	{
		scanf("%s",a[i]);
		i++;
	}
	for(i=0;i<3-1;i++)
	{
		for(j=0;j<3-i-1;j++)
		{
			if(strcmp(a[j-1],a[j])>0)
			{
				strcpy(t,a[j-1]);
                strcpy(a[j-1],a[j]);
				strcpy(a[j],t);
			}
		}
	}
	printf("list\n");

    for(i=0;i<3;i++)
	{
	printf("\t%s \n",a[i]);
	}
}

