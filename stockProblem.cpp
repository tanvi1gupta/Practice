#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
struct interval
{
    int buy;
    int sell;
};
void buysell(int s[], int n)
{
    struct interval stock[n/2+1];
    int min = INT_MAX , max = INT_MIN;
    int count =0, i=0, profit =0;
    while(i<n-1)
    {
        //local minima
        while(i<n-1 && s[i+1]<=s[i])
            i++;
        if(i==n-1) break;
        stock[count].buy = i++;
        //local maxima
        while(i<n && s[i]>=s[i-1])
            i++;
        stock[count].sell = i-1;
        profit +=s[stock[count].sell]- s[stock[count].buy];
        count++;

    }
    for(int i=0;i<count ;i++)
    {
        printf("Buy at day:%d Sell at day:%d\n", stock[i].buy, stock[i].sell);
    }
    printf("Profit: %d\n", profit);
}
int main()
{
    int n;
    scanf("%d",&n);
    int stock[n];
    for(int i=0;i<n;i++) scanf("%d",&stock[i]);
    buysell(stock, n);
}
