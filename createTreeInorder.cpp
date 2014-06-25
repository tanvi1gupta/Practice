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
node *contructTree(int a[], int s, int n)
{
    if(s>n) return NULL;
    int mid = (s+n)/2;
    struct node* root = newnode(a[mid]);
    root->left = contructTree(a, s, mid-1);
    root->right = contructTree(a, mid+1, n);
    return root;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    struct node* root = contructTree(a,0, n-1);
    printf("%d\n", root->data);
    printInOrder(root);
    printf("\n");
    printPreOrder(root);
    printf("\n");
}
