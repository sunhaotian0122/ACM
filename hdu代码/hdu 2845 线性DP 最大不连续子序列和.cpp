#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn=200005;
int tmp[maxn],dp[maxn];

int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    {
        int x;
        tmp[0]=tmp[1]=0;
        dp[0]=dp[1]=0;
        for(int i=2;i<=m+1;i++)
        {
            for(int j=2;j<=n+1;j++)
            {
                scanf("%d",&x);
                tmp[j] = max(tmp[j-1],tmp[j-2]+x);
            }
            dp[i] = max(dp[i-1],dp[i-2]+tmp[n+1]);
        }
        printf("%d\n",dp[m+1]);
    }
    return 0;
}
