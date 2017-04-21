#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int time[105],v[105],dp[1005];

int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&v[i],&time[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=t;j>=time[i];j--)
        {
            dp[j] = max(dp[j],dp[j-time[i]]+v[i]);
        }
    }
    printf("%d\n",dp[t]);
}
