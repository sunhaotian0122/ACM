#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int sz[5005],dp[125005];

int main()
{
    int n,sum,a,b,num;
    while(scanf("%d",&n)&&n>0)
    {
        sum=0;
        num=1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            sum += a*b;
            while(b--)
            {
                sz[num++] = a;
            }
        }
        for(int i=1;i<num;i++)
        {
            for(int j=sum/2;j>=sz[i];j--)
            {
                dp[j] = max(dp[j],dp[j-sz[i]]+sz[i]);
            }
        }
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }
    return 0;
}
