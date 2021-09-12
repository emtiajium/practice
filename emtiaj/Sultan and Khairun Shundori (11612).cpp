#include <bits/stdc++.h>
using namespace std;

const int SIZE=1003;
const double EPS=1e-7;
typedef long long LL;

struct TT{
    int x,y,idx;
};

TT P[SIZE],pivot;
int n,i,coun;
double first;

int TriAreaTwice(TT a, TT b, TT c){
    int area=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.x*c.y+c.x*b.y+b.x*a.y);
    return area;
}

int sqDist(TT a, TT b){
    int dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return dist;
}

double angle(TT a){
    int dy=a.y-pivot.y;
    int dx=a.x-pivot.x;
    double theta=atan2((double)dy,(double)dx);
    return theta;
}

bool comp(TT a, TT b){
    int d = TriAreaTwice(pivot,a,b);
    if(d){
        double theta,theta2;
        theta=angle(a);
        theta2=angle(b);
        //if(fabs(theta-theta2)<=EPS) return a.idx<b.idx;
        return theta<theta2;
    }
    if(!d) return sqDist(pivot,a)<sqDist(pivot,b);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++){
            scanf("%d%d",&P[i].x,&P[i].y);
            P[i].idx=i;
        }
        pivot=P[0];
        sort(P+1,P+n,comp);
        first=angle(P[1]);
        coun=1;
        for(i=2;i<n;i++){
            if(fabs(angle(P[i])-first)<EPS){
                coun++;
            }
        }
        if(coun==n-1){
            puts("no solution");
            continue;
        }
        for(i=0;i<n;i++){
            printf("%d ",P[i].idx);
        }
        printf("%d\n",P[0].idx);
    }
    return 0;
}
