#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef struct { ll x,y;    void scan(){    cin>>x>>y;} }P;

P MV(P a,P b){ P r; r.x = b.x-a.x; r.y = b.y-a.y; return r;}
int CV(P a,P b){return a.x*b.y - a.y*b.x;}
bool onsegment(P a,P b,P c){
    return( min(a.x,b.x)<=c.x && c.x<=max(a.x,b.x) && min(a.y,b.y)<=c.y && c.y<=max(a.y,b.y) );
}

bool segment_intersect(P p1,P p2,P p3,P p4)
{
    ll d1,d2,d3,d4;

    d1 = CV(MV(p1,p3),MV(p4,p3));
    d2 = CV(MV(p2,p3),MV(p4,p3));
    d3 = CV(MV(p3,p1),MV(p2,p1));
    d4 = CV(MV(p4,p1),MV(p2,p1));

    if(d1*d2<0 && d3*d4<0)  return true;
    if(!d1 && onsegment(p3,p4,p1))  return true;
    if(!d2 && onsegment(p3,p4,p2))  return true;
    if(!d3 && onsegment(p1,p2,p3))  return true;
    if(!d4 && onsegment(p1,p2,p4))  return true;

    return false;
}

bool f[1100];
P pa[1010],pb[1010];

int main()
{
    ll i,j,n,ans;
    //freopen("in.in","r",stdin);

    while(cin>>n && n)
    {
        ans=0;
        memset(f,true,sizeof (f));

        for(i=0;i<n;i++)
        {
            pa[i].scan();
            pb[i].scan();
        }

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                if(segment_intersect(pa[i],pb[i],pa[j],pb[j]) )
                {
                    ans++;
                    f[i] = f[j] = false;
                }
            if( f[i] )  ans += 2;
        }
        cout<<ans<<endl;
    }

    return 0;
}
