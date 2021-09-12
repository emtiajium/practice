#include <algorithm>
#include<stdio.h>
using namespace std;
int array[2000000];
int main()
{
	int i,N;
	while(scanf("%d",&N)&&N!=0){
	    for(i=0;i<N;i++)
            scanf("%d",&array[i]);
       sort(array, array + N);
       for(i=0;i<N;i++){
           printf("%d",array[i]);
           if(i<N-1) printf(" ");
       }
       printf("\n");
    }
   return 0;
}
