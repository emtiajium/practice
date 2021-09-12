/*Problem Statement:
There are N cities in the kingdom ‘Nameless’ and among them K cities have airport.
There the airline companies are willing to setup their flight directly between M
pairs of the cities. They think that it will not be profitable for them to run
flights between other pairs of cities. Note that if there are airports in both of
the cities of any of their M pairs only then they will run flight between that pair
otherwise not. Because of this policy of the airline companies and also because all
 the cities don’t have airport many people can’t travel between their desired cities.
  So some people of the country have demanded that the king should do something so
  that they can travel to their destinations. There are Q demands which came to the
  king. Every demand is a pair (x, y) which means some people want a route between
  city x and city y. The king really wants to satisfy the demands but he does not
  want to setup too many airports. So for every demand (x, y) the king wants to know
  the minimum number of airports he needs to setup to establish a route between city
  x and city y.

Input:

The first line of the input contains X the number of test cases which is at most 10.
 Each case starts with three numbers N ( 1 ≤ N ≤ 2,000), M ( 0 ≤ M ≤ 10,000) and
 K ( 1 ≤ K ≤ N). Here N is the number of cities, M is the number of direct air routes
 the airlines companies are willing to setup and K is the number of cities which has
 airport. Then there will be a line containing K integers which denote the name of the
 cities which have airport (city name ranges from 1 to N). Each city is separated by a
 single space. Then there will be M lines each of which contains one pair “a b”. It
 means that the airline companies are willing to run their flights between city a and b.
  The next line contains Q ( 1 ≤ Q ≤ 50 ) which is the number of demands came to the
  king. Then there will be Q lines each containing a pair “x y” which means that the
  king should build minimum airport to establish a route between city x and city y.
  There is a blank line between every consecutive test case.

Output:

For every test case you have to output the case number first (See the sample). Then
you have to output Q lines each containing the minimum number of airports the king has
 to setup to satisfy that demand. If it’s impossible to satisfy that demand then output
  -1. You have to output a blank line after each test case.

SAMPLE INPUT
OUTPUT FOR SAMPLE INPUT
1
6 4 4
1 2 5 6
1 2
3 5
2 4
4 5
3
1 2
1 3
1 6

Case 1:
0
2
-1
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define white 0
#define black 1
#define INF 1000000
#define SIZE 3000
#define NILL -1

vector<int>adj[SIZE],Par(SIZE),Dist(SIZE),Color(SIZE),Port(SIZE);

void BFS(int source,int nodes);

int main()
{
    int test,n,m,k,u,v,i,Case=1,count,query,val;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&m,&k);
        n++;
        for(i=0;i<n;i++)
        {
            adj[i].clear();
            Port[i]=false;
        }
        for(i=0;i<k;i++)
        {
            scanf("%d",&val);
            Port[val]=true;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        printf("Case %d:\n",Case++);
        scanf("%d",&query);
        for(i=0;i<query;i++)
        {
            scanf("%d %d",&u,&v);
            BFS(u,n);
            if(u==v)
                printf("0\n");
            else if(Dist[v]==INF)
                printf("-1\n");
            else printf("%d\n",Dist[v]);
        }
        printf("\n");
    }
    return 0;
}

void BFS(int source,int nodes)
{
    int i,u,v,cost;
    queue<int>Q;

    for(i=0;i<nodes;i++)
    {
        Dist[i]=INF;
        Color[i]=white;
        Par[i]=NILL;
    }
    Dist[source]=0;
    if(Port[source]==true)
        Dist[source]=0;
    else Dist[source]=1;
    Q.push(source);

    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            v=adj[u][i];
            if(Port[v]==true)
                cost=0;
            else cost=1;
            if(Dist[u]+cost<Dist[v])
            {
                Dist[v]=Dist[u]+cost;
                Par[v]=u;
                Q.push(v);
            }
        }
    }
}

