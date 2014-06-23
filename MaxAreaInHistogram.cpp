#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
void getMaxHist(int a[], int n)
{
    stack<int> s;
    int max_area=0, area_with_top,i=0;
    while(i<n)
    {
        if(s.empty() || a[s.top()] <=a[i])
            s.push(i++);
        else{
            int top = s.top(); s.pop();
            area_with_top = a[top]*(s.empty()?i:i-s.top()-1);
            if(area_with_top >max_area)
                max_area = area_with_top;
        }
    }
    while(!s.empty())
    {
        int top = s.top(); s.pop();
            area_with_top = a[top]*(s.empty()?i:i-s.top()-1);
            if(area_with_top >max_area)
                max_area = area_with_top;
    }
    printf("%d\n", max_area);
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    getMaxHist(a, n);
}
