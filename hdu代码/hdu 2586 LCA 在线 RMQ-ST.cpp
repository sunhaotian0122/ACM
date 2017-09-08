#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 4e4+5;
int n,m;
int dp[maxn*2][20];
int p[maxn*2],deep[maxn*2],first[maxn],dis[maxn];
bool vis[maxn];

struct node{
    int to,w,next;
}edge[maxn*2];
int tot,head[maxn];

void init()
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    memset(dis,0,sizeof(dis));
}

void add_edge(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot++;
}

void dfs(int u,int dep)
{
    p[++tot]=u;
    first[u]=tot;
    deep[tot]=dep;
    vis[u]=true;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(!vis[v])
        {
            int w = edge[i].w;
            dis[v] = dis[u]+w;
            dfs(v,dep+1);
            p[++tot]=u;
            deep[tot]=dep;
        }
    }
}

void ST(int len)
{
    for(int i=1;i<=len;i++) dp[i][0]=i;
    int k = (int)(log((double)len)/log(2.0));
    for(int j=1;j<=k;j++)
    {
        for(int i=1;i+(1<<j)-1<=len;i++)
        {
            int a = dp[i][j-1],b=dp[i+(1<<(j-1))][j-1];
            dp[i][j] = deep[a]<deep[b] ? a : b;
        }
    }
}

int RMQ(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    int a=dp[l][k],b=dp[r-(1<<k)+1][k];
    return deep[a]<deep[b] ? a : b;
}

int LCA(int u,int v)
{
    int l=first[u],r=first[v];
    if(l>r) swap(l,r);
    return p[RMQ(l,r)];
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init();
        int u,v,w;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
        }
        tot=0;
        dfs(1,1);
        ST(tot);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&u,&v);
            printf("%d\n",dis[u]+dis[v]-2*dis[LCA(u,v)]);
        }
    }
    return 0;
}
