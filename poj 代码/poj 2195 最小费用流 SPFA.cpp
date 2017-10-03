#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

#define PB push_back
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
typedef pair<int,int> P;
char mp[105][105];
int dist[maxn<<1],pe[maxn<<1],head[maxn<<1];
bool vis[maxn<<1];
int n,m,tot;

struct Edge{
    int u,v,cap,cost,next;
    Edge(){}
    Edge(int u,int v,int cap,int cost,int next):u(u),v(v),cap(cap),cost(cost),next(next){}
}edge[maxn<<7];

void add_edge(int from,int to,int cap,int cost)
{
    edge[tot] = Edge(from,to,cap,cost,head[from]);
    head[from] = tot++;
    edge[tot] = Edge(to,from,0,-cost,head[to]);
    head[to] = tot++;
}

bool SPFA(int s,int t)
{
    memset(dist,INF,sizeof(dist));
    memset(vis,false,sizeof(vis));
    memset(pe,-1,sizeof(pe));
    dist[s]=0;
    vis[s]=true;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        vis[u] = false;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int cost = edge[i].cost;
            if(edge[i].cap>0 && dist[v]>dist[u]+cost)
            {
                dist[v] = dist[u]+cost;
                pe[v] = i;
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    if(dist[t]==INF) return false;
    else return true;
}

int min_cost_flow(int s,int t,int f)
{
    int res = 0;
    while(SPFA(s,t))
    {
        int flow = INF;
        for(int i=pe[t];i!=-1;i=pe[edge[i].u])
        {
            flow = min(flow,edge[i].cap);
        }
        f -= flow;
        if(f<0) break;
        for(int i=pe[t];i!=-1;i=pe[edge[i].u])
        {
            edge[i].cap -= flow;
            edge[i^1].cap += flow;
        }
        res += flow*dist[t];
    }
    return res;
}

int dis(P a,P b)
{
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int main()
{
    while(~scanf("%d%d",&n,&m) && (n!=0 && m!=0))
    {
        int num1=0,num2=0;
        P man[maxn],hos[maxn];
        for(int i=1;i<=n;i++)
        {
            scanf("%s",mp[i]);
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='m')
                    man[++num1] = P(i,j+1);
                if(mp[i][j]=='H')
                    hos[++num2] = P(i,j+1);
            }
        }
        int s=0,t=num1+num2+1;
        memset(head,-1,sizeof(head));
        tot=0;
        for(int i=1;i<=num1;i++)
            add_edge(0,i,1,0);
        for(int i=1;i<=num2;i++)
            add_edge(num1+i,t,1,0);
        for(int i=1;i<=num1;i++)
        {
            for(int j=1;j<=num2;j++)
            {
                add_edge(i,num1+j,1,dis(man[i],hos[j]));
            }
        }
        printf("%d\n",min_cost_flow(s,t,num1));
    }
    return 0;
}
