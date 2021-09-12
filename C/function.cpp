#include<iostream>
#include<cmath>

using namespace std;

//overloading
double sroot(int a);
double sroot(long a);
double sroot(double a);

main()
{
	cout<<sroot(4)<<"\n";
	cout<<sroot(49L)<<"\n";
	cout<<sroot(10.11)<<"\n";

	return 0;
}

double sroot(int a)
{
	return sqrt(a);

}


double sroot(long a)
{
	return sqrt(a);

}
 

double sroot(double a)
{
	return sqrt(a);

}
 
 
