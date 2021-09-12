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
string str,temp;
map<string,int> MP;
stringstream sstr;
int m,n,dollar,salary;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(scanf("%d%d",&m,&n)==2){
        while(m--){
            cin>>str>>dollar;
            MP[str]=dollar;
        }
        getchar();
        while(n--){
            str="";
            while(getline(cin,temp) && temp!="."){
                str+=temp;
                str+=" ";
            }
            sstr<<str;
            salary=0;
            while(sstr>>temp){
                if(MP.find(temp)!=MP.end()){
                    salary+=MP[temp];
                }
            }
            printf("%d\n",salary);
            sstr.clear();
        }
        MP.clear();
    }
    str.clear();
    return 0;
}
