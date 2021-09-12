typedef pair<int,int> pii;

struct P{
    double x,y,z;
    P(double xt=0,double yt=0,int zt=0){x=xt,y=yt,z=zt;}
};

struct Comparator
{
    bool operator ()(const P &a,const P &b) const
    {
        if(a.y!=b.y)  return a.y<b.y;
        return a.x<b.x;
    }
};

const int S = 100000;
P p[S];

bool com(P a,P b){return(a.x!=b.x)?(a.x<b.x):(a.y<b.y);}
double SD(P a,P b){return sqr(a.x-b.x)+sqr(a.y-b.y);}


pii ClosestPair(P p[],int n)
{
    /// Return the index numbers of closest points.
    int left,right,ci,cj,i;
    double  dis,m;
    set<P,Comparator>st;
    P tmp;
    __typeof(st.begin())    itl,ith;

    sort(p,p+n,com);
    for(i=0;i<n;i++)    p[i].z = i;

    ci=p[0].z;
    cj=p[1].z;
    m = SD(p[0],p[1]);
    st.insert(p[0]);
    st.insert(p[1]);
    left=0;right=2;

    while(right<n)
    {
        while(left<right && sqr(p[left].x-p[right].x)>=m)
        {
            st.erase(p[left]);
            left++;
        }

        dis=sqrt(m)+ERR;

        itl = st.lower_bound(P(p[right].x,p[right].y-dis));
        ith = st.upper_bound(P(p[right].x,p[right].y+dis));

        while(itl!=ith)
        {
            dis = SD(*itl,p[right]);

            if(dis<m)
            {
                m=dis;
                ci=itl->z;
                cj = p[right].z;
            }
            itl++;
        }

        st.insert(p[right]);
        right++;
    }

    return pii(ci,cj);
}


