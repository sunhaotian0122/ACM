#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
typedef pair<int,int> P;
int dist[maxn];
int n;

struct Edge{
    int to,w,next;
}edge[maxn<<2];
int head[maxn],tot;

void add_edge(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Dijkstra()
{
    priority_queue<P> pq;
    P p;
    dist[0]=0;
    pq.push(P(dist[0],0));
    while(!pq.empty())
    {
        p = pq.top(),pq.pop();
        int u = p.second;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].w;
            if(dist[v]<dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push(P(dist[v],v));
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        tot=0;
        memset(head,-1,sizeof(head));
        memset(dist,-INF,sizeof(dist));
        int u,v,w;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w);
            add_edge(0,i,-w);
            add_edge(i,n+1,w);
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,-w);
            add_edge(v,u,-w);
        }
        Dijkstra();
        printf("%d\n",dist[n+1]);
    }
    return 0;
}
