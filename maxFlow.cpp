#include<cstdio>
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define V 6
#define MAX 10000
int min(int a, int b)
{
    if(a<b) return a;
    return b;
}

bool bfs(int table[V][V], int s, int t, int parent[])
{
    bool visited[V]={false};
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v = 0;v<V;v++)
        {
            if(table[u][v]>0 && visited[v]==false)
            {
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return (visited[t]==true);
}
int fordFulkerson(int graph[V][V], int s, int t)
{
    int table[V][V];
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            table[i][j]=graph[i][j];
    int parent[V];
    int maxFlow =0;
    while(bfs(table, s, t, parent))
    {
        int pathflow =MAX;
        for(int v=t; v!=s; v=parent[v])
        {
            int u = parent[v];
            pathflow = min(pathflow, table[u][v]);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u = parent[v];
            table[u][v]-=pathflow;
            table[v][u]+=pathflow;
        }
        maxFlow+=pathflow;
    }
    return maxFlow;
}
int main()
{
    int graph[V][V] = { {0, 16, 13, 0, 0, 0},
                        {0, 0, 10, 12, 0, 0},
                        {0, 4, 0, 0, 14, 0},
                        {0, 0, 9, 0, 0, 20},
                        {0, 0, 0, 7, 0, 4},
                        {0, 0, 0, 0, 0, 0}
                      };

    printf("max flow is :%d ", fordFulkerson(graph, 0, 5));
}
