#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

int binary[1000],octal[1000],hexa[1000]; //global variables

int decimaltobinary(int decimal);
int decimaltooctal(int decimal);
int decimaltohexa(int decimal);
int binarytodecimal(int binary);
int octaltodecimal(int octal);
int hexatodecimal(int hexa);


main()
{
	while(1)
	{
		clrscr();
		printf("\n\n\n\n\n\n\n\n\n\t\t\t\t       MENU\n\n");
		printf("\t\t     [1] Decimal to Binary,Octal,Hexadecimal\n");
		printf("\t\t     [2] Binary to Decimal,Octal,Hexadecimal\n");
		printf("\t\t     [3] Octal to Decimal,Binary,Hexadecimal\n");
		printf("\t\t     [4] Hexadecimal to Decimal,Binary,Octal\n");

		printf("\n\n\t\t                  Press 0 to exit.");
		int menu,decimal,i;
		char c[1000];
		scanf("%d",&menu);
		if(menu==0)
		{
			break;
		}
		else if (menu==1)
		{
			clrscr();
			printf("\n\n\n\n\n\n\t\t      Decimal to Binary,Octal,Hexadecimal\n");
			printf("\t\t      -----------------------------------\n");
			printf("\n\n\n\t\t           Enter Decimal Number :  ");
			scanf("%d",&decimal);

			int length=decimaltobinary(decimal);
			printf("\n\t\t       Equivalent Binary Number :  ");
			for(i=length-1;i>=0;i--)
			{
				printf("%d",binary[i]);
			}

			length=decimaltooctal(decimal);
			printf("\n\t\t       Equivalent Octal Number :  ");
			for(i=length-1;i>=0;i--)
			{
				printf("%d",octal[i]);
			}

			length=decimaltohexa(decimal);
			printf("\n\t\t       Equivalent Hexadecimal Number :  ");
			for(i=length-1;i>=0;i--)
			{
				if(hexa[i]<=9)
				printf("%d",hexa[i]);
				else if(hexa[i]==10)
				printf("A");
				else if(hexa[i]==11)
				printf("B");
				else if(hexa[i]==12)
				printf("C");
				else if(hexa[i]==13)
				printf("D");
				else if(hexa[i]==14)
				printf("E");
				else if(hexa[i]==15)
				printf("F");
			}
		}
		else if(menu==2)
		{
			clrscr();
			printf("\n\n\n\n\n\n\t\t      Binary to Decimal,Octal,Hexadecimal\n");
			printf("\t\t      -----------------------------------\n");
			printf("\n\n\n\t\t           Enter Binary Number :  ");

			scanf("%s",c);
			for(i=0;i<strlen(c);i++)
			{
				binary[i]=c[i]-'0';
			}
			decimal=binarytodecimal(strlen(c));
			printf("\n\t\t       Equivalent Decimal Number :  ");
			printf("%d",decimal);

			int length=decimaltooctal(decimal);
			printf("\n\t\t       Equivalent Octal Number :  ");
			for(i=length-1;i>=0;i--)
			{
				printf("%d",octal[i]);
			}

			length=decimaltohexa(decimal);
			printf("\n\t\t       Equivalent Hexadecimal Number :  ");
			for(i=length-1;i>=0;i--)
			{
				if(hexa[i]<=9)
				printf("%d",hexa[i]);
				else if(hexa[i]==10)
				printf("A");
				else if(hexa[i]==11)
				printf("B");
				else if(hexa[i]==12)
				printf("C");
				else if(hexa[i]==13)
				printf("D");
				else if(hexa[i]==14)
				printf("E");
				else if(hexa[i]==15)
				printf("F");
			}
		}
		else if(menu==3)
		{
			clrscr();
			printf("\n\n\n\n\n\n\t\t      Octal to Decimal,Binary,Hexadecimal\n");
			printf("\t\t      -----------------------------------\n");
			printf("\n\n\n\t\t           Enter Octal Number :  ");

			scanf("%s",c);
			for(i=0;i<strlen(c);i++)
			{
				octal[i]=c[i]-'0';
			}
			decimal=octaltodecimal(strlen(c));
			printf("\n\t\t       Equivalent Decimal Number :  ");
			printf("%d",decimal);

			int length=decimaltobinary(decimal);
			printf("\n\t\t       Equivalent Binary Number :  ");
			for(i=length-1;i>=0;i--)
			{
				printf("%d",binary[i]);
			}

			length=decimaltohexa(decimal);
			printf("\n\t\t       Equivalent Hexadecimal Number :  ");
			for(i=length-1;i>=0;i--)
			{
				if(hexa[i]<=9)
				printf("%d",hexa[i]);
				else if(hexa[i]==10)
				printf("A");
				else if(hexa[i]==11)
				printf("B");
				else if(hexa[i]==12)
				printf("C");
				else if(hexa[i]==13)
				printf("D");
				else if(hexa[i]==14)
				printf("E");
				else if(hexa[i]==15)
				printf("F");
			}
		}
		else if(menu==4)
		{
			clrscr();
			printf("\n\n\n\n\n\n\t\t      Hexadecimal to Decimal,Binary,Octal\n");
			printf("\t\t      -----------------------------------\n");
			printf("\n\n\n\t\t           Enter Hexadecimal Number :  ");

			scanf("%s",c);
			for(i=0;i<strlen(c);i++)
			{
				if(c[i]=='A')
				hexa[i]=10;
				else if(c[i]=='B')
				hexa[i]=11;
				else if(c[i]=='C')
				hexa[i]=12;
				else if(c[i]=='D')
				hexa[i]=13;
				else if(c[i]=='E')
				hexa[i]=14;
				else if(c[i]=='F')
				hexa[i]=15;
				else
				hexa[i]=c[i]-'0';
			}

			decimal=hexatodecimal(strlen(c));
			printf("\n\t\t       Equivalent Decimal Number :  ");
			printf("%d",decimal);

			int length=decimaltobinary(decimal);
			printf("\n\t\t       Equivalent Binary Number :  ");
			for(i=length-1;i>=0;i--)
			{
				printf("%d",binary[i]);
			}

			length=decimaltooctal(decimal);
			printf("\n\t\t       Equivalent Octal Number :  ");
			for(i=length-1;i>=0;i--)
			{
				printf("%d",octal[i]);
			}
		}
		getch();

	}
	return 0;
}

int decimaltobinary(int decimal) //returns length of binary[]
{
	int length=0;
	do
	{
		binary[length]=decimal%2;
		decimal=decimal/2;
		length++;
	}while(decimal!=0);
	return length;
}

int decimaltooctal(int decimal) //returns length of octal[]
{
	int length=0;
	do
	{
		octal[length]=decimal%8;
		decimal=decimal/8;
		length++;
	}while(decimal!=0);
	return length;
}

int decimaltohexa(int decimal) //returns length of hexa[]
{
	int length=0;
	do
	{
		hexa[length]=decimal%16;
		decimal=decimal/16;
		length++;
	}while(decimal!=0);
	return length;
}
int binarytodecimal(int length)//this length is for binary array
{
	int i,j,decimal=0;
	for(i=length-1,j=0;i>=0;i--,j++)
	{
		decimal=decimal+(binary[i])*pow(2,j);
	}
	return decimal;
}
int octaltodecimal(int length)//this length is for octal array
{
	int i,j,decimal=0;
	for(i=length-1,j=0;i>=0;i--,j++)
	{
		decimal=decimal+(octal[i])*pow(8,j);
	}
	return decimal;
}
int hexatodecimal(int length)//this length is for hexadecimalarray
{
	int i,j,decimal=0;
	for(i=length-1,j=0;i>=0;i--,j++)
	{
		decimal=decimal+(hexa[i])*pow(16,j);
	}
	return decimal;
}