#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

struct EDGE
{
    int cost, cap, v;
    int next, re;
}edge[maxn<<1];
int head[maxn], e;
int vis[maxn], d[maxn];
int ans, cost, src, des;
int n,m,k;

void init()
{
    memset(head, -1, sizeof(head));
    e = 0;
    ans = cost = 0;
}

void add(int u, int v, int cap, int cost)
{
    edge[e].v = v;
    edge[e].cap = cap;
    edge[e].cost = cost;
    edge[e].re = e + 1;
    edge[e].next = head[u];
    head[u] = e++;
    edge[e].v = u;
    edge[e].cap = 0;
    edge[e].cost = -cost;
    edge[e].re = e - 1;
    edge[e].next = head[v];
    head[v] = e++;
}

int aug(int u, int f)
{
    if(u == des)
    {
        ans += cost * f;
        return f;
    }
    vis[u] = 1;
    int tmp = f;
    for(int i = head[u]; i != -1; i = edge[i].next)
        if(edge[i].cap && !edge[i].cost && !vis[edge[i].v])
        {
            int delta = aug(edge[i].v, tmp < edge[i].cap ? tmp : edge[i].cap);
            edge[i].cap -= delta;
            edge[edge[i].re].cap += delta;
            tmp -= delta;
            if(!tmp) return f;
        }
    return f - tmp;
}

bool modlabel()
{
    for(int i = 0; i <= des; i++) d[i] = INF;
    d[des] = 0;
    deque<int>Q;
    Q.push_back(des);
    while(!Q.empty())
    {
        int u = Q.front(), tmp;
        Q.pop_front();
        for(int i = head[u]; i != -1; i = edge[i].next)
            if(edge[edge[i].re].cap && (tmp = d[u] - edge[i].cost) < d[edge[i].v])
                (d[edge[i].v] = tmp) <= d[Q.empty() ? src : Q.front()] ? Q.push_front(edge[i].v) : Q.push_back(edge[i].v);
    }
    for(int u = 0; u <= des; u++)
        for(int i = head[u]; i != -1; i = edge[i].next)
            edge[i].cost += d[edge[i].v] - d[u];
    cost += d[src];
    return d[src] < INF;
}

void costflow(int flow)
{
    int x,tmp=0;
    while(modlabel())
    {
        do
        {
            memset(vis, 0, sizeof(vis));
            x = aug(src, INF);
            if(x>0) tmp += x;
        }while(x>0);
    }
    if(tmp!=flow) ans = -1;
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k) && (n!=0 && m!=0 &&k!=0))
    {
        init();
        src = 0, des = m+m*k+n*k+n+1;
        for(int i=1;i<=m;i++)
            add(0,i,INF,0);
        for(int i=1;i<=n;i++)
            add(m+m*k+n*k+i,des,INF,0);
        int x,flow=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&x);
                flow += x;
                add(m+m*k+(i-1)*k+j,m+m*k+n*k+i,x,0);
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=k;j++)
            {
                scanf("%d",&x);
                add(i,m+(i-1)*k+j,x,0);
            }
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int o=1;o<=m;o++)
                {
                    scanf("%d",&x);
                    add(m+(o-1)*k+i,m+m*k+(j-1)*k+i,INF,x);
                }
            }
        }
        costflow(flow);
        printf("%d\n", ans);
    }
    return 0;
}
