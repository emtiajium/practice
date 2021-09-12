//Big Number Subtraction
#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string s1 ,s2 ,sub ;
int i,j,l1,l2,m,n,hold,diff;
bool sign;
int main()
{
    while(cin>>s1>>s2){
        l1=s1.size();
        l2=s2.size();
        sign=false;
        if(l1<l2){
            swap(l1,l2);
            swap(s1,s2);
            sign=true;
        }
        if(l1==l2){
            if(s1<s2){
                swap(s1,s2);
                sign=true;
            }
        }
        m=l1-1;
        n=l2-1;
        for(i=0,hold=0;i<l1;i++,m--,n--){
            if(n>=0)diff=(s1[m]-48)-(s2[n]-48)-hold;
            else diff=(s1[m]-48)-hold;
            if(diff<0){
                hold=1;
                sub.push_back(diff+48+10);
            }
            else{
                sub.push_back(diff+48);
                hold=0;
            }
        }
        for(i=l1-1;i>0;i--){//1269-1125=4410//reverse
            if(sub[i]!=48) break;//this loop is for 441
        }
        sub.erase(i+1);
        reverse(sub.begin(),sub.end());
        if(sign==true) putchar('-');
        cout<<sub<<endl;
        s1.erase(s1.begin(),s1.end());
        s2.erase(s2.begin(),s2.end());
        sub.erase(sub.begin(),sub.end());
    }
    return 0;
}
