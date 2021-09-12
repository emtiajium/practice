// EMTIAJ HASAN 1004050
// http://ideone.com/YTw5H
#include<iostream>
#include<cstring>
using namespace std;

const double PI=3.14159265358979323846264338327950288419716939937510;
const int SIZE=120;
char s1[SIZE],s2[SIZE],tmp[SIZE],res[SIZE],final[SIZE],summa[SIZE];
char str[50][SIZE];

class base
{
    public:
    base();
    void addition(void);
    void subtraction(void);
    void multiplication(void);
    void division(void);
    double abs(double );
    void sqrt(void);
    double sqrt(double );
    void pow(void);
    int square(int);
    int pow(int,int);
    void inverse(void);
    void quad_eqn(void);
    void l_eqn_2(void);
    void l_eqn_3(void);
};
base::base()
{
    cout<<"\n    HELLO, THIS IS EMTIAJ HASAN. I HAVE MADE A SIMPLE CALCULATOR USING C++.\n\n";
    cout<<"\t1. ADDITION";
    cout<<"\t2. SUBTRACTION";
    cout<<"\t3. MULTIPLICATION\n\n";
    cout<<"\t4. DIVISION";
    cout<<"\t5. FACTORIAL";
    cout<<"\t6. COMBINATION\n\n";
    cout<<"\t7. PERMUTATION";
    cout<<"\t8. GCD LCM";
    cout<<"\t9. X^n\n\n";
    cout<<"\t10.INVERSE";
    cout<<"\t11.SQUARE ROOT\n\n";
    cout<<"\t12.SOLVING QUADRATIC EQUATION\n\n";
    cout<<"\t13.SOLVING A SET OF TWO LINEAR EQUATION\n\n";
    cout<<"\t14.SOLVING A SET OF THREE LINEAR EQUATION\n\n";
    cout<<"\t15.NATURAL LOGARITHM";
    cout<<"\t16.10 BASE LOGARITHM";
    cout<<"\t17.EXPONENTIAL\n\n";
    cout<<"\t18.sin(x)";
    cout<<"\t19.cos(x)";
    cout<<"\t20.tan(x)";
    cout<<"\t21.cot(x)\n\n";
    cout<<"\t0.EXIT\n\n";
    cout<<"\n\tENTER CHOICE ";
}
//addition
void base:: addition(void)
{
    int l1,l2,i,j,temp,m,n,sum,hold;
    int k,len;

    cout<<"HOW MANY NUMBERS YOU WOULD LIKE TO INPUT? ";
    cin>>len;
    cout<<"INPUT NUMBERS (PRESS ENTER AFTER EACH NUMBER)\n";
    for(k=0;k<len;k++)
        cin>>str[k];

    strcpy(summa,"0");
    for(k=0;k<len;k++){
        strcpy(s1,str[k]);
        strcpy(s2,summa);
        l1=strlen(s1);
        l2=strlen(s2);
        if(l2>l1){
            temp=l1;
            l1=l2;
            l2=temp;
            strcpy(tmp,s1);
            strcpy(s1,s2);
            strcpy(s2,tmp);
        }
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)sum=(s1[m]-'0')+(s2[n]-'0')+hold;
            else sum=(s1[m]-'0')+hold;
            res[i]=sum%10+'0';
            hold=sum/10;
        }
        if(hold) res[i++]=hold+'0';
        for(j=i-1,i=0;j>=0;j--,i++)
            final[i]=res[j];

        final[i]='\0';
        strcpy(summa,final);
    }
    cout<<"THE ADDITION IS "<<final<<endl;
}
//subtraction
void base:: subtraction(void)
{
    int i,j,l1,l2,m,n,temp,hold,diff;
    char sign='0';
    cout<<"ENTER TWO NUMBER FOR DOING SUBTRACTION\n";
    cout<<"PRESS ENTER AFTER EACH NUMBER\n";
    cin>>s1>>s2;
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1<l2){
        temp=l1;
        l1=l2;
        l2=temp;
        strcpy(tmp,s1);
        strcpy(s1,s2);
        strcpy(s2,tmp);
        sign='1';
    }
    if(l1==l2){
        if(strcmp(s1,s2)<0){
            strcpy(tmp,s1);
            strcpy(s1,s2);
            strcpy(s2,tmp);
            sign='1';
        }
    }
    m=l1-1;
    n=l2-1;
    for(i=0,hold=0;i<l1;i++,m--,n--){
        if(n>=0)diff=(s1[m]-'0')-(s2[n]-'0')-hold;
        else diff=(s1[m]-'0')-hold;
        if(diff<0){
            hold=1;
            res[i]=diff+'0'+10;
        }
        else{
            res[i]=diff+'0';
            hold=0;
        }
    }
    for(i=l1-1;i>0;i--){
        if(res[i]!='0') break;
    }
    res[i+1]='\0';
    if(sign=='1') cout<<"THE SUBTRACTION IS -";
    else if(sign=='0')cout<<"THE SUBTRACTION IS ";
    for(j=i,i=0;j>=0;j--,i++)
        cout<<res[j];

    cout<<endl;
}
//multiplication
void base:: multiplication(void)
{
    int a,b,sum;
    cout<<"ENTER TWO NUMBERS FOR DOING MULTIPLICATION\n";
    cin>>a>>b;
    if(a!=0&&b!=0){
        if(a%2==0)sum=0;
        else sum=b;
        while(a!=1){
            a/=2;
            b=b*2;
            if(a%2!=0) sum+=b;
        }
        cout<<"THE PRODUCT IS "<<sum<<endl;
    }
    else cout<<"THE PRODUCT IS 0\n";
}
//division
void base:: division(void)
{
    int divisor,mod,i,j,k,q,emti;
    cout<<"ENTER TWO NUMBERS FOR DOING DIVISION\n";
    cout<<"PRESS ENTER AFTER EACH NUMBER\n";
    cin>>s1>>divisor;
    if((s1[0]=='0'&&s1[1]=='\0')&&divisor==0) cout<<"INDETERMINATE\n";
    else if(divisor==0) cout<<"UNDEFINED\n";
    else{
        for(i=0,j=0,k=0;s1[i];i++){
            emti=(s1[i]-'0')+k;
            q=emti/divisor;
            mod=emti%divisor;
            k=mod*10;
            if(q) final[j++]=q+'0';
        }
        final[j]='\0';
        if(final[0]=='\0') cout<<"THE QUOTIENT IS 0 MOD IS "<<mod<<endl;
        else cout<<"THE QUOTIENT IS "<<final<<", MOD IS "<<mod<<endl;
    }
}
//abs()
double base::abs(double x)
{
    if(x<0) x=-x;
    return x;
}
void base::sqrt(void)
{
    double num;
    cout<<"ENTER A NUMBER(REMEMBER SQUAREROOT OF A NEGETIVE NUMBER IS IMAGINARY)\n";
    cin>>num;
    cout<<"SQRT("<<num<<") = "<<sqrt(num)<<endl;
}
//sqrt
double base::sqrt(double num)
{
    double guess=1.0;
    const double  acc = 0.00001;
    while(abs(guess*guess-num)>=acc)
        guess=(num/guess+guess)/2.0;

    return guess;
}
void base::pow(void)
{
    int bas,power;
    cout<<"ENTER BASE & POWER RESPECTIVELY ";
    cin>>bas>>power;
    cout<<bas<<"^"<<power<<" = "<<pow(bas,power)<<endl;
}
int base::square(int n)
{
    return n*n;
}
//x^n
int base::pow(int base,int power)
{
    if(power==0) return 1;
    else if(power%2==0) return square(pow(base,power/2));
    else return base*(pow(base,power-1));
}
//a^-1
void base::inverse(void)
{
    double inv;
    cout<<"ENTER A NUMBER TO INVERSE IT ";
    cin>>inv;
    cout<<"1/"<<inv<<" = "<<(1/inv)<<endl;;
}
//quad
void base::quad_eqn(void)
{
    int a,b,c;
    double dis,r,x1,x2;
    cout<<"QUADRATIC EQUATION IS ax^2+bx+c=0\n";
    cout<<"ENTER CO-EFFICIENT OF of x^2, x & CONSTANT.\n";
    cin>>a>>b>>c;
    dis=b*b-4*a*c;
    if(dis<0) cout<<"SINCE DISCRIMINANT OF THIS EQUATION IS NEGETIVE, THE ROOTS ARE IMAGINARY.\n";
    else
    {
        r=sqrt(dis);
        x1=(-b+r)/(2*a);
        x2=(-b-r)/(2*a);
        cout<<"X1 = "<<x1<<endl<<"X2 = "<<x2;
    }
}
// solve x,y
void base::l_eqn_2(void)
{
    int a1,a2,b1,b2,c1,c2,det,dx,dy;
    double x,y;
    cout<<"A SET OF TWO LINEAR EQUATION IS "<<endl;
    cout<<"\ta1x + b1y = c1\n\ta2x + b2y = c2\n";
    cout<<"ENTER CO-EFFICIENT OF x, y & CONSTANT.\n";
    cin>>a1>>b1>>c1>>a2>>b2>>c2;
    det=a1*b2-a2*b1;
    if(det==0) cout<<"ERROR\n";
    else{
        dx=(c1*b2-b1*c2);
        dy=(c2*a1-a2*c1);
        x=(double)dx/(double)det;
        y=(double)dy/(double)det;
        cout<<"\nX= "<<dx<<"/"<<det<<" = "<<x<<endl;
        cout<<"\nY= "<<dy<<"/"<<det<<" = "<<y<<endl;
    }
}
//solve x,y,z
void base::l_eqn_3(void)
{
    int a1,a2,a3,b1,b2,b3,c1,c2,c3,d1,d2,d3,det,dx,dy,dz;
    double x,y,z;
    cout<<"A SET OF THREE LINEAR EQUATION IS "<<endl;
    cout<<"\ta1x + b1y + c1z = d1\n\ta2x + b2y + c2z = d2\n\ta3x + b3y + c3z = d3\n";
    cout<<"ENTER CO-EFFICIENT OF x, y, z & CONSTANT.\n";
    cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2>>a3>>b3>>c3>>d3;
    det= a1*(b2*c3-c2*b3)-b1*(a2*c3-c2*a3)+c1*(a2*b3-a3*b2);
    if(det==0) cout<<"ERROR\n";
    else{
        dx=(d1*(b2*c3-c2*b3)-b1*(d2*c3-c2*d3)+c1*(d2*b3-d3*b2));
        dy=(a1*(d2*c3-c2*d3)-d1*(a2*c3-c2*a3)+c1*(a2*d3-a3*d2));
        dz=(a1*(b2*d3-d2*b3)-b1*(a2*d3-d2*a3)+d1*(a2*b3-a3*b2));
        x=(double)dx/(double)det;
        y=(double)dy/(double)det;
        z=(double)dz/(double)det;
        cout<<"\nX= "<<dx<<"/"<<det<<" = "<<x<<endl;
        cout<<"\nX= "<<dx<<"/"<<det<<" = "<<y<<endl;
        cout<<"\nX= "<<dx<<"/"<<det<<" = "<<z<<endl;
    }
}

//derived 1
class derived1 : public base
{
    public:
    void ln(void);
    double ln(double);
    void log10(void);
    void exponential(void);
    double factorial(int);
    void sine(void);
    void cosine(void);
    void tangent(void);
    void cotangent(void);
    double sine(double);
    double cosine(double);
};
//e^x
void derived1::exponential(void)
{
    double i,j,e,sum,g,t_sum,t_e;
    cout<<"ENTER A NUMBER ";
    cin>>e;
    t_e=e;
    for(i=1,j=1,sum=0;;i++,j=t_e){
        e=e*j;
        g=factorial(i);
        t_sum=e/g;
        if(t_sum<=0.001){
            sum=t_sum+sum;
            cout<<"e^"<<t_e<<" = "<<sum+1<<endl;;
            break;
        }
        else sum=t_sum+sum;
    }
}
void derived1::ln(void)
{
    double x;
    cout<<"ENTER A NUMBER ";
    cin>>x;
    if (x<=0){
        if(x==-1) cout<<"ln(-1) = i*PI\n";
        else cout<<"MATH ERROR.\n";
    }
    else cout<<"ln("<<x<<") = "<<ln(x)<<endl;
}
//ln(x)
double derived1::ln(double x)
{
    int i,j;
    double e,r,sum,deno,neu,f_sum;
    sum=0.0;
    neu=x-1;
    deno=x+1;
    e=neu/deno;
    for (i=1;i<=25;i=i+2){
        r=1;
        f_sum=1/i;
        for(j=1;j<=i;j++)
            r*=e;

        sum+=r/i;
    }
    f_sum=sum*2;
	return f_sum;
}
//log10(x)
void derived1::log10(void)
{
    double n;
    cout<<"ENTER NUMBER ";
    cin>>n;
    if(n<0) cout<<"MATH ERROR\n";
    else cout<<"log10("<<n<<") = "<<ln(n)/2.3025850929940<<endl;
}
//factorial
double derived1::factorial(int n)
{
    double fact=1;
    for(int i=1;i<=n;i++)
        fact*=(double)i;

    return fact;
}
void derived1::cosine(void)
{
    double theta,t_theta,res;
    cout<<"ENTER A NUMBER ";
    cin>>theta;
    t_theta=(int)theta;
    if(t_theta<0) theta=(-1)*theta;
    res=cosine(theta);
    if(t_theta<0)cout<<"\ncos(-"<<theta<<") = "<<res<<endl;
    else cout<<"\ncos("<<theta<<") = "<<res<<endl;
}
void derived1::sine(void)
{
    double deg,t_d,res;
    cout<<"ENTER A NUMBER ";
    cin>>deg;
    t_d=(int)deg;
    if(t_d<0) deg=(-1)*deg;
    res=sine(deg);
    if(t_d<0)cout<<"sin(-"<<deg<<") = -"<<res<<endl;
    else cout<<"sin("<<deg<<") = "<<res<<endl;}
void derived1::tangent(void)
{
    double k,l,m;
    cout<<"ENTER A NUMBER\n";
    cin>>k;
    if((int)k==90) cout<<"UNDEFINED\n";
    else{
        l=sine(k);
        m=cosine(k);
        cout<<"tan("<<k<<") = "<<l/m<<endl;
    }
}
void derived1::cotangent(void)
{
    double k,l,m;
    cout<<"ENTER A NUMBER\n";
    cin>>k;
    if((int)k==0) cout<<"UNDEFINED\n";
    else{
    l=sine(k);
    m=cosine(k);
    cout<<"cot("<<k<<") = "<<m/l<<endl;
    }
}
double derived1::sine(double deg)
{
    const double ACC=0.001;
    double res,rad,term;
    int i,j,k;
    rad=(PI*deg)/180;
    res=rad;
    term=rad;
    i=2;
    while(1){
        if(term<0){
            if(-term<ACC)break;
        }
        else{
            if(term<ACC)break;
        }
        term*=-((rad/i)*(rad/(i+1)));
        res+=term;
        i+=2;
    }
    return res;
}
double derived1::cosine(double deg)
{
    double sum=0,res=1,rad;
    int j=0;
    rad=deg*(PI/180);
	for(int i=1;i<=20;i++){
		if(i==1)sum=sum+1;
		else{
			if(i%2==0){
				for(int k=1;k<=j;k++)
					res=res*k;

				sum=sum-rad*rad/res;
				res=1;
			}
			else{
				for(int k=1;k<=j;k++)
					res=res*k;

				sum=sum+rad*rad/res;
				res=1;
			}
        }
		j=j+2;
    }
    return sum;
}
//derived2
class derived2 : public derived1
{
    public:
    void facto(void);
    void combination(void);
    void permutation(void);
    int combination(int,int);
    int permutation(int,int);
    void g_l(void);
    int GCD(int,int);
    int LCM(int,int);
};
void derived2::combination(void)
{
    int n,r;
    cout<<"ENTER TWO NUMBER FOR DOING COMBINATION"<<endl;
    cin>>n>>r;
    if(r>n) cout<<"MATH ERROR\n";
    else cout<<n<<"C"<<r<<" = "<<combination(n,r)<<endl;
}

void derived2::permutation(void)
{
    int n,r;
    cout<<"ENTER TWO NUMBER FOR DOING PERMUTATION"<<endl;
    cin>>n>>r;
    if(r>n) cout<<"MATH ERROR\n";
    else cout<<n<<"P"<<r<<" = "<<permutation(n,r)<<endl;
}
//combination
int derived2::combination(int n,int r)
{
    int j;
    int c;
    if(r>n/2) r=n-r;
    for(j=0,c=1;j<r;j++){
        c=c*(n-j);
        c=c/(1+j);
    }
    return c;
}
//permutation
int derived2::permutation(int n,int r)
{
    int p;
    p=combination(n,r)*(int)factorial(r);
    return p;
}
void derived2::facto(void)
{
    int n;
    cout<<"ENTER A NUMBER FOR DOING FACTORIAL ";
    cin>>n;
    if(n<0&&n%2==0) cout<<"FACTORIAL OF NEGETIVE EVEN NUMBER IS -INFINITY"<<endl;
    else if(n<0&&n%2!=0) cout<<"FACTORIAL OF NEGETIVE ODD NUMBER IS +INFINITY"<<endl;
    else cout<<n<<"! = "<<factorial(n)<<endl;
}
void derived2::g_l(void)
{
    int i,len,gcd,lcm,data[100];
    cout<<"HOW MANY NUMBERS ";
    cin>>len;
    for(i=0;i<len;i++)
        cin>>data[i];

    gcd = GCD( data[0], data[1] ) ;
    lcm=(data[0]*data[1])/gcd;
    for( i = 2 ; i < len ; i++ ){
        gcd = GCD( gcd, data[i] ) ;
        lcm = LCM( lcm, data[i]);
    }
    cout<<"GCD OF THOSE INPUT IS "<<gcd<<endl;
    cout<<"LCM OF THOSE INPUT IS "<<lcm<<endl;

}
//gcd
int derived2::GCD(int first,int second)
{
    int mod ;
    while( second != 0 ){
        mod = first % second ;
        first=second;
        second=mod;
    }
    return first;
}
//lcm
int derived2::LCM( int i, int j )
{
    return i*j/GCD(i, j) ;
}
//main()
int main()
{
    derived2 A;
    int choice;
    char ch;
    while(cin>>choice&&choice){
        switch(choice){
            case 1:
                A.addition();
                break;
            case 2:
                A.subtraction();
                break;
            case 3:
                A.multiplication();
                break;
            case 4:
                A.division();
                break;
            case 5:
                A.facto();
                break;
            case 6:
                A.combination();
                break;
            case 7:
                A.permutation();
                break;
            case 8:
                A.g_l();
                break;
            case 9:
                A.pow();
                break;
            case 10:
                A.inverse();
                break;
            case 11:
                A.sqrt();
                break;
            case 12:
                A.quad_eqn();
                break;
            case 13:
                A.l_eqn_2();
                break;
            case 14:
                A.l_eqn_3();
                break;
            case 15:
                A.ln();
                break;
            case 16:
                A.log10();
                break;
            case 17:
                A.exponential();
                break;
            case 18:
                A.sine();
                break;
            case 19:
                A.cosine();
                break;
            case 20:
                A.tangent();
                break;
            case 21:
                A.cotangent();
                break;
        }
        cout<<"\nPRESS y IF YOU WOULD LIKE TO CONTINUE, ELSE n\n";
        cin>>ch;
        if(ch!='n') derived2 A;
        else break;
    }
    cout<<"\n\n\t\tTHANK YOU FOR USING MY CALCULATOR\n\n";
    return 0;
}
