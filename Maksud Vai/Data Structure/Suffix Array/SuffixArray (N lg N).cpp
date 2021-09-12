///http://e-maxx.ru/algo/suffix_array

const int S = 100000;
char s[S];
int p[S],np[S],cnt[S],c[S],nc[S],H;


void suffixArray(int n,int cls)
{
    /// n = lenght(s)+1, cls = max(s[0],s[1]......,s[n-1]) ;
    int i,m,m1;
    cls++;
    memset(cnt,0,sizeof (int)*cls);
    for(i=0;i<n;i++)    cnt[s[i]]++;
    for(i=1;i<cls;i++)  cnt[i]+=cnt[i-1];
    for(i=n-1;i>-1;i--) p[--cnt[s[i]]]=i;

    c[p[0]]=0;
    for(cls=0,i=1;i<n;i++)
    {
        if(s[p[i]]!=s[p[i-1]])  cls++;
        c[p[i]]=cls;
    }
    cls++;

    for(H=0;(1<<H)<n;H++)
    {
        for(i=0;i<n;i++)
        {
            np[i]=p[i]-(1<<H);
            if(np[i]<0) np[i]+=n;
        }

        memset(cnt,0,sizeof (int)*cls);
        for(i=0;i<n;i++)    cnt[c[np[i]]]++;
        for(i=1;i<cls;i++)  cnt[i]+=cnt[i-1];
        for(i=n-1;i>-1;i--) p[--cnt[c[np[i] ]]]=np[i];

        nc[p[0]]=0;
        for(cls=0,i=1;i<n;i++)
        {
            m = (p[i]+(1<<H))%n;
            m1 = (p[i-1]+(1<<H))%n;

            if(c[p[i]]!=c[p[i-1]] || c[m]!=c[m1])  cls++;
            nc[p[i]]=cls;
        }
        cls++;
        memcpy(c,nc,sizeof(int)*n);
    }
}


int main()
{
    int i,j,k,tks,ks=1,n,m,sum;

    while(cin>>s)
    {
        n = strlen(s)+1;
        suffixArray(n,'z');

        for(i=0;i<n;i++)
            printf("%d -> %s\n",i,p[i]+s);
    }

    return 0;
}


