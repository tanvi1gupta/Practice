// to print the right view of the tree



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
void rightViewUtil(struct node* root, int level, int*max_level)
{
    if(root==NULL) return ;
    if(*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

void rightView(struct node* root)
{
    if(root==NULL ) return ;
    int max_level=0;
    return rightViewUtil(root, 1, &max_level);
}
void leftViewUtil(struct node* root, int level , int *max_level)
{
    if(root==NULL) return ;
    if(*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }
     leftViewUtil(root->left, level+1, max_level);
     leftViewUtil(root->right, level+1, max_level);
}
void leftView(struct node* root)
{
    int max_level = 0;
    return leftViewUtil(root, 1, &max_level);
}

int main()
{
    struct node* root = NULL;
    /*root= insertTree(8, root);
    insertTree(3, root);
    insertTree(10, root);
    insertTree(1, root);
    insertTree(6, root);
    insertTree(4, root);
    insertTree(7, root);
    insertTree(14, root);
    insertTree(13, root);
    insertTree(12, root);*/

    root= insertTree(12, root);
    insertTree(13, root);
    insertTree(14, root);
    insertTree(7, root);
    insertTree(8, root);
    insertTree(10, root);
    insertTree(9, root);
    insertTree(11, root);
    insertTree(12, root);
    insertTree(2, root);

    insertTree(6, root);
    insertTree(4, root);
    insertTree(5, root);
    insertTree(3, root);
    insertTree(1, root);
    //printPreOrder(root);

printf("\nright view: ");
    rightView(root);
    printf("\nleft view: ");
    leftView(root);
    return 0;
}



