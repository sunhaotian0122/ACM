#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int dp[405][405],s1[55],s2[55],v[55];

int main()
{
    int t,m,n;
    scanf("%d%d",&t,&m);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&s1[i],&s2[i],&v[i]);
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=t;j>=s1[i];j--)
        {
            for(int k=m;k>=s2[i];k--)
            {
                dp[j][k] = max(dp[j][k],dp[j-s1[i]][k-s2[i]]+v[i]);
            }
        }
    }
    printf("%d\n",dp[t][m]);
    return 0;
}
