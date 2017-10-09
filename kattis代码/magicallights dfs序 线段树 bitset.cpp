#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5+5;
struct Edge{
    int to,next;
}edge[maxn];
int head[maxn],tot;
int n,q,c[maxn];
int in[maxn],out[maxn],dfsnum[maxn],ti;
bitset<105> col[maxn<<2];

void init()
{
    tot=ti=0;
    memset(head,-1,sizeof(head));
}

void add_edge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int u,int fa)
{
    in[u] = ++ti;
    dfsnum[ti]=u;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
    }
    out[u] = ti;
}

void push_up(int rt)
{
    col[rt] = col[rt<<1]^col[rt<<1|1];
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        col[rt].reset();
        col[rt].set(c[dfsnum[l]]);
        return;
    }
    int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}

void update(int rt,int l,int r,int pos,int color)
{
    if(l==r)
    {
        col[rt].reset();
        col[rt].set(color);
        return;
    }
    int mid = (l+r)>>1;
    if(pos<=mid) update(rt<<1,l,mid,pos,color);
    else update(rt<<1|1,mid+1,r,pos,color);
    push_up(rt);
}

bitset<105> query(int rt,int l,int r,int L,int R)
{
    if(L<=l && r<=R) return col[rt];
    int mid = (l+r)>>1;
    bitset<105> res;
    res.reset();
    if(L<=mid) res = res^query(rt<<1,l,mid,L,R);
    if(mid<R) res = res^query(rt<<1|1,mid+1,r,L,R);
    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&q))
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
        }
        int u,v;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&u);
            add_edge(u,i);
        }
        dfs(1,0);
        build(1,1,n);
        while(q--)
        {
            scanf("%d%d",&u,&v);
            if(u==0) printf("%d\n",query(1,1,n,in[v],out[v]).count());
            else update(1,1,n,in[v],u);
        }
    }
    return 0;
}
