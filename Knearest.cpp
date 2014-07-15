//sorted
//12 16 22 30 35 39 42 45 48 50 53 55 56 K = 4 X = 35
//output 22 30 39 42

#include<cstdio>
#include<iostream>
using namespace std;
int binarySearchX(int a[], int s, int e , int x)
{
    int mid=(s+e)/2;
    if(s>e) return -1;
    else if(a[mid]==x) return mid;
    else if(a[mid] < x) return binarySearchX(a, mid+1, e, x);
    else   return binarySearchX(a, s, mid-1, x);
}
int main()
{
    int n , k, x;
    scanf("%d %d %d", &n , &k, &x);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int index = binarySearchX(a, 0, n-1, x);
 //   printf("%d",index);
    int l = index-1;
    int r = index+1;
    while(l>=0 && r <n && k!=0)
    {
        int d1 = x-a[l];
        int d2 = a[r]-x;
        if(d1==d2)
        {
            printf("%d %d ", a[l], a[r]);
            l--;r++;
            k=-2;
        }
        else if(d1<d2)
        {
            printf("%d ",a[l]);
            l--;
            k--;
        }
        else{
            printf("%d ",a[r]);
            r++;
            k--;
        }
    }
}
