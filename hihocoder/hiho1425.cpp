#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int sz[205];

int main()
{
    int n,ans;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sz[i]);
        }
        for(int i=n+1;i<=2*n;i++)
        {
            sz[i] = sz[i-n];
        }
        int tmp;
        tmp=ans=0;
        for(int i=2;i<=2*n;i++)
        {
            if(sz[i]>sz[i-1]) tmp++;
            else
            {
                if(tmp>ans) ans = tmp;
                tmp=0;
            }
        }
        tmp=0;
        for(int i=2;i<=2*n;i++)
        {
            if(sz[i]<sz[i-1]) tmp++;
            else
            {
                if(tmp>ans) ans=tmp;
                tmp=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
