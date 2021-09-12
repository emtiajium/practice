#include <bits/stdc++.h>
using namespace std;

const int SIZE=1503;
typedef long long LL;

struct TT{
    LL x,y;
};

TT P[SIZE],C[SIZE],pivot,now,prev;
char arr[SIZE][51],str[51];
stack<TT>S;
LL t,n,i,nc,temp,asg;

LL TriAreaTwice(TT a, TT b, TT c){
    LL area=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.x*c.y+c.x*b.y+b.x*a.y);
    return area;
}

LL sqDist(TT a, TT b){
    LL dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return dist;
}

bool comp(TT a, TT b){
    LL d = TriAreaTwice(pivot,a,b);
    if(d){
        int dx,dy,dx2,dy2;
        double theta,theta2;
        dy=a.y-pivot.y;
        dx=a.x-pivot.x;
        dy2=b.y-pivot.y;
        dx2=b.x-pivot.x;
        theta=atan2((double)dy,(double)dx);
        theta2=atan2((double)dy2,(double)dx2);
        return theta<theta2;
    }
    if(!d) return sqDist(pivot,a)<sqDist(pivot,b);
}

void ConvexHull(){
    LL i,j,pos=0;
    for(i=1; i<n; i++){
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x>P[pos].x))
            pos = i;
    }
    swap(P[0], P[pos]);
    pivot = P[0];
    sort(P, P+n, comp);
    //puts("After Sorting"); for(i=0;i<n;i++){ printf("%lld %lld\n",P[i].x,P[i].y); } puts("");
    S.push(pivot);
    i=1;
    while(i<n){
        if(S.size()<2)
            S.push(P[i++]);
        else{
            now = S.top();
            S.pop();
            prev=S.top();
            S.push(now);
            if(TriAreaTwice(prev,now,P[i])>0){
                S.push(P[i++]);
            }
            else S.pop();
        }
    }
    i=0;
    while(!S.empty()){
        C[i++]=S.top();
        S.pop();
    }
    nc=i;
    printf("%lld\n",nc+1);
    for(i=0;i<nc;i++){
        printf("%lld %lld\n",C[nc-i-1].x,C[nc-i-1].y);
    }
    printf("%lld %lld\n",C[nc-0-1].x,C[nc-0-1].y);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif

    scanf("%lld",&t);
    printf("%lld\n",t);
    while(t--){
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld%lld",&P[i].x,&P[i].y);
        }
        ConvexHull();
        if(t){
            scanf("%lld",&temp);
            printf("%lld\n",temp);
        }
    }
    return 0;
}
