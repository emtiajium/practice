#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<map>
#include<set>
using namespace std;

//const double PI=3.14159265358979323846264338327950288419716939937511;
char mirror(char);

string str,temp;
int i;
bool pal,mirr;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    while(cin>>str){
        cout<<str;
        temp=str;
        reverse(temp.begin(),temp.end());
        if(str==temp) pal=true;
        temp.clear();
        for(i=0;str[i];i++){
            temp+=mirror(str[i]);
        }
        reverse(temp.begin(),temp.end());
        if(temp==str) mirr=true;
        if(pal==false && mirr==false) puts(" -- is not a palindrome.");
        if(pal==true && mirr==false) puts(" -- is a regular palindrome.");
        if(pal==false && mirr==true) puts(" -- is a mirrored string.");
        if(pal==true && mirr==true) puts(" -- is a mirrored palindrome.");
        puts("");
        pal=mirr=false;
        str.clear();
        temp.clear();
    }
    return 0;
}

char mirror(char ch){
    char s;
    if(ch=='A') s='A';
    else if(ch=='E') s='3';
    else if(ch=='H') s='H';
    else if(ch=='I') s='I';
    else if(ch=='J') s='L';
    else if(ch=='L') s='J';
    else if(ch=='M') s='M';
    else if(ch=='O') s='O';
    else if(ch=='S') s='2';
    else if(ch=='T') s='T';
    else if(ch=='U') s='U';
    else if(ch=='V') s='V';
    else if(ch=='W') s='W';
    else if(ch=='X') s='X';
    else if(ch=='Y') s='Y';
    else if(ch=='Z') s='5';
    else if(ch=='1') s='1';
    else if(ch=='2') s='S';
    else if(ch=='3') s='E';
    else if(ch=='5') s='Z';
    else if(ch=='8') s='8';
    else s='?'; // got WA for it
    return s;
}
