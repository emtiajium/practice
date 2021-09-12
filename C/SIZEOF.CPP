#include<stdio.h>
#include<conio.h>
main()
{

	int a,szo_a;
	float b,szo_b;
	char c[1],szo_c;
	long long d,szo_d;

	printf("Enter the value of a:");
	scanf("%d",&a);
	printf("a =%d",a);
	szo_a = sizeof(a);
	printf("\nsize of integer = %d bytes",szo_a);

	printf("\nEnter the value of b:");
	scanf("%f",&b);
	printf("b =%f",b);
	szo_b = sizeof(b);
	printf("\nsize of floating point = %f bytes",szo_b);

	printf("\nEnter the value of c:");
	scanf("%s",&c);
	printf("c =%s",c);
	szo_c = sizeof(c);
	printf("\nsize of character = %d bytes",szo_c);

    printf("\nEnter the value of d:");
	scanf("%lld",&d);
	printf("d =%lld",d);
	szo_d = sizeof(d);
	printf("\nsize of long long integer = %lld bytes",szo_d);



	getch();
	return 0;
}


