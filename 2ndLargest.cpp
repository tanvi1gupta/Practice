#include<cstdio>
#include<iostream>
using namespace std;
int main()
{

    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int max = a[0], max2 =-2;
    if(a[0]>a[1])
    {
        max = a[0];
        max2 = a[1];
    }
    else
    {
        max = a[1];
        max2 = a[0];
    }
    for(int i=2;i<n;i++)
    {
        if(a[i]>= max )
        {
            max2 = max;
            max = a[i];
        }

        else if (a[i]>max2)
            max2=a[i];
    }
    printf("largest:%d second largest:%d\n",max, max2);

}

