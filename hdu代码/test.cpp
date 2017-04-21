#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 1e7+9;
const int maxn = 10005;
int sz[maxn][25],num[maxn],vis[maxn],n,m;
ll ans;
vector<int>ve[maxn];

void dfs(int x,int k)
{
    if(vis[x])
    {
        ans++;
        if(ans>mod) ans %= mod;
        return;
    }
    vis[x]=1;
    int y,num;
    for(int i=0;i<ve[x].size();i++)
    {
        y=ve[x][i],num=0;
        for(int j=1;j<=m;j++)
        {
            if(sz[y][j]&&j!=k)
            {
                num++;
                dfs(y,j);
            }
        }
    }
    ans++;
    if(ans>mod) ans%=mod;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int a,b,x;
        for(int i=1;i<=n;i++) ve[i].clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&sz[i][j]);
            }
        }
        ans=1;
        for(int i=1;i<=m;i++)
        {
            if(sz[1][i])
            {
                dfs(1,i);
            }
        }
        if(ans>mod) ans %= mod;
        printf("%lld\n",ans);
    }
    return 0;
}
