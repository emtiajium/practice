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
struct TT{
    string word;
    int countt;
};
string str="",temp;
map<string,int> MP;
stringstream sstr;
TT arr[100005];
int size,i,asg,xx,coun;
double Et,Emax,Erel;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(getline(cin,temp) && temp!="****END_OF_INPUT****"){
        str=str+temp+" ";
        if(temp=="****END_OF_TEXT****"){
            size=str.size();
            for(i=0;i<size;i++){
                if(str[i]>96 && str[i]<123) str[i]=str[i]-32;
                else if(str[i]>64 && str[i]<91) str[i]=str[i];
                else if(str[i]==','||str[i]=='.'||str[i]==':'||str[i]==';'||str[i]=='!'||str[i]=='?'||str[i]=='"'||str[i]=='('||str[i]==')')
                    str[i]=' ';
            }
            sstr<<str;
            asg=coun=0;
            str.clear();
            while(sstr>>temp){
                if(temp=="****END_OF_TEXT****") continue;
                coun++;
                if(MP.find(temp)==MP.end()) MP[temp]=asg++;
                xx=MP[temp];
                arr[xx].word=temp;
                arr[xx].countt++;
            }
            sstr.clear();
            size=MP.size();
            Emax=log10(coun);
            Et=0.0;
            for(i=0;i<size;i++){
                Et+=arr[i].countt*(Emax-log10(arr[i].countt));
            }
            Et=Et/coun;
            Erel=(Et*100.00)/Emax;
            printf("%d %.1lf %.0lf\n",coun,Et,Erel);
            for(i=0;i<size;i++){
                arr[i].countt=0;
            }
            MP.clear();
        }
    }
    return 0;
}
/*
word1 word2

word3
****END_OF_TEXT****
word1 word2
 \\
word3
****END_OF_TEXT****
word1 word2
 \\ \\
word3
****END_OF_TEXT****
****END_OF_INPUT****

*/
