#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 4e5+5;
struct Edge{
    int to,next;
}edge[maxn<<1];
int head[maxn],tot;
int n,q,c[maxn];
int in[maxn],out[maxn],dfsnum[maxn],ti;
int pco[maxn<<2];
bitset<65> col[maxn<<2];

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
    col[rt] = col[rt<<1]|col[rt<<1|1];
}

void push_down(int rt)
{
    pco[rt<<1]=pco[rt<<1|1]=pco[rt];
    col[rt<<1].reset() , col[rt<<1].set(pco[rt]);
    col[rt<<1|1].reset() , col[rt<<1|1].set(pco[rt]);
    pco[rt]=0;
}

void build(int rt,int l,int r)
{
    pco[rt]=0;
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

void update(int rt,int l,int r,int L,int R,int color)
{
    if(L<=l && r<=R)
    {
        col[rt].reset();
        col[rt].set(color);
        pco[rt] = color;
        return;
    }
    if(pco[rt])
        push_down(rt);
    int mid = (l+r)>>1;
    if(L<=mid) update(rt<<1,l,mid,L,R,color);
    if(mid<R) update(rt<<1|1,mid+1,r,L,R,color);
    push_up(rt);
}

bitset<65> query(int rt,int l,int r,int L,int R)
{
    if(L<=l && r<=R) return col[rt];
    if(pco[rt])
        push_down(rt);
    int mid = (l+r)>>1;
    bitset<65> res;
    res.reset();
    if(L<=mid) res = res|query(rt<<1,l,mid,L,R);
    if(mid<R) res = res|query(rt<<1|1,mid+1,r,L,R);
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
        int op,u,v;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        dfs(1,0);
        build(1,1,n);
        while(q--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%d",&u,&v);
                update(1,1,n,in[u],out[u],v);
            }
            else
            {
                scanf("%d",&u);
                printf("%d\n",query(1,1,n,in[u],out[u]).count());
            }
        }
    }
    return 0;
}
