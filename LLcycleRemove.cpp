#include<cstdio>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
node* newnode(int data)
{
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data =data;
    t->next  =NULL;
    return t;
}
node* insertnode(struct node* head,int d)
{
    if(head==NULL) return newnode(d);
    struct node* t= head;
    while(t->next!=NULL) t = t->next;
    t->next = newnode(d);
    return head;
}
void removeCycle2(struct node* slow, struct node*head)
{
    struct node*p=slow;
    struct node*p2=slow;
    int k=1;
    while(p->next!=p2) {
            p=p->next;
            k++;
    }
    printf("length of loop%d\n",k);
    p2=head;
    p=head;
    for(int i=0;i<k;i++) p2=p2->next;
    while(p2!=p)
    {
        p=p->next;
        p2=p2->next;
    }
    p2=p2->next;
    while(p2->next!=p)
    {
        p2=p2->next;
    }
    p2->next=NULL;


}
void removeCycle(struct node*slow, struct node*head)
{
    //slow is one of the loop values
    struct node*p1, *p2;
    p1=head;
    while(1)
    {
        p2 =slow;
        while(p2->next!=p1 && p2->next!=slow)
            p2=p2->next;
        if(p2->next==p1)
        {
           // p2->next=NULL;
            break;
        }
        else p1=p1->next;
    }
    p2->next=NULL;
}
bool detectCycle(struct node* head)
{
    struct node*slow = head;
    struct node* fast = head;
    while(slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) {
                 removeCycle2(slow, head);
                return true;

        }
    }
    return false;
}
void print(struct node* head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
int main()
{
        struct node* head = NULL;
        head = insertnode(head, 1);
        head = insertnode(head, 2);
        head = insertnode(head, 3);
        head = insertnode(head, 4);
        head = insertnode(head, 5);
        head = insertnode(head, 6);
        head = insertnode(head, 7);
        head = insertnode(head, 8);
        //printf("%d\n",head->next->next->next->next->next->next->next->data);
        head->next->next->next->next->next->next->next = head->next->next->next;
        bool iscycle =detectCycle(head);
        if(iscycle) {
                printf("yes cycle\n");
                print(head);
        }
        else printf("no cycle\n");
}
