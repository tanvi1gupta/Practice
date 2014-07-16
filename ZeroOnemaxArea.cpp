#include<Cstdio>
#include<iostream>
#include<stack>
using namespace std;
/*
6 6
0 0 0 0 1 0
0 0 1 0 0 1
0 0 0 0 0 0
1 0 0 0 0 0
0 0 0 0 0 1
0 0 1 0 0 0
*/
int a[10][10];
int f[10][10];
int getArea(int r, int c)
{
    stack<int>s;
    int i=0, area, maxarea =-1;

    while(i<c)
    {
        if(s.empty() || f[r][s.top()] <=f[r][i])
            s.push(i++);
        else
        {
            int index = s.top();s.pop();
            if(s.empty())
                area = f[r][index]*i;
            else
                area =f[r][index]*(i-s.top()-1);
            if(area > maxarea)
                maxarea = area;
        }
    }
    while(!s.empty())
    {
        int index = s.top();s.pop();
        if(s.empty())
              area = f[r][index]*i;
        else
             area =f[r][index]*(i-s.top()-1);
        if(area > maxarea)
               maxarea = area;
    }
    printf("%d\n", maxarea);
    return maxarea;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
    //int f[n][m];
    for(int i=0;i<m;i++)
    {
       if(a[0][i]==0)
            f[0][i]=1;
      else f[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
                f[i][j]=f[i-1][j]+1;
            else f[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            printf("%d ",f[i][j]);
        printf("\n");
    }

    int maxarea =0;
   // stack<int> s;
    //start from last row
    for(int i=n-1;i>=0;i--)
    {
        int area = getArea(i, m);
        if(area>maxarea)
            maxarea =area;
    }
    printf("%d\n",maxarea);

}
