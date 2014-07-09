#include<cstdio>
#include<iostream>
using namespace std;
int minheap[100], maxheap[100];
int minsize=0, maxsize=0;
void minheapify(int size, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int small =i;
    if(l<size && minheap[l]<minheap[small] ) small =l;
    if(r<size && minheap[r]<minheap[small] ) small =r;
    if(small!=i)
    {
        int t = minheap[small];
        minheap[small]=minheap[i];
        minheap[i]=t;
        minheapify(small,i);
    }
}
void maxheapify(int size, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int small =i;
    if(l<size && maxheap[l]>maxheap[small] ) small =l;
    if(r<size && maxheap[r]>maxheap[small] ) small =r;
    if(small!=i)
    {
        int t = maxheap[small];
        maxheap[small]=maxheap[i];
        maxheap[i]=t;
        maxheapify(small,i);
    }
}
void heapify(int size, bool flag)
{
    int i = size/2;
    while(i>=0)
    {
        if(flag==1) minheapify(size, i);
        else maxheapify(size,i);
        i--;
    }
}
int signum()
{
    if(maxsize<minsize) return -1;
    if(maxsize==minsize) return 0;
    return 1;
}
int getmedian(int a, int m)
{
    int sign = signum();
    if(sign==0)
    {
        if(a>m)
        {
            minheap[minsize++]=a;
            heapify(minsize, 1);
            m = minheap[0];
        }
        else{
            maxheap[maxsize++]=a;
            heapify(maxsize, 0);
            m = maxheap[0];
        }


    }
    else if(sign==-1)
    {
        if(a>m)
        {
            maxheap[maxsize++]=minheap[0];
            heapify(maxsize, 0);
            minheap[0]=a;
            minheapify(minsize, 0);

        }
        else
        {
            maxheap[maxsize++]=a;
            heapify(maxsize, 0);

        }
           m = (minheap[0]+maxheap[0])/2;
    }
    else
    {
        if(a<m)
        {
            minheap[minsize++]=maxheap[0];
            maxheap[0]=a;
            maxheapify(maxsize, 0);
            heapify(minsize, 1);

        }
        else
        {
            minheap[minsize++]=a;
            heapify(minsize, 1);
        }
        m = (minheap[0]+maxheap[0])/2;
    }
   /* for(int i=0;i<maxsize;i++)printf("%d->",maxheap[i]);
    printf("\n");
    for(int i=0;i<minsize;i++)printf("%d->",minheap[i]);
    printf("\n");*/
    return m;
}
int main()
{
    int a[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n=12;
    int m=0;
    for(int i=0;i<n;i++)
    {
        m = getmedian(a[i], m);
        printf("%d\n",m);
    }
}
