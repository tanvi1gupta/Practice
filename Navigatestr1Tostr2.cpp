#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int mat[26][26]={{0}};
bool dfs(char a, char b)
{
    for(int i=0;i<26;i++)
    {

        if(i+'a'==b && mat[a-'a'][i])
        {
            return true;
        }
        else if(mat[a-'a'][i])
            return dfs(a, i+'a');
    }
    return false;
}
int main()
{
    char a[100], b[1000];
    scanf("%s %s",a,b);
    int len1 = strlen(a);
    int len2 = strlen(b);
    if(len1!=len2)
    {
        printf("not possible\n");
    }
    else
    {

        for(int i=0;i<len1-1;i++)
        {
            mat[a[i]-'a'][a[i+1]-'a']=1;
            mat[a[i+1]-'a'][a[i]-'a']=1;
        }

        for(int i=0;i<len2-1;i++)
        {
            mat[b[i]-'a'][b[i+1]-'a']=1;
            mat[b[i+1]-'a'][b[i]-'a']=1;
        }
      /*  for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                printf("%d ",mat[i][j]);
            }
            printf("\n");
        }*/
        for(int i=0;i<len1;i++)
        {
            if(a[i]!=b[i])
            {
                   if( dfs(a[i], b[i]))
                    {
                        a[i]=b[i];
                        printf("%s->",a);
                    }
            }
        }
    }

}
