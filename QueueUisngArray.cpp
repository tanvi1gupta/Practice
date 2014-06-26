#include<Cstdio>
#include<iostream>
using namespace std;
int start =0;
int capacity=5;
int count =0;
int q[5];
void push(int n)
{
    if(count<capacity)
        q[count++]=n;
    else if(count>=capacity)
    {
        if(start==0)
            printf("Queue Overflow\n");
        else
        {
            if(count-capacity  < start)
            {
                q[count-capacity]=n;
                count++;
            }
            else
            {
                printf("Queue Overflow\n");
            }

        }
    }
}
void pop()
{
    if(count>0)
    {
        start++;
        if(start==capacity) start=0;
      //  count--;
    }

}
void top()
{
    printf("%d\n",q[start]);
}
int main()
{
    push(1);
    push(2);
    push(3);
    top();
    pop();
    top();
    pop();
    push(4);
    push(5);
    top();
    push(6);
    push(7);
    push(8);
    top();
    pop();
    pop();
    top();
     pop();
    top();


}
