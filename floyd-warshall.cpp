#include<cstdio>
#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int graph[26][26]={0};
void topologicalSort(int i, int visited[], stack<int> &s)
{
        visited[i]=1;
        //printf("%c..",i+'a');
        for(int j=0;j<26;j++)
        {
           // printf("%d",graph[i][j]);
            if(graph[i][j]==1 && visited[j]==0)
            {
                //printf("%c..",j+'a');
                topologicalSort(j, visited, s);
            }

        }
        s.push(i);


}

void buildGraph(char s[][100], int n)
{
    int count =0;
    int fromedge[26]={0};
    for(int i=1;i<n;i++)
    {
        int k=0;
        while(s[i][k]==s[i-1][k] )
            k++;
        //printf("%c %c\n",s[i][k], s[i-1][k]);
        graph[s[i-1][k]-'a'][s[i][k]-'a']=1;
        fromedge[s[i-1][k]-'a']++;
        count++;
    }
   /* for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
            printf("%d",graph[i][j]);
        printf("\n");
    }
*/
    stack<int> st;
    int visited[26]={0};
    for(int i=0;i<26;i++)
    {
        if(visited[i]==0 && fromedge[i]!=0)
            topologicalSort(i, visited, st);
    }
    while(!st.empty())
    {
        printf("%c->",st.top()+'a');
        st.pop();
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    char c;
    scanf("%c",&c);
    char s[n][100];

    for(int i=0;i<n;i++)    scanf("%s%c",s[i],&c);
   // for(int i=0;i<n;i++) printf("%s\n",s[i]);
   buildGraph(s, n);

}
