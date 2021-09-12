#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

char num[100];
unsigned long i,j,len,sum;

int main()
{
    //freopen("input.txt","r",stdin);
    while(gets(num))
    {
        if(num[0]=='0' && num[1]=='\0') break;
        len=strlen(num);
        i=0;
        sum=0;
        while(len!=0){
            if(num[i]!=48) sum+= ( (num[i]-48) * (pow(2,len)-1) );
            len--;
            i++;
        }
        printf("%lu\n",sum);
    }
    return 0;
}
