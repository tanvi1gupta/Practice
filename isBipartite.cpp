//check whether the graph is a bipartite grpah or not
//2 colorable

#include <iostream>
#include <queue>
#define V 4
using namespace std;
bool isBipartite(int g[][V], int s)
{
    int color[V];
    for(int i=0;i<V;i++) color[i]=-1;
    queue<int> q;
    q.push(s);
    color[s]=0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0;v<V;v++)
        {
            if(g[u][v] && color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else if(g[u][v] && color[v]==color[u]) return false;
        }

    }
    return true;
}
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    isBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
}
