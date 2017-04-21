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
using namespace std;

bool comp(int a,int b)
{
    return a>b;
}

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sz[n];
        for(int i=0;i<n;i++) scanf("%d",&sz[i]);
        sort(sz,sz+n,comp);
        for(int i=0;i<m;i++)
        {
            if(i==m-1) printf("%d\n",sz[i]);
            else printf("%d ",sz[i]);
        }
    }
    return 0;
}
