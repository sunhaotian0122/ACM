#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int sz[10],dp[200005],sum,v[105],w[105];

void solve()
{
    int cnt=0;
    for(int i=1;i<=6;i++)
    {
        int tmp=1;
        while(sz[i]>=tmp)
        {
            v[++cnt] = i*tmp;
            w[cnt] = i*tmp;
            sz[i] -= tmp;
            tmp <<= 1;
        }
        if(sz[i])
        {
            v[++cnt] = i*sz[i];
            w[cnt] = i*sz[i];
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=sum;j>=v[i];j--)
        {
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
        }
    }
}

int main()
{
    int cas = 0;
    while(1)
    {
        sum=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&sz[i]);
            sum += (sz[i]*i);
        }
        if(sum==0) break;
        cas++;
        printf("Collection #%d:\n",cas);
        if(sum&1)
        {
            printf("Can't be divided.\n\n");
            continue;
        }
        else
        {
            sum /= 2;
            memset(dp,0,sizeof(dp));
            solve();
            if(dp[sum]==sum)
            {
                printf("Can be divided.\n\n");
                continue;
            }
            else
            {
                printf("Can't be divided.\n\n");
                continue;
            }
        }
    }
    return 0;
}
