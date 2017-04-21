#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int maxn=100005;
const int INF=0x3f3f3f3f;
int dp[15][maxn],sz[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++) scanf("%d",&sz[i]);
		memset(dp,INF,sizeof(dp));
		dp[1][2]=0;
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=10;j++)
			{
				if(i-j<=0) break;
				if(sz[i]-sz[i-j]<=10)
				{
					for(int k=1;k<=10;k++)
					{
						if(i-j-k<=0) break;
						if(sz[i]-sz[i-j-k]<=10)
						{
							dp[j][i] = min(dp[j][i],dp[k][i-j]+1);
						}
					}
				}
			}
		 } 
		 int ans=INF;
		 for(int i=1;i<=10;i++)
		 {
		 	ans = min(ans,dp[i][n]);
		 }
		 if(ans==INF) printf("-1\n");
		 else printf("%d\n",ans); 
	}
	return 0;
 } 
