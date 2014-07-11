#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int val;
    struct node*next;
};
struct node* insert ( struct node* start , int num)
{
    struct node* tmp = start;
    while(tmp->next!=NULL) tmp = tmp->next;
    struct node* tmp1 = (struct node*)malloc(sizeof(struct node));
    tmp1->val = num;
    tmp1->next = NULL;
    tmp->next = tmp1;
    return start;
}
void print(struct node* root)
{
    while(root!=NULL)
    {
        printf("%d ",root->val);
        root = root->next;
    }
}
struct node*reverse(struct node* root)
{
    if(root==NULL) return NULL;
    struct node* prev= NULL;
    struct node* next;
    struct node* current = root;
    while(current!=NULL)
    {
        next =current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
int main()
{
    struct node* start;
    int n ,num;
    printf("link list 1, give no of numebrs :\n");
    scanf("%d",&n);
    start= (struct node*)malloc(sizeof(struct node));
    start->val = 0;
    start->next= NULL;

    for(int i=1;i<n;i++)
    {
        insert(start, i);
    }
    print(start);
    printf("\n");
    start =reverse(start);
    print(start);
}
