#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int maxm = 1e6+5;

struct Edge{
    int u,v,next;
    Edge(){}
    Edge(int u,int v,int next):u(u),v(v),next(next){}
}edge[maxm];
int tot,head[maxn];

int ti,top,num,sta[maxn],belong[maxn],dfn[maxn],low[maxn],in[maxn];
bool vis[maxn];

struct Node{
    ll x,y,r;
    int w;
}P[maxn];
int n,ans;

void init()
{
    tot=num=ti=top=0;
    memset(head,-1,sizeof(head));
    memset(belong,0,sizeof(belong));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(in,0,sizeof(in));
    memset(vis,false,sizeof(vis));
}

bool InCircle(Node a,Node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)<=(a.r*a.r) ? true : false;
}

void add_edge(int u,int v)
{
    edge[tot] = Edge(u,v,head[u]);
    head[u]=tot++;
}

void tarjan(int u)
{
    vis[u]=true;
    dfn[u] = low[u] = ++ti;
    sta[top++]=u;
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(vis[v])
        {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        ++num;
        int now;
        do{
            now = sta[--top];
            belong[now] = num;
            vis[now] = false;
        }while(now!=u);
    }
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    for(int u=1;u<=n;u++)
    {
        for(int i=head[u];~i;i=edge[i].next)
        {
            int v = edge[i].v;
            if(belong[u]!=belong[v])
                in[belong[v]]++;
        }
    }
    ans = 0;
    for(int i=1;i<=num;i++)
    {
        if(!in[i])
        {
            int mi = INF;
            for(int j=1;j<=n;j++)
            {
                if(belong[j]==i)
                    mi = min(mi,P[j].w);
            }
            ans += mi;
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld%d",&P[i].x,&P[i].y,&P[i].r,&P[i].w);
        }
        init();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j && InCircle(P[i],P[j]))
                    add_edge(i,j);
            }
        }
        solve();
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
