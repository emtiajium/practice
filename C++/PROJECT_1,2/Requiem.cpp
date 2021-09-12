//Requiem's Simple (Yet Complex!!!) Scientific Calculator
//Rabiul Hasan Ronok
//Roll : 1004046

#include <iostream>
using namespace std;

#define PI 3.141592653589793238462643383279502884197169399375105
#define EPS 0.0000001

class standard_calculator		// Contains standard calculator functions
{
public:
	void add();
	void sub();
	void mul();
	void div();
	void root();
	void mod();
	void inverse();
	void absol();
	double absol(double);
	void sqr();
	void cube();
};

void standard_calculator :: add ()
{
	double a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	cout << "The addition is : " << a+b << endl;
}

void standard_calculator :: sub()
{
	double a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	cout << "The subtraction is : " << a-b << endl;
}

void standard_calculator :: mul()
{
	double a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	cout << "The product is : " << a*b << endl;
}

void standard_calculator :: div()
{
	double a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	try
	{
		if(b==0)
			throw b;
		else
		{
			cout << "The division is : " << a/b << endl;
		}
	}
	catch (double a)
	{
		cout << "Math Error" << endl;
	}
}

void standard_calculator :: root()
{
	double a,b;
	b=1.0;
	cout << "Enter a number : ";
	cin >> a;
	try
	{
		if(a<0)
			throw a;
		else
		{
			while(absol(b*b-a) >= EPS)
			{
				b=((a/b)+b)/2.0;
			}
			cout << "The square root is " << b << endl;
		}
	}
	catch(double a)
	{
		cout << "Math Error" << endl;
	}	
}

void standard_calculator :: mod()
{
	int a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	cout << "The modulus is : " << a%b << endl;
}

void standard_calculator :: inverse()
{
	double a;
	cout << "Enter a number : ";
	cin >> a;
	cout << "The inverse is : " << 1/a << endl;
}

void standard_calculator :: absol()
{
	double a;
	cout << "Enter a number : ";
	cin >> a;
	cout << "The absolute value is " << absol(a) << endl;
}

double standard_calculator :: absol (double a)
{
	if(a<0)
		return -a;
	else return a;
}

void standard_calculator :: sqr()
{
	double a;
	cout << "Enter a number : ";
	cin >> a;
	cout << "The square is " << a*a << endl;
}

void standard_calculator :: cube()
{
	double a;
	cout << "Enter a number : ";
	cin >> a;
	cout << "The cube is " << a*a*a << endl;
}

class scientific_calculator : public standard_calculator	// Contains scientific calculator functions
{
public:
	scientific_calculator();
	~scientific_calculator();
	void sin();
	double sin(double);
	void cos();
	double cos(double);
	void tan();
	void ln();
	double ln(double);
	void log();
	void exp();
	void fact();
	int fact(int);
	void perm();
	void comb();
};

scientific_calculator :: scientific_calculator()
{
	int a,b;
	do
	{
		cout << "Welcome To Requiem's Scientific Calculator" << endl;
		cout << "Choose an option from the menu and press enter" << endl << endl;
		cout << "1. Addition" << endl;
		cout << "2. Subtraction" << endl;
		cout << "3. Multiplication" << endl;
		cout << "4. Division" << endl;
		cout << "5. Square Root" << endl;
		cout << "6. Modulus" << endl;
		cout << "7. Inversion" << endl;
		cout << "8. Absolute Value" << endl;
		cout << "9. Square" << endl;
		cout << "10. Cube" << endl;
		cout << "11. Sin" << endl;
		cout << "12. Cos" << endl;
		cout << "13. Tan" << endl;
		cout << "14. ln" << endl;
		cout << "15. log" << endl;
		cout << "16. e" << endl;
		cout << "17. Factorial" << endl;
		cout << "18. Permutation" << endl;
		cout << "19. Combination" << endl << endl;
		cout << "Enter 0 to exit" << endl;
		cin >> a;
		cout << endl;
		if(a==0)
			break;
		else if(a==1)
			add();
		else if(a==2)
			sub();
		else if(a==3)
			mul();
		else if(a==4)
			div();
		else if(a==5)
			root();
		else if(a==6)
			mod();
		else if(a==7)
			inverse();
		else if(a==8)
			absol();
		else if(a==9)
			sqr();
		else if(a==10)
			cube();
		else if(a==11)
			sin();
		else if(a==12)
			cos();
		else if(a==13)
			tan();
		else if(a==14)
			ln();
		else if(a==15)
			log();
		else if(a==16)
			exp();
		else if(a==17)
			fact();
		else if(a==18)
			perm();
		else if(a==19)
			comb();
		cout << endl << "Do you wish to use again ? " << endl;
		cout << "Enter 1 to continue or 0 to to exit" << endl;
		cin >>b;
		if(b==0)
			break;
	}
	while(1);
}

scientific_calculator :: ~scientific_calculator()
{
	cout << endl << endl << "Thank you for using my calculator" <<endl << endl << endl;
	cout << "\t\t\t^__^" << endl << endl << endl;
}

void scientific_calculator :: sin()
{
	double a;
	cout << "Enter an angle : ";
	cin >> a;
	cout << "Sin " << a << " = " << sin(a) << endl;
}

double scientific_calculator :: sin(double a)
{
	double b,c,d;
	int i;
	if((int)a%180==0)
		return 0;
	b=(PI*a)/180;
	c=d=b;
	i=2;
	while(1)
	{
		d*=-((b/(double)i)*(b/(double)(i+1)));
		if(absol(d)<EPS)
			break;
		c+=d;
		i+=2;
	}
	return c;
}

void scientific_calculator :: cos()
{
	double a;
	cout << "Enter an angle : ";
	cin >> a;
	cout << "Cos " << a << " = " << cos(a) << endl;
}

double scientific_calculator :: cos(double a)
{
	double b,c,d;
	int i;
	if((int)(a-90)%180==0)
		return 0;
	b=(PI*a)/180;
	c=d=1;
	i=1;
	while(1)
	{
		d*=-((b/(double)i)*(b/(double)(i+1)));
		if(absol(d)<EPS)
			break;
		c+=d;
		i+=2;
	}
	return c;
}

void scientific_calculator :: tan()
{
	double a;
	cout << "Enter an angle : ";
	cin >> a;
	try
	{
		if((int)(a-90)%180==0)
			throw a;
		else
			cout << "Tan " << a << " = " << sin(a)/cos(a) << endl;
	}
	catch(double a)
	{
		cout << "MATH ERROR" << endl;
	}
}

void scientific_calculator :: ln()
{
	double a;
	cout << "Enter a number : ";
	cin >> a;
	try
	{
		if(a<=0)
			throw(a);
		else
			cout << "ln " << a << " = " << ln(a) << endl;
	}
	catch (double a)
	{
		cout << "MATH ERROR" << endl;
	}
}

double scientific_calculator :: ln(double a)
{
	int i;
	double b,c,d,e;
	c=(a-1)/(a+1);
	b=d=c;
	i=3;
	while(1)
	{
		d*=c*c;
		e=d/(double)i;
		if(d<EPS)
			break;
		b+=e;
		i+=2;
	}
	b*=2;
	return b;
}

void scientific_calculator :: log()
{
	double a;
	cout << "Enter a number : ";
	cin >> a;
	try
	{
		if(a<=0)
			throw a;
		else
		{
			cout << "log " << a << " = " << ln(a)/ln(10) << endl;
		}
	}
	catch(double a)
	{
		cout << "Math Error" << endl;
	}
}

void scientific_calculator :: exp()
{
	double a,b,c;
	int i;
	cout << "Enter a number : ";
	cin >> a;
	b=c=1;
	i=1;
	while(1)
	{
		c*=a/(double)i;
		if(c<EPS)
			break;
		b+=c;
		i++;
	}
	cout<< "Exp " << a << " = " << b << endl;
}

void scientific_calculator :: fact()
{
	int a;
	cout << "Enter a number : ";
	cin >> a;
	cout << a << "! = " << fact(a) << endl;
}

int scientific_calculator :: fact(int a)
{
	if(a==0  || a==1)
		return 1;
	else return a*fact(a-1);
}

void scientific_calculator :: perm()
{
	int a,b;
	cout << "Enter two numbers : ";
	cin >> a >> b;
	try
	{
		if(a<b)
			throw b;
		else
			cout << a << "P" << b << " =  " << fact(a)/fact(b);

	}
	catch(int a)
	{
		cout << "MATH ERROR" << endl;
	}
}

void scientific_calculator :: comb()
{
	int a,b;
	cout << "Enter two numbers  : ";
	cin >> a >> b;
	try
	{
		if(a<b)
			throw b;
		else
			cout << a << "C" << b << " = " << fact(a)/(fact(b)*fact(a-b)) << endl;
	}
	catch(int a)
	{
		cout << "MATH ERROR" << endl;
	}
}

int main()
{
	scientific_calculator C;
	return 0;
}
