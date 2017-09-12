#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int dist[maxn],in_queue[maxn];
bool vis[maxn];
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

bool SPFA()
{
    int cur,next;
    queue<int> q;
    vis[0] = true;
    in_queue[0]++;
    dist[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        cur = q.front(),q.pop();
        vis[cur]=false;
        for(int i=head[cur];i!=-1;i=edge[i].next)
        {
            int to = edge[i].to;
            int w = edge[i].w;
            if(dist[to]<dist[cur]+w)
            {
                dist[to] = dist[cur]+w;
                if(!vis[to])
                {
                    in_queue[to]++;
                    if(in_queue[to]>=n+2) return false;
                    q.push(to);
                    vis[to] = true;
                }
            }
        }
    }
    return true;
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
        memset(vis,false,sizeof(vis));
        memset(in_queue,0,sizeof(in_queue));
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
        SPFA();
        printf("%d\n",dist[n+1]);
    }
    return 0;
}
