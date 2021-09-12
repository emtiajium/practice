#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const int SIZE=1000010;
int k,l,condition,r,prime_list[SIZE];
bool flag[SIZE]={1,1,0};

int n,mod,temp_n,t_r;
char reverse[SIZE];
int main()
{
    for(k=4;k<=SIZE;k+=2)
        *(flag+k)=1;

    condition=(int)(sqrt((double)SIZE));
    for(k=3;k<=condition;k+=2){
        r=k+k;
        if(*(flag+k)==0){
            for(l=k*k;l<=SIZE;l+=r)
                *(flag+l)=1;
        }
    }
    while(scanf("%d",&n)==1){
        if( *(flag+n) ==1) printf("%d is not prime.\n",n);
        else if( *(flag+n) ==0){
            temp_n=n;
            k=0;
            while(n!=0){
                mod=n%10;
                *(reverse+k)=mod+48;
                n/=10;
                k++;
            }
            *(reverse+k)='\0';
            t_r=atoi(reverse);
            if(temp_n==t_r && *(flag+t_r)==0) printf("%d is prime.\n",temp_n);// 2,11
            else if(temp_n==t_r && *(flag+t_r)==1) printf("%d is prime.\n",temp_n);
            else if(temp_n!=t_r && *(flag+t_r)==0) printf("%d is emirp.\n",temp_n);
            else if(temp_n!=t_r && *(flag+t_r)==1) printf("%d is prime.\n",temp_n);
        }
    }
return 0;
}
