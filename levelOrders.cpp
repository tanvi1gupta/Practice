
//this code printslevel order of the tree, zig zag level order and bottom up level order

#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
struct node
{
    int val;
    struct node*right;
    struct node*left;

};
struct node* newNode(int n)
{
    struct node *tmp= (struct node*)malloc(sizeof(struct node));
    tmp->val= n;
    tmp->left=tmp->right=NULL;
    return tmp;
}
void printInorder(struct node*root)
{
    if(root==NULL) return ;
    printInorder(root->left);
    printf("%d ",root->val);
    printInorder(root->right);
}
void levelOrder(struct node*root)
{
    if(root==NULL) return ;
    queue<struct node*>q;
    q.push(root);
    int curr=1, next=0;
    while(!q.empty())
    {
        struct node* temp = q.front();
        q.pop();
        printf("%d ", temp->val);
        curr--;
        if(temp->left)
        {
            q.push(temp->left);
            next++;
        }
        if(temp->right)
        {
            q.push(temp->right);
            next++;
        }
        if(curr==0)
        {
            printf("\n");
            curr=next;
            next =0;
        }
    }
}
void levelOrderZigZag(struct node* root)
{
    if(root==NULL) return ;
    stack<struct node*>s1, s2;
    s1.push(root);
    bool ltoR=true;
    while(!s1.empty() || !s2.empty())
    {
        struct node* temp = s1.top();
        s1.pop();
        printf("%d ",temp->val);
        if(ltoR)
        {
            if(temp->left)
            {
                s2.push(temp->left);
            }
            if(temp->right)
            {
                s2.push(temp->right);
            }
        }
        else if(!ltoR)
        {
            if(temp->right)
            {
                s2.push(temp->right);
            }
            if(temp->left)
            {
                s2.push(temp->left);
            }
        }
        if(s1.empty())
        {
            printf("\n");
            ltoR=!ltoR;
            swap(s1,s2);
        }

    }
}
void levelOrderBottomUp(struct node* root)
{
    if(root==NULL) return ;
    queue<struct node*> q;
    stack<struct node*>s;
    q.push(root);
    int a[100]={0};
    a[0]+=1;
    int level =1;
    int count = a[0];
    while(!q.empty())
    {

        struct node* temp = q.front();
        count--;
        q.pop();
        s.push(temp);
        if(temp->right)
        {
            q.push(temp->right);
            a[level]++;
        }
        if(temp->left)
        {
            q.push(temp->left);
            a[level]++;
        }
        if(count==0)
        {
            count = a[level];
            level++;
        }

    }
    for(int i=0;i<level-1;i++)
    {
        for(int j=0;j<a[level-2-i];j++)
        {
            struct node* temp= s.top();
            printf("%d ",temp->val);
            s.pop();
        }
       printf("\n");
    }
}
int main()
{
  struct node *root = NULL;
  int x;
 /* Constructing tree given in the above figure */
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
  root->right->right->left = newNode(11);
  root->right->left->left = newNode(15);

printf("\nlevel order:\n");
  levelOrder(root);
 // printf("Inorder Traversal of the resultant tree is: \n");
  //printInorder(root);

  printf("\nlevel order zig zag:\n");
  levelOrderZigZag(root);

  printf("\nlevelorder bottom up:\n");
  levelOrderBottomUp(root);
  return 0;
}
