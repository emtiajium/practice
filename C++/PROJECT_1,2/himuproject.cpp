#include<iostream>
using namespace std;
//#include<conio.h>
#define PI 3.14159265358979323846264
class base
{
    public:
    base();
    float n1,n2;
    char sym;
    float add(float,float);
float sub(float,float);
float product(float,float);
float divide(float,float);
double absoluteValue (double x)
	 {
	 if ( x < 0 )
	 x = -x;
	 return x;
	 }
void  simple()
    {
//	clrscr();
	cin>>n1>>sym>>n2;
    if(sym=='+')
	cout<<"\n"<<add(n1,n2);
    if(sym=='-')
	cout<<"\n"<<sub(n1,n2);
    if(sym=='*')
	cout<<"\n"<<product(n1,n2);
    if(sym=='/')
    {
        if(n2==0)
        cout<<"MATH ERROR";
        else
	cout<<"\n"<<divide(n1,n2);
    }
    }

void rootover()
    {
	double x;
	const double  accuracy = 0.00001;
	double        img_n   = 1.0;
	cin>>x;

	if(x<0)
	cout<<"MATH ERROR";
	else{
	while  ( absoluteValue (img_n * img_n - x) >= accuracy )
	img_n = ( x / img_n + img_n ) / 2.0;
	cout<<"\n"<<img_n;
    }
    }

void square()
    {
	int squ;
	cin>>squ;
	cout<<"\n"<<squ*squ;
    }
void cube()
    {
	int cub;
	cin>>cub;
	cout<<"\n"<<cub*cub*cub;
    }
void inverse()
    {
	double inv;
	cin>>inv;
	cout<<"\n"<<(1/inv);
    }
};
base::base()
{               "CHITTAGONG UNIVERSITY OF ENGINEERING & TECHNOLOGY\n\n";
    cout<<"                     A PROJECT ON CALCULATOR\n\n";
    cout<<"Enter choice: \n";
    cout<<"Press Corresponding number to execute : \n";
    cout<<"Addition,Subtraction,Multiplication,Division:1\n";
    cout<<"Square : 2\n";
    cout<<"Cube : 3\n";
    cout<<"Inverse : 4\n";
    cout<<"Root over :5\n";
    cout<<"Combination : 6\n";
    cout<<"Permutation : 7\n";
    cout<<"Factorial : 8\n";
    cout<<"Scientific Functions : 9\n";
    cout<<"Absolute Value : A\n";
    cout<<"Exit : 0 \n                   choice : ";
}
float base:: add(float m1,float m2)
{
    return(m1+m2);
}
float base:: sub(float m1,float m2)
{
    return(m1-m2);
}

float base:: product(float m1,float m2)
{
    return(m1*m2);
}

float base:: divide(float m1,float m2)
{
    return(m1/m2);
}
class derived1 : public base
{
    public:
    double sin(double);
    double cos(double);
void expo()
    {
	double e,k,h,sum,g,t_sum,p;
	cin>>e;p=e;
	for(k=1,h=1,sum=0;;k++,h=p){
	    e=e*h;
	    g=fact(k);
		t_sum=e/g;
	if(t_sum<=0.001) {
		sum=t_sum+sum;
		cout<<sum+1;
		break;
	}
	else sum=t_sum+sum;
    }
    }

    void ln()
    {
	double x,c,b,d,e;
	int i;
	cin>>x;
		try
	{   
			if(x<=0)
	    throw(x);
              else
	{
	c=(x-1)/(x+1);
    b=d=c;
    i=3;
    while(1)
    {
      d*=(c*c);
      e=d/(double)i;
      if(d<0.000001)
	break;
      b+=e;
      i+=2;
    }
	b=b*2;
	cout<<b;
	}
		}
		catch(double x)
		{
           cout<<"MATH ERROR";		
		}
	
    }
    double fact(double i)
    {
	double factorial,j;
	for( j=1.0,factorial=1.0;j<=i;j++)
		factorial=factorial*j;
	return factorial;
    }
void cos()
    {
	double x,sum;
	cin>>x;
	sum=cos(x);
	cout<<"\n"<<sum;
	}
	void sin()
	{
	    double deg,res;
	cin>>deg;
	res=sin(deg);
	cout<<"\n"<<res;
	}
	void tan()
	{
	    double k;
	    cin>>k;
		if(((int)k-90)%180==0)
			cout<<"MATH ERROR";
		else
		{
	      k=sin(k)/cos(k);
	      cout<<"\n"<<k;
		}
	}
};
double derived1::sin(double deg)
{
    const double ACC=0.000001;
	    double rad,res,term;
	int i,j,k;
	if((int)deg%180==0)
	res=0;
	else
	{
    rad=(PI*deg)/180;
	res=rad;
	term=rad;
	i=2;
	while(1)
	{
	if(term<0)
	{
	if(-term<ACC)break;
	}
	else
	{
	if(term<ACC)break;
	}
	term*=-((rad/i)*(rad/(i+1)));
	res+=term;
	i+=2;}
	}
	return res;
}
double derived1::cos(double a)
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
		if(absoluteValue(d)<0.000001)
			break;
		c+=d;
		i+=2;
	}
	return c;
}
class derived2 : public derived1
{
    public:
    void AV(void)
     {
      double m;
      cin>>m;
      if(m<0)
       m=-m;
      else
       m=m;
    cout<<"\n"<<m;
   }
    void combination()
    {
        char fhgj;
	double n,k,a,b,i,x,p,sum,h;
	cin>>n>>fhgj>>k;
	if(n>=k)
	{
	x=n-k;if(x>k)p=k;else p=x;
	for(i=0,sum=1;i<p;i++,n--)
	sum=sum*n;
	for(i=p,a=1;i>0;i--,p--)
	a=a*p;
	h=sum/a;
	cout<<"\n"<<h;
    }
     else
       cout<<"MATH ERROR";
   }
    void permutation()
    {
	double n,k,a,b,i,x,p,sum,h;
	char fg;
	cin>>n>>fg>>k;
	if(n>=k)
	{
	x=n-k;if(x>k)p=k;else p=x;
	for(i=0,sum=1;i<p;i++,n--)
	sum=sum*n;
	for(i=p,a=1;i>0;i--,p--)
	a=a*p;
	h=sum/a;
	h=h*fact(k);
	cout<<"\n"<<h;
    }
     else
       cout<<"MATH ERROR";
    }
    void facto()
    {
	double f;
	cin>>f;
	cout<<"\n"<<fact(f);
    }
};
int main()
{
    char choice,choice2,choice_last;
derived2 A;
    cin>>choice;
    cout<<"\n\n";
    if(choice=='A')
    A.AV();
    else if(choice=='1')
    A.simple();
    else if(choice=='2')
    A.square();
    else if(choice=='3')
    A.cube();
    else if(choice=='4')
    A.inverse();
    else if(choice=='5')
    A.rootover();
    else if(choice=='6')
    A.combination();
    else if(choice=='7')
    A.permutation();
    else if(choice=='8')
    A.facto();
    else if(choice=='9')
    {
cout<<" Scientific Calculation : \n";
cout<<" Press Corresponding number to execute : ";
cout<<"ln x : 1\n";
cout<<"exp of x : 2\n";
cout<<"sin x : 3\n";
cout<<"cos x : 4\n";
cout<<"tan x : 5\n\n               choice : ";
cin>>choice2;
if(choice2=='1')
A.ln();
if(choice2=='2')
A.expo();
if(choice2=='3')
A.sin();
if(choice2=='4')
A.cos();
if(choice2=='5')
A.tan();
    }
    cout<<"\n\n";
    cout<<"         Do u wish to continue.\n\n        Press Y for yes or Press N for no\n";
    cin>>choice_last;
    if(choice_last=='Y' || choice_last=='y')
    main();
return 0;
}
