#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int m[105];
float pro[105],dp[10005];

int main()
{
    int T,n,sum;
    float p;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%f %d",&p,&n);
        p = 1-p;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %f",&m[i],&pro[i]);
            sum += m[i];
            pro[i] = 1-pro[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=sum;j>=m[i];j--)
            {
                dp[j] = max(dp[j],dp[j-m[i]]*pro[i]);
            }
        }
        for(int i=sum;i>=0;i--)
        {
            if(dp[i]>=p)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
