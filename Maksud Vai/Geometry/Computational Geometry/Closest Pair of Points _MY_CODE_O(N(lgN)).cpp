#include<iostream>
#include<algorithm>
#include<set>
#include<stdio.h>
#include<math.h>

using namespace std;


const int NP = 10010;

typedef struct {
    double x,y;
    void scan(){
        scanf("%lf%lf",&x,&y);
    }
}P;

typedef pair<P,P>ppp;

P p[NP],X[NP],Y[NP],L[NP],R[NP];

bool comx(P a,P b){   return a.x<b.x;}
bool comy(P a,P b){   return a.y<b.y;}
double sqr(double x){return x*x;}
double disP(P a,P b){
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

ppp ClosestPair(int l,int h)
{
    /// If less than 4 points.
    if(h-l<3)
    {
        double min=1e13,cur;
        P a=(P){0.0,0.0},b=(P){10000000.0,10000000.0};

        for(int i=l;i<=h;i++)
            for(int j=i+1;j<=h;j++)
            {
                cur = disP(X[i],X[j]);
                if(min>cur)
                {
                    min = cur;
                    a=X[i];
                    b=X[j];
                }
            }

        ///For sorted Y
        sort(&Y[l],&Y[h+1],comy);
        return ppp(a,b);
    }
    else
    {
        ppp cp1,cp2;
        cp1 = ClosestPair(l,(l+h)/2);
        cp2 = ClosestPair((l+h)/2+1,h);

        double min = disP(cp1.first,cp1.second);

        if(min>disP(cp2.first,cp2.second))
        {
           min=disP(cp2.first,cp2.second);
           cp1=cp2;
        }

        ///Middle
        double x=(X[(l+h)/2].x+X[(l+h)/2+1].x)/2.0;

        int lc,rc,i,j,k,a,b;

        ///Find L'
        for(lc=0,i=l;i<=(l+h)/2;i++)
            if(fabs(x-Y[i].x)<min)
                L[lc++] = Y[i];

        ///Find R'
        for(rc=0,i=(l+h)/2+1;i<=h;i++)
            if(fabs(Y[i].x-x)<min)
                R[rc++] = Y[i];

        ///Sort P'
        k=0;
        for(i=j=0;i<lc||j<rc;)
        {
            if(i<lc && j<rc)
            {
                if(L[i].y<R[j].y)   p[k++]=L[i++];
                else p[k++]=R[j++];
            }
            else if(i<lc)   p[k++]=L[i++];
            else p[k++]=R[j++];
        }

        for(i=0;i<k;i++)
        {
            for(j=i+1;j<k && j<i+7;j++)     ///This loop will iterate maximum 7 times.
                if(disP(p[i],p[j])<disP(cp1.first,cp1.second))
                    cp1 = ppp(p[i],p[j]);
                else if(fabs(p[j].y-p[i].y)>disP(cp1.first,cp1.second))
                    break;
        }

        /// Mergeing of Y
        lc = (l+h)/2;
        rc = h;
        for(k=l,i=l,j=lc+1; i <= lc || j <= rc ;)
        {
            if(i<=lc && j<=rc)
            {
                if(Y[i].y<Y[j].y)   p[k++]=Y[i++];
                else p[k++]=Y[j++];
            }
            else if(i<=lc)   p[k++]=Y[i++];
            else p[k++]=Y[j++];
        }

        for(i=l;i<=h;i++)   Y[i]=p[i];

        return cp1;
    }
}


int main()
{
    //freopen("in1.in","r",stdin);
    //freopen("in1.out","w",stdout);

    int i,n;

    ///here n > 1

    while(scanf("%d",&n)==1 && n)
    {
        for(i=0;i<n;i++)    X[i].scan();

        ///Sorting increasing of x.
        sort(X,X+n,comx);

        for(i=0;i<n;i++)
            Y[i]=X[i];

        ppp pp= ClosestPair(0,n-1);

        printf("Points are :\n");
        printf("p1(%lf, %lf) p2(%lf, %lf)\n",pp.first.x,pp.first.y,pp.second.x,pp.second.y);
        printf("Distance : %lf\n",disP(pp.first,pp.second));
    }

    return 0;
}
