#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e6+3;
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
struct Edge{
    int to,next;
    Edge(){}
    Edge(int to,int next):to(to),next(next){}
}edge[maxn<<1];
int tot,head[maxn];
int inv[mod+5]; //[1-mod]在mod下的逆元
ll v[maxn];     //节点权值
int all;        //树的节点总数
int rt;         //树的重心
int sum[maxn];  //子树大小
int sma[maxn];  //节点最大子树大小
bool vis[maxn]; //该节点是否作为重心过
int mp[mod+5];  //hash后数组
ll w[maxn];     //重心到点的权值的乘积和
int id[maxn];   //w[]对应节点
int ansl,ansr;  //答案
int n;
ll k;

void init_inv()
{
    inv[1] = 1;
    for(int i=2;i<mod;i++)
        inv[i] = (mod - mod / i) * 1ll * inv[mod%i] % mod;
}

void init()
{
    tot     =   0;
    ansl    =   ansr    =   INF;
    all     =   n;
    rt      =   0;
    sma[0]  =   INF;
    memset(head,-1,sizeof(head));
    memset(mp,0,sizeof(mp));
    memset(vis,false,sizeof(vis));
}

void add_edge(int u,int v)
{
    edge[tot]   =   Edge(v,head[u]);
    head[u]     =   tot++;
    edge[tot]   =   Edge(u,head[v]);
    head[v]     =   tot++;
}

void get_root(int u,int fa)
{
    sma[u] = 0;
    sum[u] = 1;
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v] || fa==v) continue;
        get_root(v,u);
        sum[u] += sum[v];
        sma[u] = max(sma[u],sum[v]);
    }
    sma[u] = max(sma[u],all-sum[u]);
    if(sma[u]<sma[rt])
        rt = u;
}

void get_deep(int u,int fa,ll now)
{
    ll res = now*v[u]%mod;
    w[++w[0]] = res;
    id[w[0]]  = u;
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v] || v==fa) continue;
        get_deep(v,u,res);
    }
}

void update(int u,ll res,int idl)
{
    int idr = mp[inv[res*v[u]%mod]*k%mod];
    if(!idr) return;
    if(idr<idl) swap(idl,idr);
    if(idl<ansl || (idl==ansl && idr<ansr))
        ansl = idl, ansr = idr;
}

void solve(int u)
{
    vis[u] = true;
    mp[1]  = u;
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]) continue;
        w[0] = 0;
        get_deep(v,u,1);
        for(int j=1; j<=w[0]; j++)
            update(u,w[j],id[j]);
        for(int j=1; j<=w[0]; j++)
            if(!mp[w[j]] || id[j]<mp[w[j]])
                mp[w[j]] = id[j];
    }
    mp[1] = 0;
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]) continue;
        w[0] = 0;
        get_deep(v,u,1);
        for(int j=1; j<=w[0]; j++)
            mp[w[j]] = 0;
    }
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v = edge[i].to;
        if(vis[v]) continue;
        rt = 0;
        all = sum[v];
        get_root(v,u);
        solve(rt);
    }
}

int main()
{
    init_inv();
    while(~scanf("%d%lld",&n,&k))
    {
        init();
        for(int i=1;i<=n;i++)
            scanf("%lld",v+i);
        int u,v;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        get_root(1,0);
        solve(rt);
        if(ansl==INF)
            printf("No solution\n");
        else
            printf("%d %d\n",ansl,ansr);
    }
    return 0;
}
