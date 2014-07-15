#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
node* newnode(int data)
{
        struct node* root = (struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
}

void printInOrder(struct node* root)
{
    if(root==NULL) return;
    printInOrder(root->left);
    printf("%d ",root->data);
    printInOrder(root->right);
}
void printPreOrder(struct node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}
int searchIndex(int in[], int s, int n,int data)
{
    for(int i=s;i<=n;i++)
        if(in[i]==data) return i;
    return -1;
}
 node* contructTree(int in[], int pre[], int s, int n, int *preindex)
{
    if(s>n) return NULL;
    struct node* root = newnode(pre[(*preindex)++]);
    if(s==n) return root;
    int inIndex = searchIndex(in, s,n,root->data);
    root->left = contructTree(in, pre, s, inIndex-1, preindex);
    root->right = contructTree(in, pre, inIndex+1, n, preindex);
    return root;

}
int main()
{
    int n;
    scanf("%d",&n);
    int in[n],pre[n];
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&pre[i]);
    int preindex = 0;
    struct node* root = contructTree(in,pre,0, n-1, &preindex);
    printInOrder(root);
    printf("\n");
    printPreOrder(root);
    printf("\n");
}
