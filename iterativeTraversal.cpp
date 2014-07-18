//this code is to show how to implement inorder , preorder iterative
//http://www.leetcode.com/2010/10/binary-tree-post-order-traversal.html
//http://www.leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node*right;
    bool visited;
};
struct node* newNode(int n)
{
    struct node* tmp =(struct node*)malloc(sizeof(struct node));
    tmp->data = n ;
    tmp->visited=false;
    tmp->left = tmp->right = NULL;
    return tmp;
}
void iterativeInorder(struct node*root)
{
    if(root==NULL) return ;
    stack <struct node*>s;
    s.push(root);
    while(!s.empty())
    {
        struct node* tmp = s.top();
        if(tmp)
        {
            if(tmp->visited==false)
            {
                s.push(tmp->left);
            }
            else
            {
                printf("%d ",tmp->data);
                s.pop();
                s.push(tmp->right);
            }
        }
        else
        {
            s.pop();
            if(!s.empty())
                s.top()->visited=true;
        }
    }
}
void iterativePreorder(struct node*root)
{
    if(root==NULL)
        return ;
    stack<struct node*> s;
    s.push(root);
    while(!s.empty())
    {
        struct node* tmp = s.top();
        s.pop();
        printf("%d ",tmp->data);
        if(tmp->right)
            s.push(tmp->right);
        if(tmp->left)
            s.push(tmp->left);
    }

}

void iterativePostorder(struct node* root)
{
    if(root==NULL) return ;
    stack<struct node*> s;
    s.push(root);
    struct node* prev = NULL;
    while(!s.empty())
    {
        struct node* curr = s.top();
        //we are gng down the tree
        if(!prev || prev->left == curr || prev->right==curr)
        {
            if(curr->left)
                s.push(curr->left);
            else if (curr->right)
                s.push(curr->right);
            else
            {
                printf("%d ",curr->data);
                s.pop();
            }
        }
        //moving up from left
        else if (curr->left == prev)
        {
            if(curr->right)
                s.push(curr->right);
            else
            {
                printf("%d ",curr->data);
                s.pop();
            }

        }
        //coming up from right this means left n right nodes are visited
        else if (curr->right==prev)
        {
            printf("%d ",curr->data);
            s.pop();
        }
        prev = curr;

    }
}
void inorder2(struct node* root)
{
    if(root==NULL) return ;
    stack<struct node*> s;
    bool flag = false;
    struct node* curr= root;
    while(!flag)
    {
        if(curr)
        {
            s.push(curr);
            curr=curr->left;
        }
        else
        {
            if(s.empty())
                flag = true;
            else
            {
                curr =s.top();
                s.pop();
                printf("%d ",curr->data);
                curr=curr->right;
            }
        }

    }
}
void iterativePostorder2(struct node* r)
{
    if(r==NULL) return ;
    stck<struct node*>s;
}
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      12
      /  \    /
    3     9  11
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(12);
  root->left->left  = newNode(3);
  root->left->right = newNode(9);
  root->right->left = newNode(11);
  printf("InordeR:  ");
  iterativeInorder(root);
  printf("\n\nInordeR2: ");
  inorder2(root);

  printf("\n\nPreorder: ");
  iterativePreorder(root);
  printf("\n\nPostorder:");
  iterativePostorder(root);
  printf("\n\n");
  iterativePostorder2(root);
  return 0;
}


