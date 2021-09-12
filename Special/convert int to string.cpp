#include<stdio.h>
int main()
{
    char lod[1000],reverse[1000];
    int N = 12345,i = 0,j;
    printf("integer %d\n",N);
    while( N!=0 ){
        lod[i++] = (N%10) + '0';
        N/=10;
    }
    lod[i] ='\0';
    printf("string %s\n",lod);
    for(j=i-1;j>=0;j--)
    reverse[i-1-j]=lod[j];
    reverse[i]='\0';
    printf("reverse %s\n",reverse);
    return 0;
}
