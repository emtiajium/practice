#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

string str;
int cas;

int main()
{
    //freopen("input.txt","r",stdin);
    cas=1;
    while(cin>>str)
    {
        if(str=="#") break;
        printf("Case %d: ",cas);
        if(str=="HELLO") puts("ENGLISH");
        else if(str=="HOLA") puts("SPANISH");
        else if(str=="HALLO") puts("GERMAN");
        else if(str=="BONJOUR") puts("FRENCH");
        else if(str=="CIAO") puts("ITALIAN");
        else if(str=="ZDRAVSTVUJTE") puts("RUSSIAN");
        else puts("UNKNOWN");
        cas++;
    }
    return 0;
}
