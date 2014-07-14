#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
#define editCost 1
int min(int a, int b)
{
    if(a>b) return b;
    return a;
}
void editDistance(char *x, char *y)
{
    int len1 = strlen(x)+1;
    int len2 = strlen(y)+1;
    int table[len1][len2];
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
            table[i][j]=-1;
    for(int i=0;i<len1;i++)
        table[i][0]=i;
    for(int i=0;i<len2;i++)
        table[0][i]=i;

    for(int i=1;i<len1;i++)
    {
        for(int j=1;j<len2;j++)
        {
            int left = table[i-1][j]+1;
            int right = table[i][j-1]+1;
            int shift  = table[i-1][j-1];
           if(x[i-1]==y[j-1])
            shift +=0;
            else
                shift += 1;
            table[i][j]=min(min(left, right), shift);
        }
    }
    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<len2;j++)
            printf("%d ",table[i][j]);
        printf("\n");
    }
    printf("%d\n", table[len1-1][len2-1]);
}
int main()
{
    char x[] = "SUNDAY";
    char y[] = "SATURDAY";
    editDistance(x,y);
}
