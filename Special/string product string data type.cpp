#include<stdio.h>
#include<string.h>
#include<iostream>                                                                                                                       #include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
string fir ,sec ,temp ,s1 ,prod ;
int l1,l2,l3,l4,m,n,p,q,hold,i,j,k,x,sum;

int main()
{
    while(cin>>fir>>sec){
        prod="0";
        l1=fir.size();
        l2=sec.size();
        if(l1<l2){
            swap(l1,l2);
            swap(fir,sec);
        }
        if(sec>"0"){
            for(i=0,n=l2-1;i<l2;i++,n--){
                temp.insert(temp.begin(),i,48);
                for(j=0,m=l1-1,hold=0;j<l1;j++,m--){
                    sum=(sec[n]-48)*(fir[m]-48)+hold;
                    hold=sum/10;
                    temp.push_back(sum%10+48);
                }
                if(hold) temp.push_back(hold+48);
                reverse(temp.begin(),temp.end());
                s1=temp;
                temp.erase(temp.begin(),temp.end());
                l3=s1.size();
                l4=prod.size();
                if(l4>l3){
                    swap(l3,l4);
                    swap(s1,prod);
                }
                p=l3-1;
                q=l4-1;
                for(j=0,hold=0;j<l3;j++,p--,q--){
                    if(q>=0) sum=(s1[p]-48)+(prod[q]-48)+hold;
                    else sum=(s1[p]-48)+hold;
                    temp.push_back(sum%10+48);
                    hold=sum/10;
                }
                if(hold) temp.push_back(hold+48);
                reverse(temp.begin(),temp.end());
                prod=temp;
                s1.erase(s1.begin(),s1.end());
                temp.erase(temp.begin(),temp.end());
            }
        }
        cout<<prod<<endl;
        fir.erase(fir.begin(),fir.end());
        sec.erase(sec.begin(),sec.end());
        temp.erase(temp.begin(),temp.end());
        s1.erase(s1.begin(),s1.end());
        s1.erase(s1.begin(),s1.end());
    }
    return 0;
}
