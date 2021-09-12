//GCD Algorithm
#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

int GCD(int a,int b);

int main()
{
    int a,b,n;

    while(scanf("%d %d",&a,&b)==2)
    {
        n=GCD(a,b);
        printf("%d\n",n);
    }

    return 0;
}

int GCD(int a,int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}
/*
Input & Output:
5 6
1
6 6
6
6 12
6
7 12
1
8 12
4
12 156
12
24 156
12
*/
