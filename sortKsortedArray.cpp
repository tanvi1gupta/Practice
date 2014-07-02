#include<cstdio>
#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;
#define n 4
struct node
{
    int i;
    int j;
    int val;
};

struct node heap[3];
void minheapify(int i, int size)
{
    int l = 2*i+1;
    int r =2*i+2;
    int s =i;
    if(l<size && heap[l].val<heap[s].val) s=l;
    if(r<size && heap[r].val<heap[s].val) s=r;
    if(s!=i)
    {
        struct node t = heap[s];
        heap[s]=heap[i];
        heap[i]=t;
        minheapify(s, size);
    }
}
void heapify(int size)
{
    int i = size/2;
    while(i>=0)
    {
        minheapify(i, size);
        i--;
    }
}
node getMin( )
{
    return heap[0];
}
int *mergeKArrays(int a[][n], int k)
{
    for(int i=0;i<k;i++)
    {
        heap[i].i =i;
        heap[i].j = 1;
        heap[i].val = a[i][0];
    }
    heapify(k);
    /*for(int i=0;i<k;i++)
        printf("%d ",heap[i].val);
    printf("\n");*/

    int *output= new int[n*k];
    for(int i=0;i<n*k;i++)
    {
        struct node min = getMin();
        output[i]= min.val;
        if(min.j<n)
        {
            heap[0].val = a[min.i][ min.j];
            heap[0].i = min.i;
            heap[0].j = min.j+1;
        }
        else
        {
            heap[0].val = INT_MAX;
            //heap[0].i = min.i;
            //heap[0].j = min.j+1;
        }
        minheapify(0,k);
    }
    return output;
}
void printArray(int a[], int size)
{
    for(int i=0;i<size;i++)
        printf("%d ",a[i]);
}
int main()
{
     int arr[][n] =  {{2, 6, 12, 34},
                     {1, 9, 20, 1000},
                     {23, 34, 90, 2000}};
    int k = sizeof(arr)/sizeof(arr[0]);

    int *output = mergeKArrays(arr, k);

    cout << "Merged array is " << endl;
    printArray(output, n*k);

    return 0;
}
