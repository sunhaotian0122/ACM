#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1005],sz[1005];

int main()
{
    int n,num;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sz[i]);
        }
        sort(sz+1,sz+1+n);
        scanf("%d",&num);
        if(num<5)
        {
            printf("%d\n",num);
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++)
        {
            for(int j=num-5;j>=sz[i];j--)
            {
                dp[j] = max(dp[j],dp[j-sz[i]]+sz[i]);
            }
        }
        printf("%d\n",num-dp[num-5]-sz[n]);
    }
    return 0;
}
