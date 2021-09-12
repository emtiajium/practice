#include<stdio.h>
enum Size{Table=3,Row=3,Column=3};
int main()
{
    int i, j, k;
    int arr[Table][Row][Column]=
        {
            {
            {11, 12, 13},
            {14, 15, 16},
            {17, 18, 19}
            },
            {
            {21, 22, 23},
            {24, 25, 26},
            {27, 28, 29}
            },
            {
            {31, 32, 33},
            {34, 35, 36},
            {37, 38, 39}
            },
        };
    for(i=0;i<Table;i++){
        for(j=0;j<Row;j++)
            printf("%d %d %d\n",arr[i][j][0],arr[i][j][1],arr[i][j][2]);

    printf("\n");
    }
return 0;
}
