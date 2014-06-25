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
void printPostOrder(struct node* root)
{
    if(root==NULL) return;

    printPostOrder(root->left);
    printPostOrder(root->right);
     printf("%d ",root->data);
}
node *contructTreePostorder(int a[], int s, int n, int size)
{
    if(s>n) return NULL;

    struct node* root = newnode(a[n]);
    if(s==n) return root;
    int i;
    //to find the right side of the tree
    for( i=s;i<=n;i++ )
        if(a[i] > root->data)
            break;
    root->left = contructTreePostorder(a, s, i-1 , size);
    root->right = contructTreePostorder(a, i, n-1, size);
    return root;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int preindex = n-1;
    struct node* root = contructTreePostorder(a,0, n-1, n);
    printInOrder(root);
    printf("\n");
    printPreOrder(root);
    printf("\n");
      printPostOrder(root);
    printf("\n");
}


