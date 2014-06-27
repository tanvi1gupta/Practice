//find triplet such that ai]>a[j]>[ak] && i<j<k
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    //first find local maxima
    //then 2 local minima
    int max1 = INT_MAX, min1 = INT_MAX, min2= INT_MAX;
    int i1 = -1, i2=-1, i3=-1;
    for(int i=0;i<n;i++)
    {
        while(i< n-1 && a[i]<a[i+1]) i++;

        if(i==n)
        {
            printf("no triplet\n");
            break;
        }
        max1 = a[i++];
        i1=i-1;
        //find local minima

        while(i>0 && i<n && a[i] > a[i-1])
            i++;
        min1 = a[i++];
        i2=i-1;
        while(i>0 && i<n && a[i] > a[i-1])
            i++;
        min2 = a[i++];
        i3=i-1;
        if(max1!=INT_MAX && min1 !=INT_MAX && min2!=INT_MAX)
            break;

    }
    printf("Numbers:\t%d %d %d\n",max1, min1, min2);
    printf("Indeces:\t%d %d %d",i1,i2,i3);
}
