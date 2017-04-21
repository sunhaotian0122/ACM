#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 0x3f3f3f3f;
int dp[10005],p[505],w[505];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int e,f,n;
        scanf("%d%d",&e,&f);
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i],&w[i]);
        if(f==e)
        {
            printf("The minimum amount of money in the piggy-bank is 0.\n");
            continue;
        }
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=w[i];j<=f-e;j++)
            {
                dp[j] = min(dp[j],dp[j-w[i]]+p[i]);
            }
        }
        if(dp[f-e]==INF)
        {
            printf("This is impossible.\n");
            continue;
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f-e]);
            continue;
        }
    }
    return 0;
}
