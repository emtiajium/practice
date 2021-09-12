//Leap Year or Not Leap Year _10070
#include<stdio.h>
#include<string.h>
char str[10000];
int len,four,five,sum,three,four_hun,eleven,i;
bool fl,hl,bl,b_line;
int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(str)){
        fl=0;
        hl=0;
        bl=0;
        if(b_line==true) printf("\n");//puts("\n"); is two newlines
        b_line=true;
        len=strlen(str);
        four=(str[len-2]-48)*10+(str[len-1]-48);
        five=str[len-1]-48;
        four_hun=(str[len-4]-48)*1000+(str[len-3]-48)*100+(str[len-2]-48)*10+(str[len-1]-48);
        for(i=0,sum=0;i<len;i++){
            sum+=(str[i]-48);
        }
        three=sum;
        for(i=0,sum=0;i<len;i++){
            if(i%2==0) sum+=(str[i]-48);
            else sum-=(str[i]-48);
        }
        eleven=sum;
        if(four%4==0){
            fl=1;
            if(str[len-2]=='0'&&str[len-1]=='0'){
                if(four_hun%400==0) fl=1;
                else fl=0;
            }
        }
        if(fl==1) puts("This is leap year.");
        if(three%3==0&&five%5==0){
            hl=1;
            puts("This is huluculu festival year.");
        }
        if(fl==1){
            if(eleven%11==0&&five%5==0){
                bl=1;
                puts("This is bulukulu festival year.");
            }
        }
        else if(fl==0&&hl==0&&bl==0)puts("This is an ordinary year.");
    }
    return 0;
}
