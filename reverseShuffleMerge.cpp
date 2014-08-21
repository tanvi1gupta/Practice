//https://www.hackerrank.com/challenges/reverse-shuffle-merge
//basically in the reverse string of S find whether a substringfits or not, if a substring fits then the reverse of that string is the answer
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 26
int main()
{
    char a[10010];
    scanf("%[^\n]",a);
    int len = strlen(a);
    char b[len];
    int hashmap[MAX]={0};
    int k =0;
    for(int i=0;i<len;i++) {
        hashmap[a[i]-'a']++;
        b[k++]=a[len-i-1];
    }
    b[k]='\0';

    //printf("%s---",b);
    char c[len/2+1];
    for(int i=0;i<26;i++)
    {
        if(hashmap[i])
         {
            hashmap[i]=hashmap[i]/2;
        }
    }
    int ret[len/2];
    for(int i=0;2*i<len;i++)
    {
        for(int c=0;c<26;c++)
       {
            bool ok = true;
            if(hashmap[c])
            {
               // printf("in if  %c----", c+'a');
                ret[i]=c;
                int p=0, l=0;
                for(int j=0;j<len;j++)
                 {
                   //  printf("%c %c..", ret[p]+'a', b[j]);
                    if(ret[p]+'a'==b[j])
                    {
                        p++;
                        l =j;
                        if(p>i) break;
                    }
                }
             //   printf("%d %d %d\n", p, i, l);
                if(p<=i) continue;
                int want[26]={0};
                for(int j=0;j<26;j++) want[j]=hashmap[j];
                for(int j=0;j<=i;j++) want[ret[j]]--;
                int have[26]={0};
                for(int j=l+1;j<len;j++) have[b[j]-'a']++;
               // for(int j=0;j<26;j++) printf("%c w:%d h:%d\n", j+'a', want[j], have[j]);
                ok = 1;
                for(int j=0;j<26;j++) if(want[j]<0 || want[j] > have[j]) ok = 0;
               // printf("%c %d\n",c+'a', ok);
                if(ok) break;

            }
            if(hashmap[c] && ok ) break;
        }
    }

    for(int i=0;i<len/2;i++)
        c[i]=ret[i]+'a';
    c[len/2]='\0';
    printf("%s",c);
}
