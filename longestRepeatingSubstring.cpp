#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct node
{
    char *str;
    int index;
};
int cmp(struct node a , struct node b)
{
    return strcmp(a.str, b.str)<0?1:0;
}
void buildSuffixArray(char *s)
{
    int len = strlen(s);
    struct node suffix[len];
    //build suffix tree
    for(int i=0;i<len;i++)
    {
        suffix[i].index =i;
        suffix[i].str = (s+i);
    }
    sort(suffix, suffix+len, cmp);
  /*  for(int i=0;i<len;i++)
        printf("%d %s\n",suffix[i].index, suffix[i].str);*/
    int longest = 0;
    int index = 0;
    for(int i=1;i<len;i++)
    {
        int match =0;
        for(; match < min(strlen(suffix[i].str), strlen(suffix[i-1].str)); match++)
        {
            if(suffix[i].str[match] != suffix[i-1].str[match])
                break;
        }
        if(match > longest)
        {
            longest = match;
            index =i-1;
        }
    }
    printf("\n%d %s\n",longest, suffix[index].str);
}
int main()
{
    char s[100];
    scanf("%[^\n]",s);
    int len = strlen(s);
   buildSuffixArray(s);

}
