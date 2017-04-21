#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int sz[n+5];
        for(int i=1;i<=n;i++) scanf("%d",&sz[i]);
        for(int j=2;j<=n;j++)
        {
            int key = sz[j];
            int i = j-1;
            while(i>0&&sz[i]>key)
            {
                sz[i+1] = sz[i];
                i -= 1;
            }
            sz[i+1] = key;
        }
        for(int j=1;j<=n;j++)
        {
            if(j==n) printf("%d\n",sz[j]);
            else printf("%d ",sz[j]);
        }
    }
    printf("%f\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}
