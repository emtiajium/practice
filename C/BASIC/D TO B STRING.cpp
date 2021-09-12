#include<stdio.h>
#include<math.h>
int number,i,j,k;
char remain[1000],reverse[1000];
int main()
{
    while(scanf("%d",&number)==1){
        i=0;
        while(number!=0){
            remain[i++]=(number%2)+'0';
            number/=2;
        }
        remain[i]='\0';
        for(j=i-1,k=0;j>=0;j--,k++)
            reverse[k]=remain[j];

        reverse[k]='\0';
        puts(reverse);
    }
return 0;
}
