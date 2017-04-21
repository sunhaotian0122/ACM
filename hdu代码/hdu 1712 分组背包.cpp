#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int sz[105][105],dp[105];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&sz[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=m;j>=1;j--)
            {
                for(int k=1;k<=m;k++)
                {
                    if(j-k>=0) dp[j] = max(dp[j],dp[j-k]+sz[i][k]);
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
