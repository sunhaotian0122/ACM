#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int v[1005],c[1005],dp[1005];

int main()
{
    int T,n,num;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&num);
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
                dp[j] = max(dp[j],dp[j-c[i]]+v[i]);
            }
        }
        printf("%d\n",dp[num]);
    }
    return 0;
}
