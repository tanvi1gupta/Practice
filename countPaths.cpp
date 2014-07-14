#include<cstdio>
#include<iostream>
using namespace std;
/*
7 7
0 0 1 0 0 1 0
1 0 1 1 0 0 0
0 0 0 0 1 0 1
1 0 1 0 0 0 0
1 0 1 1 0 1 0
1 0 0 0 0 1 0
1 1 1 1 0 0 0
*/

int count =0;
int table[100][100];
void DFS(int i, int j, int n,int m)
{
    if(i==n-1 && j==m-1)
    {
        count++;
        return;
    }
    table[i][j]=1;
    if(j+1<n && table[i][j+1]==0) DFS(i, j+1,n,m);
    if(i+1<n && table[i+1][j]==0) DFS(i+1, j,n,m);
    if(j-1>=0 && table[i][j-1]==0) DFS(i, j-1,n,m);
    if(i-1>=0 && table[i-1][j]==0) DFS(i-1, j,n,m);
    table[i][j]=0;
}
int main()
{

    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&table[i][j]);
          //  dp[i][j]=0;
        }

        /*dp[0][0]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if(i==0 && j==0) dp[i][j]=1;
                dp[i][j]=1;
                if(j+1<n && table[i][j+1]==0) dp[i][j]+=1;
                if(i+1<n && table[i+1][j]==0) dp[i][j]+=1;
                if(j-1>=0 && table[i][j-1]==0) dp[i][j]+=1;
                if(i-1>=0 && table[i-1][j]==0) dp[i][j]+=1;

            }
        }*/
        DFS(0,0,n,m);

        printf("%d\n",count);

}

