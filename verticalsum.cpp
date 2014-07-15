//to find the vertical sum of a tree
#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
int hdMax =0;
int hdMin=100;
struct node{
    int data;
    struct node* left;
    struct node* right;
    int hd;
};

node* insertNode(int data, struct node* root, int hd)
{
    if(root==NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->hd = hd;
        if(hd>hdMax)
            hdMax = hd;
        if(hd<hdMin)
                hdMin=hd;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data)
    {
        root->left = insertNode(data, root->left, hd-1);
    }
    else
    {
        root->right = insertNode(data, root->right , hd+1);
    }
}
struct node* insertTree(int data, struct node* root)
{
    return insertNode(data, root, 0);
}
void printPreOrder(struct node* root)
{
    if(root==NULL) return;
    printPreOrder(root->left);
    printf("%d ",root->data);
    printPreOrder(root->right);
}
int a[100]={0};
void getSum(struct node* root)
{
    if(root==NULL) return ;
   // printf("%d %d %d\n",a[root->hd-hdMin], root->data, root->hd );
    a[root->hd-hdMin]+=root->data;
    getSum(root->left);
    getSum(root->right);
}
int main()
{
     struct node* root = NULL;
    root= insertTree(8, root);
    insertTree(3, root);
    insertTree(10, root);
    insertTree(1, root);
    insertTree(6, root);
    insertTree(4, root);
    insertTree(7, root);
    insertTree(14, root);
    insertTree(13, root);
    struct node* head=NULL;
    printPreOrder(root);
    printf("\n");
    printf("%d\n\n",hdMax);
    getSum(root);
    for(int i=0;i<=hdMax-hdMin;i++)
        printf("%d ",a[i]);
    return 0;
}
