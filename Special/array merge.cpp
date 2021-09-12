#include<stdio.h>
int main()
{
    int arr1[20] = { 10  , 20  , 30 , 40 , 50};
    int arr2[] = { 60 , 70 , 80 , 90 , 100};
    int i;

  /* Given arr1 and arr2 are the two sorted arrays of length 5 , 5 respectivly
   Following code will merg the contents of arr2 with the contents of arr1 */

    for( i = 0 ; i < 5 ; i++)
        arr1[i+5] = arr2[i];
  /* Print the contents of the arr1 */

    printf("Contents of the arr1 after merging :");

    for( i = 0 ; i < 10 ;i++)
        printf("%d " , arr1[i]);

    printf("\n");
return 0;
}
