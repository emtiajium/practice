#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
using namespace std;
string arr[105],str;
map< string, int > city;
int E,asg,a,b,i;
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&E)==1){
        for(i=asg=0;i<E;i++){
            cin>>str;
            if(city.find(str)==city.end()) city[str]=asg++;// আগে যদি অ্যাসাইন হয়ে থাকে তাহলে আবার করার দরকার নাই
            a=city[str];
            arr[a]=str;
        }
        for(i=0;i<city.size();i++)
            cout<<i<<" represents "<<arr[i]<<endl;
        puts("");
        city.clear();
    }
    return 0;
}
