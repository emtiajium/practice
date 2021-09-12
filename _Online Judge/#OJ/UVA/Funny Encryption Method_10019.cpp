#include<cstdio>
using namespace std;

int d2b(int);
int h2d(int);

int t,n1,n2,remainder;
int count[2];

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n1);
        count[0]=d2b(n1);
        n2=h2d(n1);
        count[1]=d2b(n2);
        printf("%d %d\n",count[0],count[1]);
    }
    return 0;
}

int d2b(int number)
{
	int count=0;
	while(number!=0){
		remainder=number%2;
		if(remainder==1) count++;
		number/=2;
	}
return count;
}

int h2d(int number)
{
    int i=1,deci=0;
    while(number!=0){
        deci+=((number%10)*i);
        number/=10;
        i*=16;
    }
return deci;
}
