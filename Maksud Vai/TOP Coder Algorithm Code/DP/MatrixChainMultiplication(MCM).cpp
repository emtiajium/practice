//MCM(Matrix Chain Multiplication)
#define SIZE 100
#define INF 2140000000
int dp[SIZE][SIZE],s[SIZE][SIZE];
void print(int i,int j)
{
	if(i==j)
		printf("A");
	else
	{
		printf("(");
		print(i,s[i][j]);
		print(s[i][j]+1,j);
		printf(")");
	}
}
void MCM(vector<int>p)
{
    int l,j,i,k,q,n;
    n=p.size()-1;
    for(i=1;i<p.size();i++)
        dp[i][i]=0;
    for(l=2;l<=n;l++)
    {
          for(i=1;i<=n-l+1;i++)
          {
	j=i+l-1;
	dp[i][j]=INF;
	for(k=i;k<j;k++)
	{
                      q=dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j];
   	       if(q<dp[i][j])
	      {
		dp[i][j]=q;
		s[i][j]=k;
	      }
	}
          }
     }
    printf("value:%d\n",dp[1][n]);
    print(1,n);
}
/*Input & Output:
7
30 35 15 5 10 20 25
15125  (Min Cost)         ((A(AA))((AA)A))        */
