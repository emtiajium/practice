#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <dos.h>

long long dtob(long long);
long long dtoo(long long);
void dtoh(long long);
long long btod(long long);
long long btoo(long long);
void btoh(long long);
long long otod(long long);
long long otob(long long);
void otoh(long long);
long long htod(char y[], int x);
long long htob(char y[], int x);
long long htoo(char y[], int x);

int main()
{
clrscr();
int p,z;
long long a;
char q,r[101];
while(2)
{
clrscr();
delay(1500);
printf("***************** Welcome To Requiem's Base Conversion System *****************\n");
delay(1500);
printf("\nSelect the base of the input number : \n\n");
delay(1500);
printf("1. Decimal\n");
delay(500);
printf("2. Binary\n");
delay(500);
printf("3. Octal\n");
delay(500);
printf("4. Hexadecimal\n");
delay(500);
printf("5. Quit\n");
delay(1500);
printf("\nEnter your desired type conversion : ");
scanf("%d",&p);
clrscr();
if(p==1)
{
clrscr();
printf("***************** Welcome To Requiem's Base Conversion System *****************\n");
printf("\nEnter the Decimal number : ");
scanf("%lld", &a);
printf("\nThe Binary form of %lld is %lld\n",a,dtob(a));
printf("The Octal form of %lld is %lld\n", a, dtoo(a));
printf("The Hexadecimal form of %lld is ", a),dtoh(a);
printf("\n");
}
else if(p==2)
{
clrscr();
printf("***************** Welcome To Requiem's Base Conversion System *****************\n");
printf("\nEnter the Binary number : ");
scanf("%lld", &a);
printf("\nThe Decimal form of %lld is %lld\n",a,btod(a));
printf("The Octal form of %lld is %lld\n", a, btoo(a));
printf("The Hexadecimal form of %lld is ", a);
btoh(a);
printf("\n");
}
else if(p==3)
{
clrscr();
printf("***************** Welcome To Requiem's Base Conversion System *****************\n");
printf("\nEnter the Octal number : ");
scanf("%lld", &a);
printf("\nThe Decimal form of %lld is %lld\n",a,otod(a));
printf("The Binary form of %lld is %lld\n", a, otob(a));
printf("The Hexadecimal form of %lld is ", a);
otoh(a);
printf("\n");
}
else if(p==4)
{
clrscr();
printf("***************** Welcome To Requiem's Base Conversion System *****************\n");
printf("\nEnter the Hexadecimal number : ");
scanf("%s", &r);
z=strlen(r);
printf("\nThe Decimal form of %s is %lld\n",r,htod(r,z));
printf("The Binary form of %s is %lld\n", r, htob(r,z));
printf("The Octal form of %s is %lld\n", r, htoo(r,z));
}
if(p==5)
break;
printf("Convert again? Y/N");
asd:
q=getch();
if(q=='y'||q=='Y')
continue;
else if(q=='n'||q=='N')
break;
else
goto asd;
}
clrscr();
gotoxy(23,13);
printf("Thank you !!! See you again !!!");
getch();
return 0;
}

long long dtob (long long b)
{
int i,g;
long long d;
i=0,d=0;
while(b)
{
g=b%2;
d+=g*pow(10,i);
b=b/2;
i++;
}
return d;
}

long long dtoo(long long b)
{
int i,g;
long long d;
i=0,d=0;
while(b)
{
g=b%8;
d+=g*pow(10,i);
b=b/8;
i++;
}
return d;
}

void dtoh(long long b)
{
int i,g;
char d[101];
i=0;
while(b)
{
g=b%16;
if(g<10)
d[i]=g+'0';
else if(g==10)
d[i]='A';
else if(g==11)
d[i]='B';
else if(g==12)
d[i]='C';
else if(g==13)
d[i]='D';
else if(g==14)
d[i]='E';
else if(g==15)
d[i]='F';
b=b/16;
i++;
}
d[i]='\0';
strrev(d);
puts(d);
}

long long btod (long long b)
{
int i,g;
long long d;
i=0,d=0;
while(b)
{
g=b%10;
d+=g*pow(2,i);
b=b/10;
i++;
}
return d;
}

long long btoo(long long b)
{
long long d,e;
d=btod(b);
e=dtoo(d);
return e;
}

void btoh(long long b)
{
long long d;
d=btod(b);
dtoh(d);
}

long long otod(long long b)
{
int i,g;
long long d;
i=0,d=0;
while(b)
{
g=b%10;
d+=g*pow(8,i);
b=b/10;
i++;
}
return d;
}

long long otob(long long b)
{
long long d,e;
d=otod(b);
e=dtob(d);
return e;
}

void otoh(long long b)
{
long long d;
d=otod(b);
dtoh(d);
}

long long htod(char r[], int b)
{
int i,g;
long long d;
char s[101];
d=0;
strcpy(s,r);
strrev(s);
for(i=0;i<b;i++)
{
if(s[i]>='0'&&s[i]<='9')
g=s[i]-'0';
else if(s[i]=='A')
g=10;
else if(s[i]=='B')
g=11;
else if(s[i]=='C')
g=12;
else if(s[i]=='D')
g=13;
else if(s[i]=='E')
g=14;
else if(s[i]=='F')
g=15;
d+=g*pow(16,i);
}
return d;
}

long long htob(char r[], int b)
{
long long d,e;
d=htod(r,b);
e=dtob(d);
return e;
}

long long htoo(char r[], int b)
{
long long d,e;
d=htod(r,b);
e=dtoo(d);
return e;
}
