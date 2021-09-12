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
string arr[5005],temp,str;
stringstream sstr;
int size,xx,i,asg;
map<string,int>MP;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(getline(cin,temp)){
        str+=temp+" ";
    }
    size=str.size();
    for(i=0;i<size;i++){
        if(str[i]>64 && str[i]<91) str[i]=str[i]+32;
        else if(str[i]>96 && str[i]<123) str[i]=str[i];
        else str[i]=' ';
    }
    sstr<<str;
    asg=0;
    while(sstr>>temp){
        if(MP.find(temp)==MP.end()) MP[temp]=asg++;
        xx=MP[temp];
        arr[xx]=temp;
    }
    size=MP.size();
    sort(arr,arr+size);
    for(i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    MP.clear();
    return 0;
}
