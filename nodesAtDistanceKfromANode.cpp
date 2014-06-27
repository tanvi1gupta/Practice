//nodes at dostance k from all the leaf nodes..
//store all the ancestors recursively and whenevr u get a leaf node..print the ancestor at the distance k

#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;
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
//1 3 4 6 7 8 10 12 13 14
void findKNode(struct node* root, int k)
{
    if(root==NULL || k<0) return ;
    if(k==0 ){
            printf("%d\n", root->data);
            return ;
    }
    findKNode(root->left, k-1);
    findKNode(root->right, k-1);
}
int nodesAtdistance(struct node* root, int data, int k)
{
    if(root==NULL) return 0;
    if(root->data == data)
    {
        findKNode(root->left, k-1);
        findKNode(root->right, k-1);
        return 1;
    }
    int l = nodesAtdistance(root->left, data, k);
    int r = nodesAtdistance(root->right, data, k);
   if(l==k || r ==k)
   {
       printf("%d\n", root->data);
   }
   if(l<k && l>0)
   {
       findKNode(root->right, k-l-1);
       return l+1;
   }
   if(r<k && r>0)
   {
       findKNode(root->left, k-r-1);
       return r+1;
   }
    return 0;
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
    insertTree(12, root);
    printPreOrder(root);
    printf("\n");
    nodesAtdistance(root, 3, 1);
    return 0;
}
