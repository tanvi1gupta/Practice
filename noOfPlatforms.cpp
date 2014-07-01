#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
struct sch
{
    int start;
    int end;
};
bool cmp(sch a, sch b)
{
    if(a.end < b.end) return 1;
    else if(a.end==b.end)
    {
        if(a.start > b.start) return 1;
        else return 0;
    }
    return 0;
}

void getPlatforms(sch s[], int n)
{
    int e[n];
    for(int i=0;i<n;i++) e[i]=-1;
    int k=0;
    int j=0, count =1;
    for(int i=1;i<n;i++)
    {
       // printf("%d %d\n",s[i].start , s[j].end );
        if(s[i].start > s[j].end)
        {
            j=i;
        }
        else if(k==0)
        {
                count++;
                e[k++]=i;
        }
        else
        {
            int flag =0;
            for(int m=0;m<k;m++)
            {
                if(s[i].start > s[e[m]].end)
                {
                    flag =1;
                    e[m]=i;
                }
            }
            if(flag==0) {
                    e[k++]=i;
                    count++;
            }
        }
    }
    printf("%d\n", count);
}
int main()
{
    int n;
    scanf("%d",&n);
    struct sch s[n];
    for(int i =0;i<n;i++)
    {
        scanf("%d %d",&s[i].start, &s[i].end);
    }
    sort(s, s+n, cmp);
   /* for(int i=0;i<n;i++)
        printf("%d %d\n",s[i].start, s[i].end);*/
    getPlatforms(s, n);
}
