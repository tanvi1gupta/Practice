#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stack>
using namespace std;
//5+((1+2)*4)-3
struct node
{
    char data;
    struct node* left;
    struct node* right;
};
bool isOp(char op)
{
    if(op=='+' || op=='-' || op=='*'||op=='/'||op=='('||op==')')
        return true;
    else return false;
}
int precedennce(char op)
{
    if(op=='+' || op=='-') return 1;
    else if(op=='*' || op=='/') return 2;
    return 0;
}
int isDigit(char a)
{
    if(a>='0' && a<='9') return 1;
    else return 0;
}
void evaluate(char a[])
{
    int len = strlen(a);
    if(len==0) return ;
    stack<char> s;
    int k=0;
    for(int i=0;i<len;i++)
    {
        if(isDigit(a[i]))
        {
            s.push(a[i]);
        }
        else
        {
            int o1 = s.top()-'0';
            s.pop();
            int o2 = s.top()-'0';
            s.pop();
            //printf("%d %d\n",o1,o2);
            if(a[i]=='+')
                s.push(o1+o2+'0');
            else if(a[i]=='-')
                s.push(o2-o1+'0');
            else if(a[i]=='*')
                s.push(o1*o2+'0');
            else if(a[i]=='/')
                s.push(o2/o1+'0');

        }
    }
    printf("%d\n",s.top()-'0');
}
void createPostfix(char a[])
{
    stack<char> s;
    int len = strlen(a);
    char postfix[len+1];
    int k=0;
   // printf("%s\n",a);
    for(int i=0;i<len;i++)
    {
        if(isOp(a[i]))
        {
            if(s.empty())
                s.push(a[i]);
            else
                {
                char top = s.top();
                int pre1 = precedennce(top);
                int pre2 = precedennce(a[i]);

                if(a[i]=='(') s.push(a[i]);
                else if(top=='(')
                        s.push(a[i]);
                else if(a[i]==')')
                {
                    while(top!='(')
                    {
                        postfix[k++]=top;
                        s.pop();
                        top = s.top();
                    }
                    s.pop();
                }

                else if(pre1<pre2)
                    s.push(a[i]);
                else
                {
                    postfix[k++]=top;
                    s.pop();
                    s.push(a[i]);
                }
            }
        }
        else
        {
            postfix[k++]=a[i];
        }
    }
    while(!s.empty())
    {
        postfix[k++]=s.top();
        s.pop();
    }
    postfix[k]='\0';
    printf("%s\n",postfix);
    evaluate(postfix);
}

int main()
{
    char a[100];
    scanf("%[^\n]",a);
    createPostfix(a);
}
