#include<cstdio>
#include<iostream>
#include<limits.h>
#include<string.h>
using namespace std;
/*

4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6*/
int kadaneSum(int a[], int *start, int *finish, int n)
{
    int sum =0, maxSum = INT_MIN;
    sum = 0;
    maxSum = INT_MIN;
    int local_start =0;
    for(int i=0;i<n;i++)
    {
        sum = sum +a[i];
        if(sum <0) {
                sum =0;
                local_start = i+1;
        }
        if(sum >maxSum) {
               maxSum = sum;
               *start = local_start;
               *finish =i;
        }
    }
    if(*finish!=-1)
        return maxSum;
    sum = a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i] > sum)
        {
            sum =a[i];
            *start = *finish = i;
        }
    }
    return sum;
}
void print(int temp[], int n)
{
    printf("\n\n");
    for(int i=0;i<n;i++) printf("%d ",temp[i]);
    //printf("\n\n");
}
void findMaxSum(int mat[][10], int n , int m)
{
    int temp[n], sum, start , finish, maxSum= INT_MIN, finalleft, finalright, finaltop, finalbottom;
    for(int i=0;i<m;i++)
    {
        memset(temp, 0, sizeof(temp));
        for(int j=i;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                temp[k]+=mat[k][j];
            }
           // print(temp, n);
            sum = kadaneSum(temp, &start, &finish, n);
           // printf("sum: %d",sum);
            if(sum>maxSum)
            {
                maxSum=sum;
                finalleft = i;
                finalright =j;
                finaltop = start;
                finalbottom = finish;
            }
        }
    }
    printf("top left%d %d\n", finaltop, finalleft);
    printf("bottom right%d %d\n", finalbottom, finalright);
    printf("%d\n",maxSum);
}
int main()
{
    int n , m;
    scanf("%d%d",&n,&m);
    int mat[10][10];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&mat[i][j]);
    findMaxSum(mat, n,m);


}
