#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int dp[105][2005],sz[105];

int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&sz[i]);
        sum += sz[i];
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(j+sz[i]<=sum) dp[i][j+sz[i]] = max(dp[i][j+sz[i]],dp[i-1][j]);
            if(j>=sz[i] && dp[i-1][j]!=-1) dp[i][j-sz[i]] = max(dp[i][j-sz[i]],dp[i-1][j]+sz[i]);
            else if(j<sz[i] && dp[i-1][j]!=-1) dp[i][sz[i]-j] = max(dp[i][sz[i]-j],dp[i-1][j]+j);
        }
    }
    if(dp[n][0]>0) printf("%d\n",dp[n][0]);
    else printf("Impossible\n");
}
