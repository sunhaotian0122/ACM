#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = -0x3f3f3f3f;
int dp[2020],f[2020];

int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<n;i++) scanf("%d",&f[i]);
        memset(dp,INF,sizeof(dp));
        dp[0]=0;
        for(int i=1;i<=n-2;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i] = max(dp[i],dp[i-j]+f[j+1]-f[1]);
            }
        }
        printf("%d\n",dp[n-2]+n*f[1]);
    }
    return 0;
}
