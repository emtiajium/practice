//Love Calculator 10424
#include<stdio.h>
#include<math.h>
int sm(int );
char str1[30],str2[30];
double calc;
int main()
{
    int i,value,sum1,sum2,sum3,sum4;
    while(gets(str1)){
        gets(str2);
        for(i=0,sum1=0;str1[i];i++){
            if(str1[i]>96&&str1[i]<123) value=str1[i]-96;
            else if(str1[i]>64&&str1[i]<91) value=str1[i]-64;
            else value=0;
            sum1+=value;
        }
        for(i=0,sum2=0;str2[i];i++){
            if(str2[i]>96&&str2[i]<123) value=str2[i]-96;
            else if(str2[i]>64&&str2[i]<91) value=str2[i]-64;
            else value=0;
            sum2+=value;
        }
        //printf("s1 %d s2 %d\n",sum1,sum2);
        sum3=sm(sum1);
        sum4=sm(sum2);
        //printf("s3 %d s4 %d\n",sum3,sum4);
        if(sum3>sum4) calc=((double)sum4/(double)sum3)*100;
        else calc=((double)sum3/(double)sum4)*100;
        printf("%0.2lf %%\n",calc);
    }
    return 0;
}

int sm(int sum)
{
    int len,sum1,mod,i;
    len=log10(sum)+1;
    while(len>1){
        for(i=0,sum1=0;i<len;i++){
            mod=sum%10;
            sum1+=mod;
            sum/=10;
        }
        len=log10(sum1)+1;
        sum=sum1;
    }
    return sum;
}
