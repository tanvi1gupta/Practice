#include<stdlib.h>
#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

#define NO_OF_CHAR 256

struct node
{
    char data;
    struct node* next, *prev;
};
//if head does not exits then make the head, else append at the end and update the tail
void appendNodeAtEnd(char c , struct node** head , struct node** tail)
{
    struct node *tmp = (node*)malloc(sizeof(node));
    tmp->data = c;
    tmp->next = tmp->prev=NULL;
    if(*head==NULL)
    {
        *head = tmp;
        *tail= tmp;
        return;
    }
    (*tail)->next = tmp;
    tmp->prev = *tail;
    *tail = tmp;
    return;

}

void removefromDLL(struct node* temp, struct node**head_ref, struct node**tail_ref)
{

    if (*head_ref == NULL)
         return;

    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;

    if (*tail_ref == temp)
            *tail_ref = (*tail_ref)->prev;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);

}
void printList(struct node* head, struct node*tail)
{
    printf("\nCURRENT LIST: ");
    while(head!=tail)
    {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("%c ", head->data);
    printf("\n");
    return;
}
void findFirstNonRepeating()
{
    struct node* inDLL[NO_OF_CHAR];
    bool repeated[NO_OF_CHAR];

    struct node*head=NULL;
    struct node*tail=NULL;
    for(int i=0;i<NO_OF_CHAR;i++)
    {
        inDLL[i]=NULL;
        repeated[i]=false;
    }
    char str[] = "geeksforgeeksandgeeksquizfor";
    for(int i=0;str[i];i++)
    {
        printf("reading char : %c\n",str[i]);
        char temp = str[i];
        //if repeated is false  1. check if present in DLL..if not present in DLL then add to DLL 2. if present in the DLL repeated-?true
        if(!repeated[temp])
        {

            if(inDLL[temp]==NULL)
            {
                appendNodeAtEnd(temp, &head, &tail);
                inDLL[temp]=tail;
            }
            else
            {
                //this means this is the second occurence of the given character
                 removefromDLL(inDLL[temp], &head, &tail);
                inDLL[temp]=NULL;
                repeated[temp]=true;
            }
        }
        if(head!=NULL)
        {
            printList(head, tail);
            printf("first non repeating charactor %c\n", head->data);
        }
    }


}
int main()
{
    findFirstNonRepeating();
    return 0;
}
