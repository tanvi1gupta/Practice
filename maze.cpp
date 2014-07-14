#include<cstdio>
#include<iostream>
using namespace std;
/*
4 4
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
*/
int main()
{

    int n,m;
    scanf("%d%d",&n,&m);
    int table[n][m], dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&table[i][j]);
            dp[i][j]=0;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {

                if(i==0 && j==0 && table[i][j]==1) dp[i][j]=1 ;
                else if(table[i][j]==1)
                {

                     dp[i][j]=dp[i-1][j]||dp[i][j-1];

                }
                else
                    dp[i][j]=0;
            }
        }

        if(dp[n-1][m-1])
            printf("can reach the end\n");
        else printf("cannot reach\n");

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",dp[i][j]);
            printf("\n");
        }


}
