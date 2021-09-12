#include<stdio.h>
#include<math.h>

void main()
{
int a,b,i=0,s=0,c,d,e,n=0,q;
printf("\t\t//*** NUMBER CONVERSION PROGRAM ***//\n");
Z:
{
i=0; s=0; c=0; e=0; n=0; q=0; b=0;
printf("Your options are here--\n");
printf("\n\t1.Decimal\n");
printf("\t2.Hexadecimal\n");
printf("\t3.Octal\n");
printf("\t4.Binary\n");
printf("\t0.To stop\n");

printf("Enter your choice to choose a number catagory you want to input: ");
scanf("%d",&a);

if(a==1)
goto A;
else if(a==2)
goto B;
else if(a==3)
goto C;
else if(a==4)
goto D;
else if(a==0)
goto E;

}

A:
{

printf("\nEnter your number: ");
scanf("%d",&b);
printf("\nOctal=%o",b);
printf("\tHexadecimal=%X",b);
printf("\tBinary=");
i=0;

d=9;
while(d!=0)
{
c=b%2;
d=b/2;
s=s+(c*pow(10,i));
b=d;
i++;
}
printf("%d\n",s);

goto Z;
}

B:
{

printf("\nEnter your number: ");
scanf("%X",&b);
printf("\nOctal=%o",b);
printf("\tDecimal=%d",b);
printf("\tBinary=");
q=0;
i=0;
while(b!=0)
{
c=b%2;
b=b/2;
q=q+(c*pow(10,i));
i++;
}
printf("%d\n",q);

goto Z;
}

C:
{

printf("\nEnter your number: ");
scanf("%o",&b);
printf("\nHexadecimal=%X",b);
printf("\tDecimal=%d",b);
printf("\tBinary=");
q=0;
i=0;
while(b!=0)
{
c=b%2;
b=b/2;
q=q+(c*pow(10,i));
i++;
}
printf("%d\n",q);


goto Z;
}

D:
{

printf("\nEnter your number: ");
scanf("%d",&b);
printf("\nDecimal=");
i=0;
e = 9;
while(e!=0)
{
e=b/10;
c=b%10;
d=c*pow(2,i);
s=s+d;
b=e;
i++;
}
printf("%d",s);
printf("\tHexadacimal=%X",s);
printf("\tOctal=%o\n",s);

goto Z;
}

E:
{

printf("\nThank you for using this program\n\n\n");
}

}