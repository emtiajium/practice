/*
Lighting Away
Input: Standard Input
Output: Standard Output

Ronju is a night-guard at the “Lavish office buildings Ltd.” headquarters. The office has a large 
grass field in front of the building. So every day, when Ronju comes to duty at the evening, it is 
his duty to turn on all the lights in the field. However, given the large size of the field and the 
large number of lights, it is very tiring for him to walk to each and every individual light to turn it on.

So he has devised an ingenious plan – he will swap the switches for light-sensitive triggers. A local 
electronic store nearby sells these funny trigger switches at a very cheap price. Once installed at a 
light-post, it will automatically turn that light on whenever it can sense some other light lighting 
up nearby. So from now on, Ronju can just manually flip a few switches, and the light from those will 
trigger nearby sensors, which will in turn light up some more lights nearby, and so on, gradually lighting 
up the whole field.

Now Ronju wonders: how many switches does he have to flip manually for this?

Input
The input starts with an integer T, the number of test cases to follow. Each test case will start 
with two integers N (1 <= N <= 10000) and M (0 <= M <= 100000), where N is the number of lights in 
the field, and M more lines of input follows in this input case. Each of these extra M lines will 
have two integers a and b separated by a space, where 1 <= a, b <= N, indicating that if the light a 
lights up, it will trigger the light b to turn on as well (according to their distance, brightness, 
sensor sensitivity, orientation and other complicated factors). Finally, every test case in the input 
will be followed by a blank line.

Output
For each input test case, the output must be a single line of the format “Case k: c” where k is 
the case number starting with 1, and c is the minimum number of lights that Ronju must turn on 
manually before all the lights in the whole field gets lit up.

Sample Input                               Output for Sample Input
2
5 4
1 2
1 3
3 4
5 3

4 4
1 2
1 3
4 2
4 3

Case 1: 2
Case 2: 2
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

#define SIZE 10010
#define NILL -1
#define white 1
#define gray 2
#define black 3


vector<int>Dis(SIZE),Par(SIZE),Color(SIZE),Fin(SIZE),adj[SIZE],store;
int Time;

int DFS(int nodes);
void DFS_Visit(int u);

int main()
{
    int nodes,edges,i,u,v,count,Case=1,test;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&nodes,&edges);
        for(i=0;i<nodes;i++)
            adj[i].clear();
        for(i=0;i<edges;i++)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            adj[u].push_back(v);
        }
        for(i=0;i<nodes;i++)
            Color[i]=white;
        store.clear();
        for(i=0;i<nodes;i++)
        {
            if(Color[i]==white)
            {
                store.push_back(i);
                DFS_Visit(i);
            }
        }
        for(i=0;i<nodes;i++)
            Color[i]=white;
        count=0;
        for(i=store.size()-1;i>-1;i--)
        {
            if(Color[store[i]]==white)
            {
                count++;
                DFS_Visit(store[i]);
            }
        }
        printf("Case %d: %d\n",Case++,count);
    }
    return 0;
}

void DFS_Visit(int u)
{
    Color[u]=gray;      //White Vertex u Has just been Discovered
    Dis[u]=++Time;        //Discoverd u Vertex
    for(int i=0;i<adj[u].size();i++)
        if(Color[adj[u][i]]==white)
        {
            Par[adj[u][i]]=u;
            DFS_Visit(adj[u][i]);
        }
    Color[u]=black;     //Blacken u,it is finished
    Fin[u]=++Time;
}
