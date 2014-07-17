#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data, ht;
    struct node* left;
    struct node* right;
};
struct node* newnode(int data)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data =data;
    t->ht=1;
    t->left = t->right = NULL;
    return t;
}
int max(int a, int b)
{
    if(a>b) return a;
    return b;
}
int height(struct node*t)
{
    if(t==NULL) return 0;
    return t->ht;
}
int getBalance(struct node* root)
{
    if(root==NULL) return 0;
    return (height(root->left)- height(root->right));

}
node* rightRotate(struct node* x)
{
    struct node*y=x->left;
    struct node*T2=y->right;
    y->right = x;
    x->left = T2;
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;
    return y;

}
struct node* leftRotate(struct node* x)
{
    struct node*y=x->right;
    struct node*T2=y->left;
    y->left = x;
    x->right=T2;
    x->ht = max(height(x->left), height(x->right))+1;
    y->ht = max(height(y->left), height(y->right))+1;
    return y;
}

struct node* insert(struct node*root, int data)
{
    if(root==NULL){
            return newnode(data);
    }
    if(data < root->data)
        root->left = insert( root->left, data);
    else
        root->right = insert( root->right, data);
    root->ht = max(height(root->left), height(root->right))+1;
    int balance = getBalance(root);
    if(balance>1 && data < root->left->data)
    {
        return rightRotate(root);
   }
    if(balance<-1 && data > root->right->data)
    {
        return leftRotate(root);
    }
    if(balance >1 && data >root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && data <root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct node*minvaluenode(struct node*root)
{
    while(root->left)
        root = root->left;
    return root;
}
void preorder(struct node*root)
{
    if(root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}
struct node* deletenode(struct node* root, int data)
{
        if(root==NULL) return NULL;
        if(data <root->data)
            root->left = deletenode(root->left, data);
        else if(data>root->data)
            root->right = deletenode(root->right, data);
        else
        {
            //found the data
            if(root->left==NULL || root->right ==NULL)
            {
                struct node* t = root->left?root->left:root->right;
                if(t==NULL)
                {
                    t=root;
                    root=NULL;
                }
                else
                {
                    *root=*t;
                }

                free(t);

            }
            //we have both children
            else
            {
                struct node* t = minvaluenode(root->right);
                root->data=t->data;
                root->right = deletenode(root->right, t->data);
            }
        }

    if(root==NULL) return NULL;
    root->ht = max(height(root->left), height(root->right))+1;
    int balance = getBalance(root);
    if(balance>1 && getBalance(root->left)>=0)
    {
        return rightRotate(root);
    }
    if(balance<-1 && getBalance(root->right)<=0)
    {
        return leftRotate(root);
    }
    if(balance >1 && getBalance(root->left)<0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance<-1 && getBalance(root->right)>0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;


}
int main()
{
    struct node* root=NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
    preorder(root);
    printf("\n\n");
    root=deletenode(root, 9);
    preorder(root);
}
