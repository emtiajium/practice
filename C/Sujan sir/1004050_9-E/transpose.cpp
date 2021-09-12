#include<stdio.h>

void main()
{

	int mat1[3][4], mat2[4][3];

	int i,j;

	printf("Enter matrix :");


	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			scanf("%d",&mat1[i][j]);

	
	for(i=0;i<4;i++)
		for(j=0;j<3;j++)
			mat2[i][j]=mat1[j][i];




	printf("Transpose of Matrix :\n");
			
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)
			
		{
			printf(" %d  ",mat2[i][j]);
		}

		printf("\n");
	}


}