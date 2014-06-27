//longest non repeating sunstring
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char s[200];
    scanf("%[^\n]",s);
    int len = strlen(s);
    int visited[256];
    for(int i=0;i<256;i++)visited[i]=-1;
    visited[s[0]]=0;
    int max_len = 0,  prev = 0,cur=0, start=0;
    printf("%d\n",len);
    for(int i=1;i<len;i++)
    {
        prev = visited[s[i]];
        if(prev==-1 || i-cur > prev)
            cur++;
        else
        {
            if(cur>max_len)
            {
                max_len=cur;
                start =prev;
            }

            cur = i-prev;

        }
        visited[s[i]]=i;
    }
    printf("%d %d ",max_len,start);
    if(cur>max_len)
        max_len = cur;
    for(int i=start ;i<=start+max_len-1;i++)
        printf("%c",s[i]);

}
