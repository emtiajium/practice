#define LL          long long
#define IT          ::iterator
#define fii(a,b)    for(i=a;i<b;i++)
#define rii(a)      for(i=0;i<a;i++)

const double pi=2*acos(0.);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}

typedef struct {
    LL x,y;    double an;   int t;
    void read(){    scanf("%d%I64d%I64d",&t,&x,&y);}
    void print(){printf("x:%I64d  y:%I64d  an:%lf\n",x,y,an);}
}P;

P p[100020];
set<P>s;

bool operator<(const P &a,const P &b){    return a.an<b.an;}


P MV(P a,P b){return (P){b.x-a.x,b.y-a.y};}

LL CP(P a,P b){return a.x*b.y-a.y*b.x;}

P Pre(P a)
{
    if(s.count(a)>0)    return *s.find(a);
    set<P>IT i=s.lower_bound(a);
    if(i!=s.begin())    return *--i;
    return *--s.end();
}

P Nxt(P a)
{
    set<P> IT i=s.upper_bound(a);

    if(i!=s.end())    return *i;
    return *s.begin();
}


bool Isinside(P c){
    P a=Pre(c),b=Nxt(c);
    return (CP(MV(c,b),MV(c,a))<=0);
}

void add(P a)
{
    if(Isinside(a)) return ;

    P b,c;

    while(true)
    {
        b = Nxt(a);
        s.erase(b);
        c = Nxt(a);
        if(CP(MV(c,b),MV(c,a))<0)
        {
            s.insert(b);
            break;
        }
    }

    while(true)
    {
        b = Pre(a);
        s.erase(b);
        c = Pre(a);
        if(CP(MV(c,b),MV(c,a))>0)
        {
            s.insert(b);
            break;
        }
    }

    s.insert(a);
}


int main()
{
    int i,j,k,l,n,m,cnt,a;
    double x,y;

    while(cin>>n)
    {
        s.clear();
        rii(n)
            p[i].read();

        p[0].an=0;
        x=y=0;
        rii(3)  x+=p[i].x,y+=p[i].y;

        x/=3;
        y/=3;

        rii(n)
            p[i].an=atan2(p[i].y-y,p[i].x-x)+(atan2(p[i].y-y,p[i].x-x)<0?2*pi:0);

        rii(3)  s.insert(p[i]);

        fii(3,n)
        {
            if(p[i].t==1)   add(p[i]);
            else
            {
                if(Isinside(p[i])) puts("YES");
                else puts("NO");
            }
        }
    }

    return 0;
}


