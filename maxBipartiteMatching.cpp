//consider M applicants and N jobs. Each applicant has a subset of jobs that he is interested in.
//Each job opening can accept only 1 applicant & applicant can have only 1 job
//Find job assignments to applicants

//this is maxflwo problem where each edge has wt 1 -> maxflow will give the max job applciants
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
#define M 6 //applicants
#define N 6 //jobs
bool getApplicant(int g[M][N], int a, bool seen[], int match[])
{
    //find job for app a
    for(int v=0;v<N;v++)
    {
        //if app is interestd in job j and job not taken
        if(g[a][v] && !seen[v])
        {
            //match[j]=v;
            seen[v]=true;
            //if job not taken, or
            // if job v taken but applicant of job v can be assigned to another job
            if(match[v] <0 || getApplicant(g, match[v], seen, match))
            {
                match[v]=a;
                return true;
            }
        }
    }
    return false;
}
int maxBPM(int g[M][N])
{
    bool seen[N];
    int match[N];
    memset(match, -1, sizeof(match));
    int result = 0;
    for(int u=0;u<M;u++)
    {
        memset(seen, 0, sizeof(seen));
        if(getApplicant(g, u, seen, match))
            result++;
    }
    for(int i=0;i<N;i++)
    {
        printf("job:%d applicant:%d\n",i, match[i]);
    }
    return result;
}
int main()
{
    // Let us create a bpGraph shown in the above example
    int bpGraph[M][N] = {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };

    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);

    return 0;
}
