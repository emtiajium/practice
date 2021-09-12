#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addit(string,int,string,int);
string subtra(string,int,string,int);
string multi(string,int,string,int);

int t,cases,l,i,k,n;
bool f,sign;
string s,aa,b,a;
char ch,blah;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        f=false;
        sign=false;
        scanf("%d",&n);
        getchar();
        getline(cin,s);
    	l=s.size();
    	for(i=0;i<=l;){
    		if(s[i]!=' '&&i!=l){
    			aa+=s[i];
    			i++;
    		}
    		else{
    			i++;
    			if(f==false){
    				b=aa;
    				ch=s[i];
    				f=true;
    				i+=2;
    				blah='+';
    				aa.clear();
    			}
    			else{
                    a=aa;
                    if(ch=='*') b=multi(b,b.size(),a,a.size());
                    else if(ch=='+'){
                        if(blah=='-'){
                            b=subtra(b,b.size(),a,a.size());
                            if(sign==false) blah='-';
                            else blah='+';
                        }
                        else b=addit(a,a.size(),b,b.size());
                    }
                    else if(ch=='-'){
                        if(blah=='-') b=addit(a,a.size(),b,b.size());
                        else{
                            b=subtra(b,b.size(),a,a.size());
                            if(sign==false) blah='+';
                            else blah='-';
                        }
                    }
                    ch=s[i];
                    i+=2;
                    aa.clear();
                    a.clear();
    			}
    		}
    	}
    	printf("Case %d: ",++cases);
    	if(blah=='-') printf("-");
        cout<<b<<endl;
        s.clear();
        b.clear();
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
                temp+=sum%10+48;
            }
            if(hold) temp+=hold+48;
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
        add+=sum%10+48;
        hold=sum/10;
    }
    if(hold) add+=hold+48;
    reverse(add.begin(),add.end());
    return add;
}

string subtra(string s1 ,int l1,string s2 ,int l2){
    int i,m,n,hold,diff;
    string sub;
    if(l1==l2 && s1==s2) sub="0";
    else{
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
