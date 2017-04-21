#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int dp[105][105],a[105],b[105];

int main()
{
    int n,m,k,s,tmp;
    while(~scanf("%d%d%d%d",&n,&m,&k,&s))
    {
        for(int i=1;i<=k;i++)  scanf("%d%d",&a[i],&b[i]);
        memset(dp,0,sizeof(dp));
        tmp=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i<b[j]) continue;
                for(int x=1;x<=s;x++)
                {
                    for(int y=1;y<=x&&y*b[j]<=i;y++)
                    {
                        dp[i][x] = max(dp[i-y*b[j]][x-y]+y*a[j],dp[i][x]);
                    }
                }
            }
            if(dp[i][s]>=n)
            {
                tmp=i;
                break;
            }
        }
        if(tmp==0) printf("-1\n");
        else printf("%d\n",m-tmp);
    }
    return 0;
}
