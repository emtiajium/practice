#include<stdio.h>
#include<iostream>                                                                                                                       #include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
string s1,s2,add;
int l1,l2,i,j,m,n,sum,hold;
int main()
{
    while(cin>>s1>>s2){
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
            add.push_back(sum%10+48);
            hold=sum/10;
        }
        if(hold) add.push_back(hold+48);
        reverse(add.begin(),add.end());
        cout<<add<<endl;
        s1.erase(s1.begin(),s1.end());
        s2.erase(s2.begin(),s2.end());
        add.erase(add.begin(),add.end());
    }
    return 0;
}
