#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dp[1005];

int main()
{
    int T,n,t,w;
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&T,&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&w);
        for(int j=T;j>=t;j--)
        {
            dp[j] = max(dp[j],dp[j-t]+w);
        }
    }
    printf("%d\n",dp[T]);
    return 0;
}
