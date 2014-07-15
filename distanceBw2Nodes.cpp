//distance between 2 given leaf nodes

#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
      struct Node* root = (struct Node*)malloc(sizeof(struct Node));
        root->data = data;
        root->left = root->right = NULL;
        return root;
}
void printPreOrder(struct Node* root)
{
    if(root==NULL) return;
    printPreOrder(root->left);
    printf("%d ",root->data);
    printPreOrder(root->right);
}
struct Node* findAncestor(struct Node* root, int k1, int k2, int &d1, int &d2, int &dist, int level)
{
    if(root==NULL) return NULL;
    if(root->data ==k1)
    {
        d1 = level;
        return root;
    }
    if(root->data ==k2)
    {
        d2= level;
        return root;
    }

    //this will give the position of k1 and k2
    Node* left = findAncestor(root->left, k1, k2, d1,d2,dist,level+1);
    Node* right = findAncestor(root->right, k1, k2, d1,d2,dist,level+1);

    if(left && right)
    {
        dist = d1+d2-2*level;
        return root;
    }
    return (left!=NULL)?left:right;
}

int findLevel(Node* root, int k, int level)
{
    if(root==NULL) return -1;
    if(root->data == k) return level;
    int l = findLevel(root->left, l , level+1);
    if(l==-1)
        return findLevel(root->right, k, level+1);
    else
        return l;
}
int findDistance(struct Node*root, int leaf1, int leaf2)
{
    int d1 = -1, d2 = -1, dist;
    Node*  ancestor = findAncestor(root, leaf1, leaf2, d1, d2, dist, 1);
    if(d1!=-1 && d2!=-1) return dist;
    if(d1!=-1)
    {
        dist = findLevel(ancestor, leaf1, 0);
        return dist;
    }
    if(d2!=-1)
    {
        dist = findLevel(ancestor, leaf2,0);
        return dist;
    }
    return -1;

}
int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    printPreOrder(root);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    return 0;
}
