#include<cstdio>
#include<iostream>
using namespace std;
void swap(char *a, char *b)
{
    char t = *a;
    *a=*b;
    *b=t;
}
void permute(char *a, int i, int n)
{
    if(i==n)
        printf("%s\n",a);
    else
    {
        for(int j=i;j<=n;j++)
        {
            if(a[i]==a[j] && i!=j) continue;    //for same character
            swap(a+i, a+j);
            permute(a, i+1, n);
            swap(a+i, a+j);
        }
    }

}
int main()
{

    char a[]="AABC";
    permute(a,0,3);
    return 0;
}
