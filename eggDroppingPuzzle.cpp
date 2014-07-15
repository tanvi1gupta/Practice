#include<cstdio>
#include<iostream>
#include<limits.h>
using namespace std;
int max(int a, int b)
{
    if(a>b) return a;
    return b;
}

int getcount(int e, int f)
{
    int table[e+1][f+1];
    //if one egg then start throwing egg from 1st floor and go up
    for(int i=1;i<=f;i++)
    {
        table[1][i]=i;
    }
    //if 0 floor then 0..if 1 floor then 1 attemp
    for(int i=1;i<=e;i++)
    {
        table[i][0]=0;
        table[i][1]=1;
    }

    for(int i=2;i<=e;i++)
    {
        for(int j=2;j<=f;j++)
        {
            table[i][j]=INT_MAX;
            for(int k=1;k<=j;k++)
            {
                //2 possibilities-> egg breaks at floor k then i-1 eggs left and start from throw for k-1 floors,
                // egg does not break then egg will break when thrown from any floor greater than k but less than j
                int res = 1+ max(table[i][j-k], table[i-1][k-1]);
                if(res < table[i][j]) table[i][j]=res;
            }
        }
    }
    return

    table[e][f];
}

int main()
{
    int egg, floor;
    scanf("%d%d",&egg,&floor);
    printf("%d\n",getcount(egg,floor));
    return 0;
}
