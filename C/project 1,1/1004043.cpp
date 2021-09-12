#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
int main ()
{
	double x,sum=0,fact=1;
	int a,b,c,i,n,m,j,l;
	float e,f,stop,answer,k;
printf("\t\tTHIS IS A PROJECT OF CALCULATOR");
printf("\n\n\t\t\t WELCOME         ");
printf("\n\n Add=1  \t\tSubtract=2  \t\tMaltipication=3   \n Divition=4  \t\tSquer=5  \t\tCube=6");

	   printf("\n Cos x=7  \t\tFactoryal=8  \t\tSin x=9  \n\t\t\tStop=0 ");
for (m=0;m<=100;m++)
{
printf("\n\nENTER THE NUMBER :");
scanf("%d",&a);

    if (a==1)
	{ 
	printf("\n\nEnter the frist number=");
	scanf("%f",&answer);
	for (l=0;l<=20;l++)
	{
	printf("\n\nEnter the scoend number=");
	scanf("%f",&f);
	answer=answer+f;
	if (f==0)
		break;
	
	printf ("ANSWER=%f",answer);
	}
	}
else if (a==2)
{ 
	printf("\n\nEnter the frist number=");
	scanf("%f",&e);
	printf("\n\nEnter the scoend number=");
	scanf("%f",&f);
	answer=e-f;
	printf ("ANSWER=%f",answer);
}
else if (a==3)
{ 
	printf("\n\nEnter the frist number=");
	scanf("%f",&e);
	printf("\n\nEnter the scoend number=");
	scanf("%f",&f);
	answer=e*f;
	printf ("ANSWER=%f",answer);
}
else if (a==4)
{ 
	printf("\n\nEnter the frist number=");
	scanf("%f",&e);
	printf("\n\nEnter the scoend number=");
	scanf("%f",&f);
	answer=e/f;
	printf ("ANSWER=%f",answer);
}
else if (a==5)
{ 
	printf("\n\nEnter the number=");
	scanf("%f",&e);
	 
	answer=pow (e,2);
	printf ("ANSWER=%f",answer);
}
else if (a==6)
{ 
	printf("\n\nEnter the number=");
	scanf("%f",&e);
	 
	answer=pow (e,3);
	printf ("ANSWER=%f",answer);
}
else if (a==7)
{  
	printf("Enter the value of x : ");
	scanf("%lf",&x);
 j=0;
	x=x*(3.1416/180);


	for(i=1;i<=20;i++)
	{
		if(i==1)
		{
			sum=sum+1;
		}
		else
		{
	     if((i%2)==0)
		{
			for(l=1;l<=j;l++)
			{	
				fact=fact*l;
			}
			sum=sum-pow(x,j)/fact;
			fact=1;
		 }
		 else
		 {
			 for(l=1;l<=j;l++)
			 {
				 fact=fact*l;
			 }
			 sum=sum+pow(x,j)/fact;
		     fact=1;
		 }
		}
j=j+2;	 
		 
		 
		 }
		 
printf("\ncosx=%.5lf",sum);
}
else if (a==8)
{ 
printf("Enter the number n:");
scanf ("%d",&n);
for(i=n;i>0;i--)
{
	fact=fact*i;
}
printf ("fact=%lf",fact);
} 



else if (a==9)
	{
	j=1;
	printf("Enter the value of x : ");
	scanf("%lf",&x);

	x=x*(3.1416/180);


	for(i=1;i<=20;i++)
	{
		if(i==1)
		{
			sum=sum+x;
		}
		else
		{
	     if(i%2==0)
		{
			for(k=1;k<=j;k++)
			{	
				fact=fact*k;
			}
			sum=sum-pow(x,j)/fact;
			fact=1;
		 }
		 else
		 {
			 for(k=1;k<=j;k++)
			 {
				 fact=fact*k;
			 }
			 sum=sum+pow(x,j)/fact;
		     fact=1;
		 }
		}
j=j+2;	 
		 
		 
		 }
		 
printf("\nsin x=%.5lf",sum);
	}
else if (a==0)
break;
} 
printf("\n  \t\tTHANKYOU FOR USEING CALCULATOR\n\n\n\t\t");
getch ();
return 0;
}
