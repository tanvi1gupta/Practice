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
node* getmax(struct node* root)
{
    while(root->right!=NULL)
        root = root->right;
    return root;
}
node* getPredessor(struct node* root, int data, struct node* parent)
{
    if(root==NULL) return NULL;
    if(root->data ==data)
    {
        if(root->left)
            return getmax(root->left);
        else
            return parent;
    }
    if(root->data < data)
        return getPredessor(root->right, data, root);
    else return getPredessor(root->left, data, root);
}
void predessor(struct node* root, int data)
{
    struct node* pre = getPredessor(root, data, NULL);
    printf("predessor of %d is:%d\n",data,pre->data);

}
int main()
{
    struct node* root = NULL;
    root= insertTree(7, root);
    insertTree(3, root);
    insertTree(9, root);
    insertTree(2, root);
    insertTree(1, root);
    insertTree(5, root);
    insertTree(4, root);
    insertTree(6, root);
    insertTree(8, root);
    insertTree(11, root);
    insertTree(10, root);
    insertTree(12, root);
    struct node* head=NULL;
    printPreOrder(root);
    printf("\n");
    predessor(root, 7);
    predessor(root, 6);
    predessor(root, 5);
    predessor(root, 3);
    predessor(root, 9);
    predessor(root, 12);

    return 0;
}
