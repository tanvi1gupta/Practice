//this is to find whether a setcan be broken down into 2 subsets of equal sum

#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int a[]={3, 1, 1, 2, 2, 1};
    int n = sizeof(a)/sizeof(a[0]);
    int sum =0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2!=0) printf("cannot be divided into subsets");
    else{
        int sum2=sum/2;
        int table[sum2+1][n+1];
        for(int i=0;i<n+1;i++)
            table[0][i]=1;
        for(int i=0;i<=sum2;i++)
            table[i][0]=0;
        for(int i=1;i<=sum2;i++)
        {
            for(int j=1;j<=n;j++)
            {
                table[i][j]=table[i-1][j];
                if(i>=a[j-1])
                    table[i][j]=table[i][j]|| table[i-a[j-1]][j-1];
            }
        }
        if(table[sum2][n]) printf("can be divided");
        else printf("cannot be divided into subsets");
    }
}
