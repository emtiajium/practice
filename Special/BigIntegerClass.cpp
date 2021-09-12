#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class BigInteger {
public:
    string number,mod,sign="";

    BigInteger () {};
    BigInteger ( string number ) {
        this -> number = number;
    }

    string removeLeadingZero ( string number ) {
        int i,j;

        for( i=j=0; number[i]; i++ ) {//leading zero
            if( number[i]>48 ) {
                j++;
                break;
            }
        }
        if( j==0 ) return "0";
        for( j=i,i=0; number[j]; j++ ) {
            number[i++] = number[j];
        }
        number.erase(i);
        return number;
    }

    BigInteger operator + ( BigInteger param ) {

        int m,n,l1,l2,i,hold,sum;
        string add;

        number = removeLeadingZero( number );
        param.number = removeLeadingZero( param.number );
        l1 = number.size();
        l2 = param.number.size();
        if(l2>l1) {
            swap(l1,l2);
            swap(number,param.number);
        }
        for( i=0,m=l1-1,n=l2-1,hold=0; i<l1; i++,m--,n-- ) {
            if( n>=0 ) sum = ( number[m]-48 ) + ( param.number[n]-48 ) + hold;
            else sum = ( number[m]-48 ) + hold;
            add += sum % 10 + 48;
            hold = sum / 10;
        }
        if( hold ) add += hold + 48;
        reverse( add.begin(),add.end() );
        number = removeLeadingZero(add);
        return number;
    }

    BigInteger operator - ( BigInteger param ) {
        int l1,l2,i,m,n,hold,diff;
        string sub;
        BigInteger c;

        number = removeLeadingZero( number );
        param.number = removeLeadingZero( param.number );
        l1 = number.size();
        l2 = param.number.size();
        c.sign = "";
        if(l1<l2) {
            swap(l1, l2);
            swap(number, param.number);
            c.sign = "-";
        }
        else if(l1 == l2) {
            if(number < param.number) {
                swap(number, param.number);
                c.sign = "-";
            }
        }
        else if( l1 == l2 && number == param.number ) {
            sub = "0";
            number = sub;
            return number;
        }
        for( i=0,m=l1-1,n=l2-1,hold=0; i<l1; i++,m--,n--) {
            if( n>=0 ) diff = (number[m]-48) - (param.number[n]-48) - hold;
            else diff = (number[m]-48) - hold;
            if( diff<0 ) {
                hold = 1;
                sub += diff + 48 + 10;
            }
            else {
                sub += diff + 48;
                hold = 0;
            }
        }
        for( i=l1-1; i>0; i-- ) {
            if( sub[i] > 48 ) break;
        }
        sub.erase(i+1);
        reverse( sub.begin(),sub.end() );
        c.number = removeLeadingZero(sub);
        return c;
    }

    BigInteger operator * (BigInteger param) {
        int l1,l2,i,j,m,n,hold,sum,l3,l4;
        string temp,prod="0";
        BigInteger a,b,c;

        number = removeLeadingZero( number );
        param.number = removeLeadingZero( param.number );
        l1 = number.size();
        l2 = param.number.size();
        if( l1<l2 ){
            swap( l1,l2 );
            swap( number,param.number );
        }
        if( param.number == "0" ) {
            number = "0";
            return number;
        }
        for( i=0,n=l2-1; i<l2; i++,n--) {
            temp.insert( temp.begin(),i,48 );
            for( j=0,m=l1-1,hold=0; j<l1; j++,m-- ) {
                sum = (param.number[n]-48) * (number[m]-48) + hold;
                hold = sum / 10;
                temp += sum % 10 + 48;
            }
            if( hold ) temp += hold + 48;
            reverse( temp.begin(),temp.end() );
            a.number = temp;
            b.number = prod;
            c = a + b;
            prod = c.number;
            temp.erase( temp.begin(),temp.end() );
        }
        number = removeLeadingZero(prod);
        return number;
    }

    BigInteger operator / (BigInteger param) {
        // divident = number; divisor = param.number;
        int l1,l2,i,j;
        string quotient,mod,add,prod,tdivident,tquotient;
        BigInteger a,b,c;

        number = removeLeadingZero( number );
        param.number = removeLeadingZero( param.number );
        if( param.number == "0" ) {
            c.number = c.mod = "UNDEFINED";
            return c;
        }
        for( i=0; number[i]; i++ ) {
            tdivident += number[i];
            if( tdivident == "0" ) {// 102 / 1
                quotient += 48;
                mod = "0";
                tdivident.erase( tdivident.begin(),tdivident.end() );
                continue;
            }
            l1 = param.number.size();
            l2 = tdivident.size();
            if( l1>l2 ) {// 12/1
                quotient += 48;
                mod = tdivident;
                continue;
            }
            else if( l1==l2 ) {
                if( param.number == tdivident ) { //12/12
                    quotient += 49;
                    mod = "0";
                    tdivident.erase( tdivident.begin(),tdivident.end() );
                    continue;
                }
                else if( param.number > tdivident ) {// 12/11
                    quotient += 48;
                    mod = tdivident;
                    continue;
                }
            }//else 20/12
            add = "1";
            while( true ) {
                a = param.number; // a.number = param.number, a.mod, a.sign = garbage value
                b = add;
                c = a * b;
                prod = c.number;
                l1 = prod.size();
                l2 = tdivident.size();
                if( l1>l2 ) break;
                if( l1==l2 && tdivident < prod ) break;
                tquotient = add;
                a = add;
                string str = "1";
                b = str;
                c = a + b;
                add = c.number;
            }
            for( j=0; tquotient[j]; j++ ) {
                quotient += tquotient[j];
            }
            a = param.number;
            b = tquotient;
            c = a * b;
            prod = c.number;
            a = tdivident;
            b = prod;
            c = a - b;
            mod = c.number; // a = bq +r;
            if( mod == "0" ) tdivident.erase( tdivident.begin(),tdivident.end() );
            else tdivident = mod;
        }
        c.number = removeLeadingZero(quotient);
        c.mod = removeLeadingZero(mod);
        return c;
    }

    BigInteger operator % (BigInteger param) {
        BigInteger a,b,c;
        a = number;
        b = param.number;
        c = a / b;
        return c.number = c.mod;
    }
};

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s,sign,s2;
    cout << "Input Pattern: Number1 Sign Number2\n\n";

    while( cin >> s >> sign >> s2 ){

        BigInteger a(s);
        BigInteger b(s2);
        BigInteger c;

        cout << a.number << " " << sign << " " << b.number << " = ";

        if( sign == "+" ) c = a + b;
        if( sign == "-" ) c = a - b;
        if( sign == "*" ) c = a * b;
        if( sign == "/" ) c = a / b;
        if( sign == "%" ) c = a % b;

        cout << c.sign << c.number << endl;
    }
    return 0;
}
