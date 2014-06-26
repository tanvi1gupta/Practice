//implement pop push getmax in order(1)

#include<cstdio>
#include<iostream>
using namespace std;
int s[1000];
int gmin[1000];
int capacity =100;
int count =0;
int countm=0;
void push(int n)
{
    if(count==0||count+1<=capacity)
    {
        s[count++]=n;
        if(countm==0||n < gmin[countm-1] )
            gmin[countm++]=n;
    }

    else
        printf("Stack overflow\n");
}
int pop()
{
    int n = s[count-1];
    if(n==gmin[countm-1])
        countm--;
    count--;
    return n;
}
void getminStack()
{
    printf("%d\n", gmin[countm-1]);
}
int main()
{
    push(3);
    push(2);
    getminStack();
    pop();
    getminStack();
    push(5);
    push(7);
    getminStack();
    push(6);
    push(4);
    getminStack();
    push(1);
    push(10);
    getminStack();
    //push(3);
    //push(3);

}
