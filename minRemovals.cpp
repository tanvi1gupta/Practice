//minimum number of eleemtns to be removes suchthat the 2min>=max

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int get2times(int a[], int start, int end, int k)
{
    if(start>end) return -1;
    int mid=(start+end)/2;
    if(mid>0 && a[mid-1] <= k && k< a[mid] )
    {
        return mid-1;
    }
    else if(a[mid] < k) return get2times(a, mid+1, end, k);
    else
        return get2times(a, start, mid-1, k);
}
int removals(int a[], int start, int end)
{
    int r,l_r=INT_MAX, index_min, index_max;
    for(int i=start;i<=end;i++)
    {
        int index = get2times(a, start, end, 2*a[i]);

        if(index==-1) continue;
        //printf("%d %d\n",a[i], a[index]);
        r = end-index + i-start;
        if(r<l_r)
        {
            l_r =r;
            index_min = i;
            index_max =index;
        }


    }
    printf("%d %d\n", a[index_min], a[index_max]);
    return l_r;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d", removals(a, 0, n-1));

}
