#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int dp[20005],sz[35];

int main()
{
    int n,t;
    scanf("%d",&t);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&sz[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=t;j>=sz[i];j--)
        {
            dp[j] = max(dp[j],dp[j-sz[i]]+sz[i]);
        }
    }
    printf("%d\n",t-dp[t]);
    return 0;
}
