#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

int dp[15][105],minimal[15];
const int INF=0x3f3f3f3f;

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int hire,salary,fire,maxp=-1,cost;
        scanf("%d%d%d",&hire,&salary,&fire);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&minimal[i]);
            if(minimal[i]>maxp) maxp=minimal[i];
        }
        memset(dp,INF,sizeof(dp));
        for(int i=minimal[1];i<=maxp;i++) dp[1][i] = (hire+salary)*i;
        for(int i=2;i<=n;i++)
        {
            for(int j=minimal[i];j<=maxp;j++)
            {
                for(int k=minimal[i-1];k<=maxp;k++)
                {
                    if(k<j) cost = j*salary+(j-k)*hire;
                    else cost = j*salary+(k-j)*fire;
                    if(dp[i-1][k]+cost<dp[i][j]) dp[i][j] = dp[i-1][k]+cost;
                }
            }
        }
        int ans=INF;
        for(int i=minimal[n];i<=maxp;i++) if(dp[n][i]<ans) ans=dp[n][i];
        printf("%d\n",ans);
    }
    return 0;
}
