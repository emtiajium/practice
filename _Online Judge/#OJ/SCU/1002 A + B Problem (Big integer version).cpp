#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addit(string,string);

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s,s2,add;

    while(cin>>s>>s2){
        add=addit(s,s2);
        cout<<add<<endl;
    }
    return 0;
}

string addit(string s1,string s2){
    int m,n,i,l1,l2,hold,sum;
    string add;
    l1=s1.size();
    l2=s2.size();
    if(l2>l1){
        swap(l1,l2);
        swap(s1,s2);
    }
    m=l1-1;
    n=l2-1;
    for(i=0,hold=0;i<l1;i++,m--,n--){
        if(n>=0) sum=(s1[m]-48)+(s2[n]-48)+hold;
        else sum=(s1[m]-48)+hold;
        add+=sum%10+48;
        hold=sum/10;
    }
    if(hold) add+=hold+48;
    reverse(add.begin(),add.end());
    return add;
}
