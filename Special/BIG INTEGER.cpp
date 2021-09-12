#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct TT{
    string quotient,mod;
};
bool sign;
string addit(string,string);
string subtra(string,string);
string multi(string,string);
TT divis(string,string);
int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    TT D;
    string s,s2,add,sub,prod;
    while(cin>>s>>s2){

        add=addit(s,s2);
        sub=subtra(s,s2);
        prod=multi(s,s2);
        D=divis(s,s2);
        //cout<<s<<" / "<<s2<<" = "<<D.quotient<<endl;
        cout<<"ADDITION -> "<<add<<endl<<endl;
        if(sign==true) cout<<"SUBTRACTION -> -"<<sub<<endl<<endl;
        else cout<<"SUBTRACTION -> "<<sub<<endl<<endl;
        cout<<"MULTIPLICATION -> "<<prod<<endl<<endl;
        if(D.quotient!="emtiaj" && D.mod!="hasan")
            cout<<"QUOTIENT -> "<<D.quotient<<" MOD  -> "<<D.mod<<"\n\n";
    }
    return 0;
}
TT divis(string divident,string divisor){
    TT D;
    int l1,l2,i,j;
    string add,prod,tdivident,tquotient;
    if(divident=="0" && divisor=="0") puts("INDETERMINATE");
    else if(divisor=="0") puts("UNDEFINED");
    else{
        for(i=0;divident[i];i++){
            tdivident+=divident[i];
            if(tdivident=="0"){// 102 / 1
                D.quotient+=48;
                D.mod="0";
                tdivident.clear();
                continue;
            }
            l1=divisor.size();
            l2=tdivident.size();
            if(l1>l2){// 12/1
                D.quotient+=48;
                D.mod=tdivident;
                continue;
            }
            else if(l1==l2){
                if(divisor==tdivident){ //12/12
                    D.quotient+=49;
                    D.mod="0";
                    tdivident.clear();
                    continue;
                }
                else if(divisor>tdivident){// 12/11
                    D.quotient+=48;
                    D.mod=tdivident;
                    continue;
                }
            }//else 20/12
            add="1";
            while(1){
                prod=multi(divisor,add);
                l1=prod.size();
                l2=tdivident.size();
                if(l1>l2) break;
                else if(l1==l2){
                    if(tdivident<prod) break;
                }
                tquotient=add;
                add=addit(add,"1");
            }
            for(j=0;tquotient[j];j++)
                D.quotient+=tquotient[j];
            prod=multi(divisor,tquotient);
            D.mod=subtra(tdivident,prod);//a=bq+r
            if(D.mod=="0") tdivident.clear();
            else tdivident=D.mod;
        }
        for(i=j=0;D.quotient[i];i++){//leading zero
            if(D.quotient[i]>48){
                j++;
                break;
            }
        }
        if(j==0) D.quotient="0";
        else{
            for(j=i,i=0;D.quotient[j];j++)
                D.quotient[i++]=D.quotient[j];
            D.quotient.erase(i);
        }
        return D;
    }
    D={"emtiaj","hasan"};
    return D;
}
string multi(string s1 ,string s2 ){
    int i,j,l1,l2,m,n,hold,sum;
    string temp,prod="0";
    l1=s1.size();
    l2=s2.size();
    if(l1<l2){
        swap(l1,l2);
        swap(s1,s2);
    }
    if(s2=="0") return prod;
    else{
        for(i=0,n=l2-1;i<l2;i++,n--){
            temp.insert(temp.begin(),i,48);
            for(j=0,m=l1-1,hold=0;j<l1;j++,m--){
                sum=(s2[n]-48)*(s1[m]-48)+hold;
                hold=sum/10;
                temp+=sum%10+48;
            }
            if(hold) temp+=hold+48;
            reverse(temp.begin(),temp.end());
            prod=addit(temp,prod);
            temp.clear();
        }
    }
    return prod;
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

string subtra(string s1 ,string s2){//divident>remainder
    int i,l1,l2,m,n,hold,diff;
    string sub;
    sign=false;
    l1=s1.size();
    l2=s2.size();
    if(l1==l2 && s1==s2) sub="0";
    else{
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
                sub+=diff+48+10;
            }
            else{
                sub+=diff+48;
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
