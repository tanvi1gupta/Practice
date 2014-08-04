#include<cstdio>
#include<iostream>
#include<limits.h>
using namespace std;
//int graph[9][9];
int minDistance(int dist[], bool visited[], int v)
{
    int min    =INT_MAX , min_index;
    for(int i=0;i<v;i++)
    {
        if(dist[i]<=min && !visited[i])
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[][9], int start, int v)
{
    int dist[v],parent[v];
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        dist[i]=INT_MAX;
        visited[i]= false;
        parent[v]=-1;
    }
    dist[start]=0;
    parent[start]=-1;
    for(int i=0;i<v-1;i++)
    {
        int u = minDistance(dist, visited, v);
        visited[u]=true;
        for(int j=0;j<v;j++)
        {
            if(visited[j]==false && graph[u][j]!=0 && dist[u]+graph[u][j] < dist[j])
            {
                dist[j] = dist[u]+graph[u][j];
                parent[j]=u;
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        printf("%d\tdist:%d\tparent:%d\n",i, dist[i], parent[i]);
    }
}
int main()
{
    int v= 9;
    int graph[9][9] =     {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    dijkstra(graph, 0, v);
}
