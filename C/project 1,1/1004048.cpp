#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
int oct(int a);
int hex(int a);
int bin(int a);
int main()
{
	int a,g,k,c,sum;
	char ch;
	printf("\n To stop press :ctrl+z");
	printf("\n For Decimal Press 1.");
		printf("\nFor  Binary Press   2.");
	printf("\nFor  Octal   Press  3.");
	printf("\nFor  Hexadecimal Press 4:");
	printf("\n I pressed=");
	while(scanf("%d",&g)!=EOF)
	{ch=getchar();
if(g==1)

{	printf("\n Enter a decimal number:");
	scanf("%d",&a);	
	printf("The Octal equvalent is =");
	oct(a);
	printf("\n The Hexadecimal equvalent is =");
	hex(a);
	printf("\n The Binary equvalent is =");	
	bin(a);
	printf("\nI pressed=");
}
 else if(g==2)
 {
printf("\n Enter a binary number:");
scanf("%d",&k);
int b,c=0,i=0,f;
while(k!=0)
{
	b=k%10;
	f=b * pow(2,i);
	c+=f;
	i++;
	k=k/10;
}
printf("\n The decimal equvalent is =%d",c);
a=c;
printf("\n The Octal equvalent is = ");
oct(a);
printf("\n the Hexadecimal equvalent is = ");
hex(a);
printf("\nI pressed=");
 }
 else if(g==3)
 {
	 printf("\n Enter a Octal number:");
	 scanf("%d",&k);
	 int i=0,c=0,b,f;
	 while(k!=0)
	 {
		 b=k%10;
		 f=b*pow(8,i);
		 c+=f;
		 i++;
		 k=k/10;
	 }
	 printf("\n The decimal equvalent is =%d",c);
	 a=c;
	 printf("\n The Hexadecimal equvalent is =");
	 hex(a);
	 printf("\n The Binary equvalent is =");
	 bin(a);
	 printf("\nI pressed=");
 }
 else if (g==4)
 {
	 char s[100];
	 int sum=0,i,j,dd[100],q,y;
	 printf("\nEnter a hexadecimal number:\n\n");
      gets(s);
      y=strlen(s);
      for(i=0;i<y;i++)
      {
       if(s[i]=='A'||s[i]=='a')
        dd[i]=10;
        
        else if(s[i]=='B'||s[i]=='b')
        dd[i]=11;
        else if(s[i]=='C'||s[i]=='c')
        dd[i]=12;
        else if(s[i]=='D'||s[i]=='d')
        dd[i]=13;
        else if(s[i]=='E'||s[i]=='e')
        dd[i]=14;
        else if(s[i]=='F'||s[i]=='f')
        dd[i]=15;
        else
        dd[i]=s[i]-'0';}
        for(j=i-1,k=0;j>=0;j--,k++)
        sum+=dd[j]*(pow(16,k));
        
      
      
		printf("\nThe Decimal equvalent is= %d",sum);
		a=sum;
	 printf("\n The Octal equvalent is =");
	oct(a);
	printf("\n The Binary equvalent is =");
	bin(a);
	printf("\nI pressed=");
	
}}}
int oct(int a)
{
	int b[80],i=1,j;
	while(a!=0)
	{
		b[i]=a%8;
		a=a/8;
		i++;
	}
	for(j=i-1;j>=1;j--)
	{

		 printf("%d",b[j]);
	}
	
	return 0;
}
int hex(int a)
{
	int b[90],i=1,j;
	while(a!=0)
	{
		b[i]=a%16;
		a=a/16;
		i++;
	}
	for(j=i-1;j>=1;j--)
	{

	if(b[j]==10)
	printf("A");
		else if(b[j]==11)
			printf("B");
		else if(b[j]==12)
			printf("C");
		else if(b[j]==13)
			printf("D");
		else if(b[j]==14)
			printf("E");
		else if(b[j]==15)
			printf("F");
		else
			printf("%d",b[j]);
	}
	
 return 0;
}
int bin(int a)
{
	int b[80],i=1,j;
	while(a!=0)
	{
		b[i]=a%2;
		a=a/2;
		i++;
	}
	for(j=i-1;j>=1;j--)
	 	
	{	printf("%d",b[j]);
	}
	
return 0;
}

