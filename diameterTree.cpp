//http://www.geeksforgeeks.org/archives/5687
//diamter of a tree--> longets path from one leaf node to another
//3 cases
//1. left diameter
//2. right diameter
//3. left ht + rht +1 i.e. through the root of the node..
#include<cstdio>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
   int data;
   struct node* left;
   struct node* right;
};
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
int max (int a , int b)
{
    if(a>b) return a;
    else return b;
}
int height(struct node*root)
{
    if(root==NULL) return 0;
    int rheight = height(root->right);
    int lheight = height(root->left);
    if(rheight>lheight)
        return (rheight+1);
    else    return (lheight+1);
}
int diameter(struct node*root)
{
    //diameter is the longest path between one leaf node to another
    //1. left height+right height+1 i.e through the root node
    //2. not through the root node i..e with in a sub tree
    if(root==NULL) return 0;
    int lht = height(root->left);
    int rht = height(root->right);
    int rdiamter = diameter(root->right);
    int ldiamter = diameter(root->left);

    return max(lht+rht+1,max(rdiamter,ldiamter));

}
int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);

  printf("Diameter of the given binary tree is %d\n", diameter(root));

  getchar();
  return 0;
}
