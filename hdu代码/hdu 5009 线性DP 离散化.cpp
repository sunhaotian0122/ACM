#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm> 
using namespace std;

const int maxn=50005;
const int INF=0x3f3f3f3f;
int dp[maxn],sz[maxn],nex[maxn],pre[maxn];
map<int,int>mp; 

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		mp.clear();
		for(int i=1;i<=n;i++) 
		{
			scanf("%d",&sz[i]);
			nex[i]=i+1;
			pre[i]=i-1;
		}
		memset(dp,INF,sizeof(dp));
		pre[0]=-1;
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			if(!mp[sz[i]]) mp[sz[i]]=i;
			else 
			{
				int x=mp[sz[i]];
				nex[pre[x]] = nex[x];
				pre[nex[x]] = pre[x];
				mp[sz[i]] = i;
 			}
 			int num=0;
 			for(int j=pre[i];j!=-1;j=pre[j])
 			{
 				num++;
 				dp[i] = min(dp[i],dp[j]+num*num);
 				if(num*num>i) break;
			 }
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
