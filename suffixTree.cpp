#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
#define SIZE 26
struct node{
    bool isword;
    struct node* next[SIZE];
};
node* newnode()
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->isword = false;
    for(int i=0;i<SIZE;i++)
        root->next[i]=NULL;
        return root;
}
void insertnode(struct node* root, char *a, int start, int len)
{
   // printf("%s ",a);
    for(int i=start;i<len;i++)
    {
       // printf("%c", a[i]);
        int index = a[i]-'a';
        if(root->next[index]==NULL)
        {
            root->next[index]= newnode();
        }
        root = root->next[index];
        if(i==len-1)
            root->isword=true;
    }
}
void print(struct node* root, char *s, int pos)
{
    if(root==NULL) return ;
    if(root->isword==true) {
        s[pos]='\0';
        printf("%s\n",s);
    }

    for(int i=0;i<SIZE;i++)
    {
        if(root->next[i])
        {
            s[pos]=i+'a';
            print(root->next[i], s, pos+1);
        }
    }
}
void buildSuffixArray(char *s)
{
    int len = strlen(s);
    struct node* root = NULL;
    root = newnode();
    for(int i=0;i<len;i++)
        insertnode(root, s, i, len);
    char s2[len];
    print(root, s2, 0);
}
int main()
{
    char s[100];
    scanf("%[^\n]",s);
    int len = strlen(s);
   buildSuffixArray(s);
}
