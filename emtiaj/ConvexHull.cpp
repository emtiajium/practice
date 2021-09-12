#include <bits/stdc++.h>
using namespace std;

const int SIZE=105;

struct TT{
    int x,y;
};

TT P[SIZE],C[SIZE],pivot,now,prev;
int n,i,nc;
stack<TT>S;

int TriAreaTwice(TT a, TT b, TT c){
    int area=(a.x*b.y+b.x*c.y+c.x*a.y)-(a.x*c.y+c.x*b.y+b.x*a.y);
    return area;
}

int sqDist(TT a, TT b){
    int dist=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
    return dist;
}

bool comp(TT a, TT b){
    int d = TriAreaTwice(pivot,a,b);
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
    int i,j,pos=0;
    for(i=1;i<n;i++){
        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x>P[pos].x))
            pos = i;
    }
    swap(P[0],P[pos]);
    pivot=P[0];
    sort(P,P+n,comp);
    //puts("After Sorting"); for(i=0;i<n;i++){ printf("%d %d\n",P[i].x,P[i].y); } puts("");
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
            if(TriAreaTwice(prev,now,P[i])>0){//CCW
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
    printf("%d\n",nc+1);
    for(i=0;i<nc;i++){
        printf("%d %d\n",C[nc-i-1].x,C[nc-i-1].y);
    }
    printf("%d %d\n",C[nc-0-1].x,C[nc-0-1].y);
}

int main(){

    freopen("input.txt","r",stdin);

    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%d%d",&P[i].x,&P[i].y);
        }
        ConvexHull();
    }
    return 0;
}
