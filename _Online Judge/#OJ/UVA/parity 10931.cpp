#include<stdio.h>
char remainder[100],reverse[100];
int main()
{
    int number,i,j,k,sum,count;
    while(scanf("%d",&number)&&(number!=0)){
        count=0;
        i=0;
        while(number!=0){
            remainder[i]=(number%2)+'0';
            if(remainder[i]=='1') count++;
            number=number/2;
            i++;
        }
        remainder[i]='\0';
        for(j=i-1,k=0;k<i;j--,k++){
            reverse[k]=remainder[j];
        }
        reverse[i]='\0';
        printf("The parity of %s is %d (mod 2).\n",reverse,count);
    }
return 0;
}
