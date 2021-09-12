#include<iostream>
using namespace std;
void main()
{
int x,i=sizeof(int)*8-1,j;
cin>>x;
while(i>=0)
{
j=x&(1<<i);
cout<<(j==0?0:1);
i--;

}
		

}