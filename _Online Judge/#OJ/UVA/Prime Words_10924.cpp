// in this problem 1 is prime
#include<stdio.h>
#include<math.h>
const int SIZE=100000;
int i,j,condition,r;
bool flag[SIZE]={1,0,0};

char str[25];
int value,sum;

int main()
{
    for(i=4;i<=SIZE;i+=2)
        flag[i]=1;

    condition=sqrt((double)SIZE);;
    for(i=3;i<=condition;i+=2){
        r=i*2;
        if(*(flag+i)==0){
            for(j=i*i;j<=SIZE;j+=r)
                *(flag+j)=1;
        }
    }
    //freopen("input.txt","r",stdin);
    while(gets(str)){
        for(i=0,sum=0;str[i];i++){

            if(str[i]>64&&str[i]<91) value=(str[i]-64)+26;// capital A
            else if(str[i]>96&&str[i]<123) value=str[i]-96;
            sum+=value;
        }
        if(flag[sum]==0) puts("It is a prime word.");
        else puts("It is not a prime word.");
    }
    return 0;
}
