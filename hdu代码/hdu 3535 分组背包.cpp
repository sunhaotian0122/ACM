#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = -0x3f3f3f3f;
int dp[105][105],c[105],w[105];

int main()
{
    int n,t,m,s;
    while(~scanf("%d%d",&n,&t))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&m,&s);
            for(int j=1;j<=m;j++) scanf("%d%d",&c[j],&w[j]);
            if(s==0)
            {
                for(int j=0;j<=t;j++) dp[i][j] = INF;
                for(int j=1;j<=m;j++)
                {
                    for(int k=t;k>=c[j];k--)
                    {
                        dp[i][k] = max(dp[i][k],dp[i][k-c[j]]+w[j]);
                        dp[i][k] = max(dp[i][k],dp[i-1][k-c[j]]+w[j]);
                    }
                }
            }
            else if(s==1)
            {
                for(int j=0;j<=t;j++) dp[i][j] = dp[i-1][j];
                for(int j=1;j<=m;j++)
                {
                    for(int k=t;k>=c[j];k--)
                    {
                        dp[i][k] = max(dp[i][k],dp[i-1][k-c[j]]+w[j]);
                    }
                }
            }
            else
            {
                for(int j=0;j<=t;j++) dp[i][j] = dp[i-1][j];
                for(int j=1;j<=m;j++)
                {
                    for(int k=t;k>=c[j];k--)
                    {
                        dp[i][k] = max(dp[i][k],dp[i][k-c[j]]+w[j]);
                        dp[i][k] = max(dp[i][k],dp[i-1][k-c[j]]+w[j]);
                    }
                }
            }
        }
        dp[n][t] = max(dp[n][t],-1);
        printf("%d\n",dp[n][t]);
    }
    return 0;
}
