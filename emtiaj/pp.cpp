#include <iostream>
#include <complex>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
typedef complex<double> point;

#define PI 3.141592653589793
#define EPS 0.0000000001
#define X real()
#define Y imag()
#define vec(a,b) ((b)-(a))
#define cross(a,b)  ((conj(a)*b).imag())
#define dot(a,b)  ((conj(a)*(b)).real())
#define length(a)  hypot((a).X,(a).Y)
#define lenSqr(a)  dot(a,a)
#define len(v) ((int)v.size)

point pivot(0,0);
bool collinear(point &a,point &b,point &c)
{
    return (fabs(cross(vec(a,b),vec(a,c))) < EPS);


}
bool ccw(point a,point b,point c)
{
    return cross(vec(a,b),vec(a,c)) > 0;
}
bool angleCmp(point a,point b)
{
    if(collinear(pivot,a,b))
    {
      return lenSqr(vec(pivot,a)) < lenSqr(vec(pivot,b));
    }
   return ccw(pivot,a,b);

}
vector<point> CH(vector<point> P)
{

    int i,N=(int)P.size();
    int po=0;
    for ( i=0;i<N-1;i++)
        if(P[i].Y < P[po].Y || (P[i].Y== P[po].Y && P[i].X < P[po].X))
            po=i;
    pivot = P[po];

    sort(P.begin(),P.end(),angleCmp);


    point prev(0,0),now(0,0);
    stack<point> S;
    S.push(pivot);
    i=1;
    while(i<N)
    {
        if(S.size()<2)
        {
            S.push(P[i++]);
        }
        else{
        now = S.top();
        S.pop();
        prev=S.top();
        S.push(now);
        if(ccw(prev,now,P[i])){
            S.push(P[i++]);
        }
        else S.pop();
    }
    }

    vector<point> ConvexHull;
    ConvexHull.push_back(pivot);
    while(!S.empty())
    {

        ConvexHull.push_back(S.top());
        S.pop();
    }
    return ConvexHull;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    int t,n;
    scanf("%d",&t);
    cout << t << endl;
    for (int i=0;i<t;i++)
    {
        if(i!=0)
            cout << -1 << endl;
         scanf("%d",&n);
        vector<point> v;
        int x,y;
        for (int j=0;j<n;j++)
            {
                scanf("%d %d",&x,&y);
                point p(x,y);
                v.push_back(p);
            }
        vector<point> vv = CH(v);
        int m = (int)vv.size();
        cout << m <<  endl;
        for (int j=0;j<m;j++)
            cout << vv[m-j-1].X << " " << vv[m-j-1].Y << endl;
    scanf("%d",&n);
    }
    return 0;
}
