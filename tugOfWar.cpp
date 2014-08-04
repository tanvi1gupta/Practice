//find the subsets of size n/2 such that the difference of the sum of the elements of the subsets is minimum

#include<cstdio>
#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;
void tugofwarUtil(int a[], int n , bool curr[], bool sol[], int sum, int currpos, int currsum, int selected, int*mindiff)
{
    //every element has 2 possibilities either in set 1 or set 2
    //if curr[i]==true => in set1 else in set2
    if(currpos==n) return ;
    if( (n/2- selected) > (n-currpos)) return ;
    //current element not included in the solution
    tugofwarUtil(a, n, curr, sol, sum, currpos+1, currsum, selected, mindiff);
    currsum+=a[currpos];
    selected++;
    curr[currpos]=true;
    if(n/2==selected)
    {
        if(abs(sum/2-currsum)<*mindiff)
        {
            *mindiff = abs(sum/2-currsum);
            for(int i=0;i<n;i++) sol[i]=curr[i];
        }
    }
    else
    {
        //current element considered in the solution
         tugofwarUtil(a, n, curr, sol, sum, currpos+1, currsum, selected, mindiff);
    }
    curr[currpos]=false;

}
void tugOfWar(int a[], int n)
{
    bool sol[n], curr[n];
    memset(sol, false, sizeof(sol));//this gives the final soluntion
    memset(curr, false, sizeof(curr)); //current situation
    int mindiff = INT_MAX;
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
    }

    tugofwarUtil(a, n, curr, sol, sum, 0, 0, 0, &mindiff);
    for(int i=0;i<n;i++) if(sol[i]==true) printf("%d ", a[i]);
    printf("\n");
    for(int i=0;i<n;i++) if(sol[i]==false) printf("%d ", a[i]);
    printf("\n");
}
int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}
