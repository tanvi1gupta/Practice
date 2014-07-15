//find maximum in the given size of the window

#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d",&n,&k);
    int a[n], li[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    deque<int> q;
    for(int i=0;i<k;i++)
    {
        while(!q.empty() && a[i]>=a[q.back()])
        {
                q.pop_back();
        }
        q.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        printf("%d\n",a[q.front()]);
        if(!q.empty() && i-k >=q.front())
            q.pop_front();
        while(!q.empty() && a[i]>=a[q.back()])
        {
                q.pop_back();
        }
        q.push_back(i);
    }
     printf("%d\n",a[q.front()]);
}
