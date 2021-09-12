#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include<dos.h>


int b2dec(long int a);
int o2dec(long int a);
int bin(long int a);
int hex(long int a);
int oct(long int a);


int main()
{

 m:
 clrscr();
 int t;
 printf ("\t\t A PROJECT ON BASE CONVERTION\n\t\t");
	delay(500);
 printf("       DOER:M G H HIMU");
	delay(500);
 printf("\n\t\tCOURSE TEACHER:SUJAN CHOWDHURY");
	 delay(1000);
 printf("\n\n    CHOOSE FRM D MENU(press d corresponding digit to choose):\n\t");
	 delay(100);
 printf("1.DECIMAL TO BINARY,HEXDECIMAL & OCTAL NUMBER; ");
	 delay(100);
 printf("\n\t2.BINARY TO DECIMAL,HEXADECIMAL & OCTAL NUMBER;");
	 delay(100);
 printf("\n\t3.OCTAL TO DECIAL,BINARY & HEXADECIMAL;");
	 delay(100);
 printf("\n\t4.HEXADECIMAL TO DECIMAL,BINARY & OCTAL;");
 printf("\n\t5.Exit.");
 printf("\n\n\n\n\n\t\t\tPRESS HERE:");
 scanf("%d",&t);
 if(t==1)
 goto h;
 else if(t==2)
 goto i;
 else if(t==3)
 goto j;
 else if(t==4)
 goto k;
 else
 goto n;


 h:
 long int a;
 int o;
 clrscr();
 printf("Enter a DECIMAL nimber = ");
 scanf("%ld",&a);
 bin(a);
 hex(a);
 oct(a);
 printf("\n\n\tTO CONTINUE - PRESS 1 \n\n\tTO EXIT - PRESS 0\n\n\t\t\tPRESS HERE:");
 scanf("%d",&o);
 if(o==1)
  goto m;
 else
  goto n;


 i:
 long int b;
 clrscr();
 printf("Enter a BINARY number = ");
 scanf("%ld",&b);
 b2dec(b);
 printf("\n\n\tTO CONTINUE - PRESS 1 \n\n\tTO EXIT - PRESS 0\n\n\t\t\t\tPRESS HERE:");
 scanf("%d",&o);
 if(o==1)
  goto m;
 else
  goto n;


 j:
 long int c;
 clrscr();
 printf("Enter an OCTAL number = ");
 scanf("%d",&c);
 o2dec(c);
 printf("\n\n\tTO CONTINUE - PRESS 1 \n\n\tTO EXIT PRESS - 0\n\n\t\t\tPRESS HERE:");
 scanf("%d",&o);
 if(o==1)
  goto m;
 else
  goto n;


 k:
 char d[200];
 long l,g;
 int f,i;
 clrscr();
 printf("Enter a HEXADECIMAL number = ");
 scanf("%s",d);
 strrev(d);
 f=strlen(d);
 l=0;
	for(i=0;i<f;i++)
	 {
		if(d[i]>='0'&&d[i]<='9')
		 {
		  g=d[i]-'0';
		  g=g*pow(16,i);
		 }
		else if(d[i]>='A'&&d[i]<='Z')
		 {
		  g=d[i]-'A'+10;
		  g=g*pow(16,i);
		 }
		 l=l+g;
	  }
	printf("\nDEC=%d",l);
 bin(l);
 oct(l);
 printf("\n\n\tTO CONTINUE - PRESS 1 \n\n\tTO EXIT - PRESS 0\n\n\t\t\tPRESS HERE:");
 scanf("%d",&o);
 if(o==1)
  goto m;
 else
  goto n;


 n:
 printf("\n\t\t\tEND OF PROGRAM.\n\t\t\tTHANX FOR BEING WITH ME.");


getch();
return 0;
}


int b2dec(long int a)
{
long int c,d,i;
 d=0;i=0;
 while(a!=0)
 {
  c=a%10;
  a=a/10;
  c=c*pow(2,i);
  d=d+c;
  i++;
 }
  printf("\nDEC=%ld",d);
  hex(d);
  oct(d);
return 0;
}


int o2dec(long int a)
{
long int c,d,i;
d=0;i=0;
 while(a!=0)
 {
  c=a%10;
  a=a/10;
  c=c*pow(8,i);
  d=d+c;
  i++;
 }
  printf("\nDEC=%ld",d);
  bin(d);
  hex(d);
return 0;
}


int bin(long int a)
{
 char s[200];
 long int c,i;
 i=0;
  while(a!=0)
	{
	 c=a%2;
	 a=a/2;
	 s[i]=c+'0';
	 i++;
	}
	 s[i]='\0';
	 strrev(s);
	 printf("\nBIN=%s",s);
return 0;
}


int hex(long int a)
{
 char s[100];
 long int c,i;
 i=0;
  while(a!=0)
	{
	 c=a%16;
	 a=a/16;
	 if(c<=9)
	 s[i]=c+'0';
	 else
	 {
		if(c==10)
		 s[i]='A';
		 else if(c==11)
		 s[i]='B';
		 else if(c==12)
		 s[i]='C';
		 else if(c==13)
		 s[i]='D';
		 else if(c==14)
		 s[i]='E';
		 else if(c==15)
		 s[i]='F';
	 }
	 i++;
	}
	 s[i]='\0';
	 strrev(s);
	 printf("\nHEX=%s",s);
return 0;
}


int oct(long int a)
{
 char s[100];
 long int c,i;
 i=0;
  while(a!=0)
	{
	 c=a%8;
	 a=a/8;
	 s[i]=c+'0';
	 i++;
	}
	 s[i]='\0';
	 strrev(s);
	 printf("\nOCT=%s",s);
return 0;
}
