#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int INF=-0x3f3f3f3f;
int dp[105][105];
int main()
{
    int n,tmp;
    while(~scanf("%d",&n))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&tmp);
                dp[i][j] = dp[i][j-1]+tmp;
            }
        int sum,ans=INF;
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                sum=0;
                for(int k=1;k<=n;k++)
                {
                    if(sum<0) sum=0;
                    sum += dp[k][j]-dp[k][i-1];
                    if(sum>ans) ans=sum;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
