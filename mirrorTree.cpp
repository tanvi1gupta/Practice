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
struct node* insertTree(int data, struct node* root)
{
    if(root==NULL)
    {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    if(data < root->data)
    {
        root->left = insertTree(data, root->left);
    }
    else
    {
        root->right = insertTree(data, root->right);
    }
}

void printPreOrder(struct node* root)
{
    if(root==NULL) return;
    printPreOrder(root->left);
    printf("%d ",root->data);
    printPreOrder(root->right);
}

node* mirrorTree(struct node* root)
{
    if(root==NULL) return NULL;
    struct node* temp = root->left;
    root->left  = root->right;
    root->right = temp;
    root->left = mirrorTree(root->left);
    root->right = mirrorTree(root->right);
    return root;
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
    mirrorTree(root);
    printPreOrder(root);
    return 0;
}
