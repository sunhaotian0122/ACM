#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 5e4+5;
int sz[maxn];

int main()
{
    int n,l,r,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&sz[i]);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        l=r=sz[i];
        for(int j=i;j<=n;j++)
        {
            if(sz[j]>r) r = sz[j];
            if(sz[j]<l) l = sz[j];
            if(r-l==j-i) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
