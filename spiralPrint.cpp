#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,m; scanf("%d%d",&n,&m);
    int mat[n][m];
    int k=0, l=0,z=1, a =n, b=m;
   while(k<n && l<m)
   {
       //first row
       for(int i=l;i<m;i++)
            mat[k][i]=z++;
        k++;
        //last col
       for(int i = k ; i<n ;i++)
            mat[i][m-1]=z++;
        //l++;
        m--;
        //last row
        if(k<n)
        {
            for(int i = m-1;i>=l;i--)
            {
                mat[n-1][i]=z++;
            }
            n--;

        }
        //first col
        if(l<m)
        {
                for(int i=n-1 ; i>=k ;i--)
                    mat[i][l]=z++;
                l++;
        }


   }
   for(int i=0;i<a;i++)
   {
       for(int j=0;j<b;j++)
            printf("%d\t", mat[i][j]);
       printf("\n");

   }
}
