#include<cstdio>
#include<stdlib.h>
#include<iostream>
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
void toDLL(struct node* root, struct node**head)
{
    static struct node* prev= NULL;
    if(root==NULL) return ;
    toDLL(root->left, head);
    if(prev==NULL) *head=root;
    else
    {
    prev->right = root;
    root->left = prev;
    }
    prev = root;
    toDLL(root->right,head);
}
void printList(struct node*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->val);
        head = head->right;
    }
}
void printInorder(struct node*root)
{
    if(root==NULL) return ;
    printInorder(root->left);
    printf("%d ",root->val);
    printInorder(root->right);
}
void postOrder(struct node* root)
{
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->val);
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


  printf("Inorder Traversal of the resultant tree is: \n");
  printInorder(root);
  printf("\n\n");
  postOrder(root);
  printf("\n\n");
  struct node* head = NULL;
  toDLL(root, &head);

  printList(head);

  
  return 0;
}
