#include <iostream>
#include <queue>
using namespace std;
struct TT{
    string apprnce;
    int age;
};
struct compare{
    bool operator()(TT a, TT b){
        return a.age > b.age;
    }
};
priority_queue < TT , vector<TT> , compare > pq;
//priority_queue < TT , deque<TT> , compare > pq;
int i;
TT t;
int main()
{
    for(i=0;i<5;i++){
        t.apprnce="goru";
        t.age=i*10;
        pq.push(t);
    }
    while ( !pq.empty() ){
        cout << pq.top().apprnce<< " " << pq.top().age << endl;
        pq.pop();
    }
    return 0;
}
