#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addit(string,int,string,int);
string subtra(string,int,string,int);
string multi(string,int,string,int);

int main()
{
    int l1,l2,i,j;
    string divident,divisor,quotient,mod ;
    string add,prod,tdivident,tquotient ;
    //freopen("division.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(cin>>divident>>divisor){
        if( divident=="0" && divisor=="0") puts("INDETERMINATE");
        else if(divisor=="0") puts("UNDEFINED");
        else{
            for(i=0;divident[i];i++){
                tdivident.push_back(divident[i]); // or use tdivident+=divident[i];
                if(tdivident=="0"){// 102 / 1
                    quotient.push_back(48);
                    mod="0";
                    tdivident.erase(tdivident.begin(),tdivident.end());
                    continue;
                }
                l1=divisor.size();
                l2=tdivident.size();
                if(l1>l2){// 12/1
                    quotient.push_back(48);
                    mod=tdivident;
                    continue;
                }
                else if(l1==l2){
                    if(divisor==tdivident){ //12/12
                        quotient.push_back(49);
                        mod="0";
                        tdivident.erase(tdivident.begin(),tdivident.end());
                        continue;
                    }
                    else if(divisor>tdivident){// 12/11
                        quotient.push_back(48);
                        mod=tdivident;
                        continue;
                    }
                }//else 20/12
                add="1";
                while(1){
                    prod=multi(divisor,divisor.size(),add,add.size());
                    l1=prod.size();
                    l2=tdivident.size();
                    if(l1>l2) break;
                    else if(l1==l2){
                        if(tdivident<prod) break;
                    }
                    tquotient=add;
                    add=addit(add,add.size(),"1",1);
                }
                for(j=0;tquotient[j];j++)
                    quotient.push_back(tquotient[j]);
                prod=multi(divisor,divisor.size(),tquotient,tquotient.size());
                mod=subtra(tdivident,tdivident.size(),prod,prod.size());//a=bq+r
                if(mod=="0") tdivident.erase(tdivident.begin(),tdivident.end());
                else tdivident=mod;
            }
            for(i=j=0;quotient[i];i++){//leading zero
                if(quotient[i]>48){
                    j++;
                    break;
                }
            }
            if(j==0) quotient="0";
            else{
                for(j=i,i=0;quotient[j];j++)
                    quotient[i++]=quotient[j];
                quotient.erase(i);
            }
            cout<<"QUOTIENT -> "<<quotient<<" MOD  -> "<<mod<<"\n\n";
        }
        divident.erase(divident.begin(),divident.end());
        divisor.erase(divisor.begin(),divisor.end());
        quotient.erase(quotient.begin(),quotient.end());
        mod.erase(mod.begin(),mod.end());
        add.erase(add.begin(),add.end());
        prod.erase(prod.begin(),prod.end());
        tquotient.erase(tquotient.begin(),tquotient.end());
        tdivident.erase(tdivident.begin(),tdivident.end());
    }
    return 0;
}

string multi(string s1 ,int l1,string s2 ,int l2){
    int i,j,m,n,hold,sum,l3,l4;
    string temp,prod="0";
    l1=s1.size();
    l2=s2.size();
    if(l1<l2){
        swap(l1,l2);
        swap(s1,s2);
    }
    if(s2=="0") prod="0";
    else{
        for(i=0,n=l2-1;i<l2;i++,n--){
            temp.insert(temp.begin(),i,48);
            for(j=0,m=l1-1,hold=0;j<l1;j++,m--){
                sum=(s2[n]-48)*(s1[m]-48)+hold;
                hold=sum/10;
                temp.push_back(sum%10+48);
            }
            if(hold) temp.push_back(hold+48);
            reverse(temp.begin(),temp.end());
            l3=temp.size();
            l4=prod.size();
            prod=addit(temp,l3,prod,l4);
            temp.erase(temp.begin(),temp.end());
        }
    }
    return prod;
}

string addit(string s1 ,int l1,string s2 ,int l2){
    int m,n,i,hold,sum;
    string add;
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
    return add;
}

string subtra(string s1 ,int l1,string s2 ,int l2){//divident>remainder
    int i,m,n,hold,diff;
    string sub;
    if(l1==l2 && s1==s2) sub="0";
    else{
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
        for(i=l1-1;i>0;i--){
            if(sub[i]>48) break;
        }
        sub.erase(i+1);
        reverse(sub.begin(),sub.end());
    }
    return sub;
}
