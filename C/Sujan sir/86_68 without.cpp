#include<stdio.h>
int main()
{
    int a,b;
    scanf("%d",&a);
      while(a!=0){
	  b=a%10;
	  printf("%d",b);
	  a=a/10;
	  }
    printf("\n");
return 0;
}
