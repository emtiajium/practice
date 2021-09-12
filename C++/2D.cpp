//column parameter of the matrix as a default argument
#include<stdio.h>
void two(int arr[][2],int R,int C=2);//prototype
int main()
{
    int R=3;
    int arr[R][2];
    two(arr,R);//default for 3rd argument
return 0;
}

void two(int arr[][2],int R,int C)//size of 2nd dimension must be specified
{
    int i;
    for(i=0;i<R;i++)
        scanf("%d %d",&arr[i][0],&arr[i][1]);

    for(i=0;i<R;i++)
        printf("%d %d\n",arr[i][0],arr[i][1]);
}


