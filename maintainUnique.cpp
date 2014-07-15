//maintain unique element using trie

#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
struct node
{

    struct node* next[26];
    bool isword ;
    bool isdelete ;
};
node* newnode()
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->isword = false;
    root->isdelete = false;
    for(int i=0;i<26;i++)
        root->next[i]=NULL;
    return root;
}
int words =0;
node* searchNode(struct node* root, char key[])
{
    int len = strlen(key);
    for(int i=0;i<len;i++)
    {
        int index = key[i]-'a';
        if(!root->next[index])
        {
          // printf("%s not present\n", key);
           return NULL;
        }
        root  = root->next[index];
        if(i==len-1 && root->isword==true && root->isdelete==false)
            return root;

    }
    return NULL;
}
void insertNode(struct node* root, char key[])
{
  //  printf("%s\n",key);
    struct node* findNode = searchNode(root, key);
    if(findNode==NULL)
    {
      //  printf("in uf\n");
        int len = strlen(key);
       // printf("%s %d\n",key, len);
        for(int i=0;i<len;i++)
        {
            int index = key[i]-'a';
            if(!root->next[index])
            {
                root->next[index]= newnode();
            }
            root  = root->next[index];
            if(i==len-1)
               {
                 root->isword = true;
                // return;
               }
        }
      //  printf("done\n");
        return;

    }
    else
    {
      //  printf("in else\n");
        findNode->isdelete=true;
        return;
    }

}

void printNode(struct node* root, char str[], int len)
{
    //printf()
    if(root==NULL ) return ;
    if(root && root->isdelete==false && root->isword==true)
    {
        str[len]='\0';
        printf("%s ",str);
    }
    for(int i=0;i<26;i++)
    {
        if(root->next[i])
        {
            str[len]=i+'a';
           // printf("%s\n",str);
            printNode(root->next[i], str, len+1);
        }
    }

}
void printNodes(struct node* root)
{
    if(root==NULL) return ;
    char key[10];
    printNode(root, key,0);
}
int main()
{
    char keys[][11] = {"the", "a", "there", "a","answer", "any", "by", "bye", "their","their","a"};
    struct node* root = newnode();

    for(int i=0;i<11;i++)
    {
        insertNode(root, keys[i]);
        printNodes(root);
        printf("\n");
    }
 //   printf("%d\n",searchNode(root, "an"));
  //  printf("%d\n",searchNode(root, "any"));

}
