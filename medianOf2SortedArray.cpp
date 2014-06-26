#include<cstdio>
#include<iostream>
/*
5
1 12 15 26 38
2 13 17 30 45
and: 16
*/
using namespace std;
int max(int a, int b)
{
    if(a>b) return a;
    return b;
}
int min(int a, int b)
{
    if(a<b) return a;
    return b;
}
int median(int a[], int n)
{
    if(n%2==0) return (a[n/2-1]+a[n/2])/2;
    else return a[n/2];
}
int getMedian(int a[], int b[], int n)
{
    if(n<=0) return -1;
    if(n==1) return (a[0]+b[0])/2;
    if(n==2) return (max(a[0],b[0])+min(a[1],b[1]))/2;
    int m1 = median(a,n);
    int m2 = median(b,n);
    if(m1==m2) return m1;
    if(m1 <m2)
    {
        if(n%2==0)
            return getMedian(a+n/2-1, b,n-n/2+1 );
        else return getMedian(a+n/2, b, n-n/2 );
    }
    else
    {
        if(n%2==0)
             return getMedian(b+n/2-1, a,n-n/2+1 );
        else return getMedian(b+n/2, a, n-n/2 );
    }
}
int main()
{
    int n,m;
    scanf("%d ",&n);
    int a[n], b[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    printf("%d",getMedian(a,b,n));
}
