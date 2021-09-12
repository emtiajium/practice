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
stringstream sstr;
string party,str;
map<string,int> MP;
char temp[5];
int test,cases,p,g,s,t,val,sign,vote,sum;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&p,&g)==2){
        while(p--){
            cin>>party;
            scanf("%d.%d",&s,&t);
            vote=s*10+t;
            getchar();
            MP[party]=vote;
        }
        while(g--){
            getline(cin,str);
            sstr<<str;
            sum=0;
            while(sstr>>party){
                if(MP.find(party)!=MP.end()){
                    sum+=MP[party];
                }
                else{
                    if(party=="<") sign=1;
                    else if(party==">") sign=2;
                    else if(party=="<=") sign=3;
                    else if(party==">=") sign=4;
                    else if(party=="=") sign=5;
                    else{
                        strcpy(temp,party.c_str());
                        val=atoi(temp);
                    }
                }
            }
            sstr.clear();
            val=val*10;
            printf("Guess #%d was ",++cases);
            if(sign==1){
                if(sum<val) puts("correct.");
                else puts("incorrect.");
            }
            else if(sign==2){
                if(sum>val) puts("correct.");
                else puts("incorrect.");
            }
            else if(sign==3){
                if(sum<=val) puts("correct.");
                else puts("incorrect.");
            }
            else if(sign==4){
                if(sum>=val) puts("correct.");
                else puts("incorrect.");
            }
            else if(sign==5){
                if(sum==val) puts("correct.");
                else puts("incorrect.");
            }

        }
        MP.clear();
    }
    party.clear();
    str.clear();
    return 0;
}
/*
The achieved vote percentage of each party always has one digit after the decimal point.
One way you could read the percentage x is using:
int x, i, f;
scanf("%d.%d", &i, &f);
x = i * 10 + f;

Now for the comparisons multiply n * 10.
*/
