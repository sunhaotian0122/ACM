#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e18;
const int maxn = 6e4+5;
typedef pair<ll,int> P;
ll dist[5][maxn],k,d1,d2,d3,d4,mi;

struct Edge{
    int to;
    ll w;
    Edge(int _to,ll _w)
    {
        to = _to;
        w = _w;
    }
};

vector<Edge> edge[5];

void add_edge(int from,int to,ll w)
{
    edge[from].push_back(Edge(to,w));
    edge[to].push_back(Edge(from,w));
}

void Dijkstra()
{
    for(int i=1;i<5;i++) fill(dist[i],dist[i]+mi,INF);
    P cur;
    priority_queue<P,vector<P>,greater<P> >pq;
    dist[2][0] = 0;
    pq.push(P(0,2));
    while(!pq.empty())
    {
        cur = pq.top(),pq.pop();
        int u = cur.second;
        if(cur.first > dist[u][cur.first%mi]) continue;
        for(int i=0;i<edge[u].size();i++)
        {
            int v = edge[u][i].to;
            ll dis = dist[u][cur.first%mi]+edge[u][i].w;
            if(dis < dist[v][dis%mi])
            {
                dist[v][dis%mi] = dis;
                pq.push(P(dis,v));
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
        for(int i=0;i<5;i++) edge[i].clear();
        scanf("%lld%d%d%d%d",&k,&d1,&d2,&d3,&d4);
        add_edge(1,2,d1);
        add_edge(2,3,d2);
        add_edge(3,4,d3);
        add_edge(4,1,d4);
        mi = 2*min(d1,d2);
        Dijkstra();
        ll ans = INF;
        for(ll i=0;i<mi;i++)
        {
            if(dist[2][i]>=k) ans = min(ans,dist[2][i]);
            else
            {
                ll tmp = k-dist[2][i];
                ans = min(ans,dist[2][i]+tmp/mi*mi+(tmp%mi>0)*mi);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
