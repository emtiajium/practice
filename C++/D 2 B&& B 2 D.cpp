#include<iostream>
using namespace std;
class conversion
{
	int number;
    public:
        void d2b(int );
        void b2d(char [],int );
};

void conversion::d2b(int a)
{
	number=a;
	int i=0,j,k;
	char remainder[100],binary[100];
	while(number!=0)
	{
		remainder[i]=(number%2)+'0';
		number/=2;
		i++;
	}
	cout<<"D to B ";
	for(j=i-1,k=0;j>=0;j--,k++)
        binary[k]=remainder[j];

	binary[k]='\0';
    cout<<binary<<endl;
	b2d(binary,k);
}

void conversion::b2d(char binary[],int size)
{
	int i=1,c=0,x=size-1;
	while(x>=0)
	{
		int mod=(binary[x]-'0')*i;//2^0=1
		i*=2;
		c+=mod;
		x--;
	}
	cout<<"B to D "<<c<<endl;
}

int main()
{
	conversion c;
	int z;
	cin>>z;
	c.d2b(z);
return 0;
}
