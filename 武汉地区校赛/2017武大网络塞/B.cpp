#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

const int mod = 1e7+9;
const int maxn = 10005;
int sz[maxn][25],vis[maxn],dp[maxn][25],n,m;
//dp[i][j]表示i结点涂j颜色的涂法总数
vector<int>ve[maxn];//无根图储存边
vector<int>tree[maxn];//有根图储存边

void init()
{
    for(int i=1;i<=n;i++) ve[i].clear();
    for(int i=1;i<=n;i++) tree[i].clear();
    memset(vis,0,sizeof(vis));
    memset(dp,0,sizeof(dp));
}

void build(int root) //让无根图变为有根图
{
    if(vis[root]) return;
    vis[root]=1;
    for(int i=0;i<ve[root].size();i++)
    {
        int son = ve[root][i];
        if(!vis[son])
        {
            tree[root].push_back(son);
            build(son);
        }
    }
}

void dfs(int root)
{
    if(!tree[root].size()) //叶子结点
    {
        for(int i=1;i<=m;i++)
        {
            if(sz[root][i]) dp[root][i]=1;
            else dp[root][i]=0;
        }
        return;
    }
    for(int i=0;i<tree[root].size();i++) //先递归算出子结点的dp
    {
        dfs(tree[root][i]);
    }
    for(int i=1;i<=m;i++)
    {
        if(sz[root][i])
        {
            ll sum=1;
            for(int j=0;j<tree[root].size();j++)
            {
                ll tmp=0;
                int son = tree[root][j];
                for(int k=1;k<=m;k++)
                {
                    if(k!=i) tmp = (tmp+dp[son][k])%mod; //连加算出其子节点再该节点涂i的所有涂法
                }
                sum = (sum*tmp)%mod; //连乘算出该节点涂i颜色时所有涂法
            }
            dp[root][i] = sum;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int a,b;
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
        build(1); //1为根
        dfs(1); //从根开始遍历
        ll ans=0;
        for(int i=1;i<=m;i++)
        {
            ans = (ans+dp[1][i])%mod; //连加算出根节点所有涂法即答案
        }
        printf("%lld\n",ans);
    }
    return 0;
}
