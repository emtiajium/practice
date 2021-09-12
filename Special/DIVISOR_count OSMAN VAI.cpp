#include<stdio.h>
#include<iostream>
using namespace std;
const int SIZE=1000005;//<=10^6
int k,l,arr[SIZE]={0,1},n;
int main()
{
    for(k=2;k<=SIZE;k++){
        for(l=k;l<=SIZE;l+=k){
            arr[l]++;
        }
        arr[k]++;
    }
    while(scanf("%d",&n)==1)
        printf("Number of divisor %d\n",arr[n]);
    return 0;
}
