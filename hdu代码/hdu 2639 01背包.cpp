#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[1005],c[1005],dp[1005][35],sz1[35],sz2[35];

int main()
{
    int T,n,num,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&num,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&v[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=num;j>=c[i];j--)
            {
                int x;
                for(x=1;x<=k;x++)
                {
                    sz1[x] = dp[j-c[i]][x]+v[i];
                    sz2[x] = dp[j][x];
                }
                sz1[x]=sz2[x]=-1;
                int a,b;
                a=b=x=1;
                while(x<=k && (sz1[a]!=-1 || sz2[b]!=-1))
                {
                    if(sz1[a]>sz2[b])
                    {
                        dp[j][x] = sz1[a++];
                    }
                    else
                    {
                        dp[j][x] = sz2[b++];
                    }
                    if(dp[j][x]!=dp[j][x-1]) x++;
                }
            }
        }
        printf("%d\n",dp[num][k]);
    }
    return 0;
}
