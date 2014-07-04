#include<cstdio>
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
#define SIZE 100
int min(int a, int b)
{
    if(a<b) return a;
    return b;
}
int getminindex(int dist[], bool visited[], int size)
{
    int ans = INT_MAX, index =-1;
    for(int i=1;i<=size;i++)
        if(dist[i]<ans && visited[i]==false)
        {
            ans = dist[i];
            index = i;
        }
    return index;
}
void dijkstra(int mat[][SIZE+1])
{
    int start =1;
    int end = SIZE;
    int dist[SIZE+1]={INT_MAX};
    bool visited[SIZE+1]={false};
    int parent[SIZE+1]={-1};
    for(int i=0;i<=SIZE;i++)
    {
        dist[i]=INT_MAX;
        visited[i]=false;
        parent[i]=-1;
    }

    dist[start] =0;
    parent[start]=-1;
    for(int i=1;i<SIZE+1;i++)
    {
        int minindex = getminindex(dist,visited, SIZE  );
        for(int j=1;j<=SIZE;j++)
        {
            if(mat[minindex][j]==1 && visited[j]==false && dist[j] > dist[minindex]+1)
            {
                    dist[j]=dist[minindex]+1;
                    parent[j]=minindex;
            }

        }
       // printf("\n");
        visited[minindex]=true;
    }
    printf("%d\n",dist[SIZE]-1);
}
int main()
   {
    int t;scanf("%d",&t);
    while(t--)
        {
        int s, l;scanf("%d,%d",&l,&s);
        int st,e;
        int mat[SIZE+1][SIZE+1];
        //mat[1][1]=1;
        for(int i=1;i<SIZE+1;i++)
          {

            for(int j=1;j<SIZE+1;j++)
            {
                if(j==i+1 || j==i+2|| j==i+3||  j==i+4 ||  j==i+5|| j==i+6  )
                    mat[i][j]=1;
                else mat[i][j]=0;
            }

          }
        for(int i=0;i<l;i++)
            {
            scanf("%d,%d",&st,&e);
            //a[st]=e;
            mat[st][e]=1;

        }
        for(int i=0;i<s;i++)
            {
            scanf("%d,%d",&st,&e);
            mat[st][e]=-1;//ladder
        }
        dijkstra(mat);

    }
}

