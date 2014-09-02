#include<iostream>
#include<cstdio>
#include<queue>
#include<stdlib.h>
#include<vector>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* right;
    struct Node*down;
}Node;

void push(Node **head , int data)
{
    Node * newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->down =(*head);
    newnode->right = NULL;
    (*head) = newnode;
}

void printList(Node * a)
{

    while(a!=NULL)
    {
       printf("%d ",a->data);
        a = a->down;

    }
}
//need lowest value @head
struct CompareValue
{

    bool operator()(Node* const &n1, Node* const &n2)
    {
        return n1->data > n2->data;
    }
};
Node * flatten(Node *node)
{
    priority_queue<Node*, vector<Node*>, CompareValue> pq;
    pq.push(node);
    Node * result=NULL , *tmp,*res;
    while(!pq.empty())
    {

        tmp = pq.top();
        printf("top->%d ",tmp->data);
        if(tmp->down!=NULL){
          pq.push(tmp->down);
         // printf("down-> %d ",tmp->down->data);
        }
        if(tmp->right!=NULL) {
                pq.push(tmp->right);
        //printf("right->%d",tmp->right->data);
        }
        printf("\n");
        if(result==NULL)
        {

            result = tmp;
            res=result;
            result->down=NULL;
        }

        else
            {
                result->down=tmp;
                result = result->down;
            }
        pq.pop();



    }
    result->down=NULL;
    printf("%d\n",res->data);
    return res;
}
int main()
{
    Node* root = NULL;

    /* Let us create the following linked list
       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
    */
    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    // Let us flatten the list
    root = flatten(root);

    // Let us print the flatened linked list
    printList(root);

    return 0;
}
