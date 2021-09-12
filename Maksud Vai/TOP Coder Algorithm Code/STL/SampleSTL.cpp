#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>

using namespace std;

#define PI 2*acos(0)

int main()
{
    int i,len;

    //Vector Implements
    vector<int>a;

    a.clear();
    for(i=0;i<5;i++)
        a.push_back(i+5);

    len=a.size();

    for(i=0;i<len;i++)
        printf("%d\n",a[i]);

    a.erase(a.begin()+3);

    for(i=0;i<a.size();i++)
        printf("%d\n",a[i]);



    //string Implement
    string str="We think in generalities, but we live in details.";
    string str2;
    string::iterator it;

    str2 = str.substr (12,12);
    cout<<str2<<endl;

    if(str.find(str2)!=-1)
        cout<<"Found Data\n";

    reverse(str.begin(),str.end());

    cout<<str<<endl;


    //String Conversion
    istringstream iss;
    iss.str(str);
    while(iss>>str2)
    {
        cout<<str2<<endl;
    }

    str="1245 56898 5689 1245 124545";
    iss.clear();
    iss.str(str);
    while(iss>>i)
    {
        cout<<i<<endl;
    }

    for(it=str.begin();it!=str.end();it++)
        cout<<*it;
    cout<<endl;


    //Map Opertion
    map<char,int> mymap;
    map<char,int>::iterator x;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
    for ( x=mymap.begin() ; x != mymap.end(); x++ )
        cout << (*x).first << " => " << (*x).second << endl;

    mymap.clear();

    mymap['c']=50;
    mymap['b']=100;
    mymap['a']=150;
    mymap['d']=200;
    x=mymap.find('b');
    mymap.erase (x);
    mymap.erase (mymap.find('d'));
    for ( x=mymap.begin() ; x != mymap.end(); x++ )
        cout << (*x).first << " => " << (*x).second << endl;

    cout << "mymap.size() is " << (int) mymap.size() << endl;

    //Queue Operation
    queue<int> myqueue;
    int myint;

    cout << "Please enter some integers (enter 0 to end):\n";

    for (int i=0; i<5; ++i) myqueue.push(i+5);

    cout << "myqueue contains: ";
    while (!myqueue.empty())
    {
        cout << " " << myqueue.front();
        myqueue.pop();
    }

    //Stack Operation
    stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    cout << "\nPopping out elements...";
    while (!mystack.empty())
    {
        cout << " " << mystack.top();
        mystack.pop();
    }
    cout << endl;

    //Priority Queue
    priority_queue<int> mypq;

    mypq.push(30);
    mypq.push(100);
    mypq.push(25);
    mypq.push(40);

    cout << "Popping out elements...";
    while (!mypq.empty())
    {
        cout << " " << mypq.top();
        mypq.pop();
    }
    cout << endl;


    //Set
    set<int> myset;
    set<int>::iterator y;

    for (int i=1; i<=5; i++) myset.insert(i*10);
    cout << "myset contains:";
    for (y=myset.begin(); y!=myset.end(); y++)
        cout << " " << *y;
    cout << endl;
    y=myset.find(20);
    myset.erase (y);
    myset.erase (myset.find(40));

    cout << "myset contains:";
    for (y=myset.begin(); y!=myset.end(); y++)
        cout << " " << *y;
    cout << endl;
    cout<<"size:"<<(int)myset.size()<<endl;
    myset.clear();
    cout<<"size:"<<(int)myset.size()<<endl;


    //Algorithm STL
     int myints[] = {1,2,3,4,5,4,3,2,1};
    vector<int> v(myints,myints+9);
    vector<int>::iterator m;
    sort (v.begin(), v.end());

    cout << "looking for a 3... ";
    if (binary_search (v.begin(), v.end(), 3))
        cout << "found!\n"; else cout << "not found.\n";
    m=find(v.begin(),v.end(),3);
    cout<<"value:"<<*m<<endl;
    cout << "Min:" << *min_element(v.begin(),v.end())<<endl;
    cout << "Max:" << *max_element(v.begin(),v.end())<<endl;

    //Next Permutation
    int b[] = {1,2,3};

    cout << "The 3! possible permutations with 3 elements:\n";

    sort (b,b+3);

    do {
        cout << b[0] << " " << b[1] << " " << b[2] << endl;
    } while ( next_permutation (b,b+3) );

    //Prev Permutation
    printf("\n\n\n");
    sort (b,b+3);
    reverse (b,b+3);

    do {
        cout << b[0] << " " << b[1] << " " << b[2] << endl;
    } while ( prev_permutation (b,b+3) );


    //Cmath
    //tan2
    double p, q, result;
    p = -10.0;
    q = 10.0;
    result = atan2(p,q) * 180 / PI;
    printf ("arc tan(x=%lf, y=%lf) is %lf deg\n",p,q,result);

    //exponential
    double param;
    param = 5.0;
    result = exp (param);
    printf ("The exponential value of %lf is %lf.\n", param, result );
    return 0;
}

