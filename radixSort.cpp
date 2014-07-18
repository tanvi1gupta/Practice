#include<cstdio>
#include<iostream>
using namespace std;
int getmax(int a[], int n)
{
    int max =-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max) max=a[i];
    }
    return max;
}
void sortR(int a[], int exp, int n)
{
    int count[10]={0};
    int output[n];
    for(int i=0;i<n;i++)
        count[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];
    for(int i=n-1;i>=0;i--)
    {
        output[count[ (a[i]/exp)%10 ]-1]=a[i];
        count[ (a[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)a[i]=output[i];

}
void radixSort(int a[], int n)
{
    int maxvalue = getmax(a, n);
    for(int i=1;maxvalue/i>0;i=i*10)
    {
        sortR(a,i,n);
    }
}
int main()
{
    int n;scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    radixSort(a,n);
    for(int i=0;i<n;i++)printf("%d ",a[i]);
}
