#include<iostream>
using namespace std;
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

double  absoluteValue (double x)
         {
         if ( x < 0 )
         x = -x;
         return x;
         }
void  simple()
    {
        cin>>n1>>sym>>n2;
    if(sym=='+')
        cout<<"\n"<<add(n1,n2);
    if(sym=='-')
        cout<<"\n"<<sub(n1,n2);
    if(sym=='*')
        cout<<"\n"<<product(n1,n2);
    if(sym=='/')
        cout<<"\n"<<divide(n1,n2);
    }

void rootover()
    {
        double x;
        const double  epsilon = 0.00001;
        double        guess   = 1.0;
        cin>>x;
        while  ( absoluteValue (guess * guess - x) >= epsilon )
        guess = ( x / guess + guess ) / 2.0;
        cout<<"\n"<<guess;
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
{
    cout<<"\n                      BISMILLAHIR RAHMANIR RAHIM\n\n";
    cout<<"This Program is a program for calculator\n\n";
    cout<<"Enter choice n\n";
    cout<<"Press n";
    cout<<"[1] for Addition,Subtraction,Multiplication,Division\n      n";
    cout<<"[2] for Square\n      n";
    cout<<"[3] for cube\n      n";
    cout<<"[4] for inverse\n      n";
    cout<<"[5] for Root over\n      n";
    cout<<"[6] for combination\n      n";
    cout<<"[7] for permutation\n      n";
    cout<<"[8] for factorial\n      n";
    cout<<"[s] for Scientific Functions\n      n";
    cout<<"[E] for Exit \n\n                   choice <n> ";
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
    double cose(double);
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
        double x;
        cin>>x;
        if (x<=0)
		cout<<"MATH ERROR.";
	else
	{
		int i,j;
		double e,r,s,v,t,q;
		s=0.00;
		t=x-1;
		v=x+1;
		e=t/v;
		for (i=1;i<=25;i=i+2)
		{
			r=1;
			q=1/i;
			for (j=1;j<=i;j++)
				r*=e;
			s+=r/i;
		}
		q=s*2;
		cout<<"\nln("<<x<<")="<<q;
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
        sum=cose(x);
	cout<<"\n"<<sum;
	}
	void sine()
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
	    k=sin(k)/cose(k);
	    cout<<"\n"<<k;
	}
};
double derived1::sin(double deg)
{
    const double PI=3.14159,ACC=0.001;
	    double rad,res,term;
        int i,j,k;
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
        return res;
}
double derived1::cose(double x)
{
    double sum=0,res=1;	int j=0;
    x=x*(3.1416/180);
	for(int i=1;i<=20;i++)
	{
		if(i==1)
			sum=sum+1;
		else
		{
			if(i%2==0)
			{
				for(int k=1;k<=j;k++)
					res=res*k;
				sum=sum-x*x/res;
				res=1;
			}
			else
			{
				for(int k=1;k<=j;k++)
					res=res*k;
				sum=sum+x*x/res;
				res=1;
			}}
		j=j+2;}
		return sum;
}
class derived2 : public derived1
{
    public:
    void combination()
    {
        double n,k,a,b,i,x,p,sum,h;
        cin>>n>>k;
        x=n-k;if(x>k)p=k;else p=x;
        for(i=0,sum=1;i<p;i++,n--)
        sum=sum*n;
        for(i=p,a=1;i>0;i--,p--)
        a=a*p;
        h=sum/a;
        cout<<"\n"<<h;
    }
    void permutation()
    {
        double n,k,a,b,i,x,p,sum,h;
        cin>>n>>k;
        x=n-k;if(x>k)p=k;else p=x;
        for(i=0,sum=1;i<p;i++,n--)
        sum=sum*n;
        for(i=p,a=1;i>0;i--,p--)
        a=a*p;
        h=sum/a;
        h=h*fact(k);
        cout<<"\n"<<h;
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
    if(choice=='1')
    A.simple();
    if(choice=='2')
    A.square();
    if(choice=='3')
    A.cube();
    if(choice=='4')
    A.inverse();
    if(choice=='5')
    A.rootover();
    if(choice=='6')
    A.combination();
    if(choice=='7')
    A.permutation();
    if(choice=='8')
    A.facto();
    if(choice=='s')
    {
cout<<" Scientific Function  n\n";
cout<<" Press n";
cout<<"[1] for ln x \n       n";
cout<<"[2] for exp of x \n       n";
cout<<"[3] for Sin x \n       n";
cout<<"[4] for Cos x \n       n";
cout<<"[5] for Tan x \n\n               choice <n> ";
cin>>choice2;
if(choice2=='1')
A.ln();
if(choice2=='2')
A.expo();
if(choice2=='3')
A.sine();
if(choice2=='4')
A.cos();
if(choice2=='5')
A.tan();
    }
    if(choice=='e'|| choice=='E')
{
    cout<<"\n\n";
    cout<<"         Do u wish to continue.\n\n        Press Y for yes or Press N for no\n";
    cin>>choice_last;
    if(choice_last=='Y' || choice_last=='y')
    main();
}
}
