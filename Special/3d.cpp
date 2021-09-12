#include<stdio.h>
const int Table=3,Row=3,Column=3;
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
        printf("Table %d\n",i);
        for(j=0;j<Row;j++){
            for(k=0;k<Column;k++)
                printf("[%d][%d][%d]-->%d\t",i,j,k,*(*(*( arr+i)+j)+k));

        printf("\n");
        }
    }
return 0;
}
