#include<stdio.h>
#include<conio.h>
#include<string.h>
int binary_todec(int a)
{
int b,c;
int e=1,sum=0;
 while(a!=0)
 {
   b=a%10;
   c=b*e;
   e=e*2;
   sum+=c;
   a=a/10;
 }
return sum;
}

int octal_todec(int a)
{
int b,c;
int e=1,sum=0;
 while(a!=0)
 {
   b=a%10;
   c=b*e;
   e=e*8;
   sum+=c;
   a=a/10;
 }
return sum;
}

int hexadec_todec(char a[])
{
int b,i;
int c=1,sum=0;
char ch;
int length=strlen(a);
int value;
 for(i=length-1;i>=0;i--)
 {
   ch=a[i];
   switch(ch)
   {
     case'0':value=0;break;
     case'1':value=1;break;
     case'2':value=2;break;
     case'3':value=3;break;
     case'4':value=4;break;
     case'5':value=5;break;
     case'6':value=6;break;
     case'7':value=7;break;
     case'8':value=8;break;
     case'9':value=9;break;
     case'a':value=10;break;
     case'b':value=11;break;
     case'c':value=12;break;
     case'd':value=13;break;
     case'e':value=14;break;
     case'f':value=15;break;
     case'A':value=10;break;
     case'B':value=11;break;
     case'C':value=12;break;
     case'D':value=13;break;
     case'E':value=14;break;
     case'F':value=15;break;
   }
   b=value*c;
   c=c*16;
   sum+=b;
 }
return sum;
}


void decimal_tobin(int a)
{
int n,i;
int b[100];
n=0;
 while(a>0)
 {
   b[n]=a%2;
   a=a/2;
   n++;
 }
printf("\tThe binary number is:");
for(i=n-1;i>=0;i--)
   printf("%d",b[i]);
printf("\n");
}

void decimal_tohex(int a)
{
int n,i;
int b[100];
n=0;
 while(a>0)
 {
   b[n]=a%16;
   a=a/16;
   n++;
 }
printf("\tThe hexadecimal number is:");
for(i=n-1;i>=0;i--)
  {
   if(b[i]<10)
    printf("%d",b[i]);
   else if(b[i]==10)
    printf("A");
   else if(b[i]==11)
    printf("B");
   else if(b[i]==12)
    printf("C");
   else if(b[i]==13)
    printf("D");
   else if(b[i]==14)
    printf("E");
   else if(b[i]==15)
    printf("F");
   }
   printf("\n");
}

void decimal_toOct(int a)
{
int n,i;
int b[100];
n=0;
 while(a>0)
 {
   b[n]=a%8;
   a=a/8;
   n++;
 }
printf("\tThe octal number is:");
for(i=n-1;i>=0;i--)
  printf("%d",b[i]);
printf("\n");
}


void conversion()
{
 char ch;
 int a,b;
 while(1)
 {
  clrscr();
  printf("\n\n\n\n\t\t#A PROGRAM FOR NUMBER CONVERSION#");
  printf("\n\n\n\t\t\tWHAT TYPE OF CONVERSION DO YOU WANT?");
  printf("\n\n\t\t\tFrom Binary to All Press B");
  printf("\n\t\t\tFrom Hexadecimal to All Press H");
  printf("\n\t\t\tFrom Decimal to All Press D");
  printf("\n\t\t\tFrom Octal to All Press O");
  printf("\n\t\t\tFor Quit press Q\n");
    ch=getchar();
    if(ch=='B'||ch=='b')
    {
      printf("\tEnter a binary number:");
      scanf("%d",&a);
      b=binary_todec(a);
      printf("\tThe decimal number is:%d\n",b);
      decimal_tohex(b);
      decimal_toOct(b);
    }
    else if(ch=='H'||ch=='h')
    {
      char hex[100];
      printf("\tEnter a hexadecimal number:");
      scanf("%s",hex);
      b=hexadec_todec(hex);
      printf("\tThe decimal number is:%d\n",b);
      decimal_tobin(b);
      decimal_toOct(b);
    }
    else if(ch=='D'||ch=='d')
    {
      printf("\tEnter a decimal number:");
      scanf("%d",&a);
      decimal_tobin(a);
      decimal_tohex(a);
      decimal_toOct(a);
    }
    else if(ch=='O'||ch=='o')
    {
      printf("\tEnter a octal number:");
      scanf("%d",&a);
      b=octal_todec(a);
      printf("\tThe decimal number is:%d\n",b);
      decimal_tobin(b);
      decimal_tohex(b);
    }
    else if(ch=='Q'||ch=='q')
    {
    break;
    }
  getch();
  }
}


int main()
{
  clrscr();
  conversion();
  return 0;
  getch();
}




