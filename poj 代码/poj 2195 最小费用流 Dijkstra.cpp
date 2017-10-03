#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;

#define PB push_back
const int INF = 0x3f3f3f3f;
const int maxn = 105;
typedef pair<int,int> P;
char mp[maxn][maxn];
int dist[maxn<<1],pv[maxn<<1],pe[maxn<<1];
int n,m;

struct Node{
    int to,cap,cost,rev;
    Node(int to,int cap,int cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
};
vector<Node> edge[maxn<<1];

void add_edge(int from,int to,int cap,int cost)
{
    edge[from].PB(Node(to,cap,cost,edge[to].size()));
    edge[to].PB(Node(from,0,-cost,edge[from].size()-1));
}

int min_cost_flow(int s,int t,int f)
{
    int res = 0;
    while(f>0)
    {
        memset(dist,INF,sizeof(dist));
        dist[s]=0;
        priority_queue<P,vector<P>,greater<P> > pq;
        pq.push(P(0,s));
        while(!pq.empty())
        {
            P cur = pq.top();pq.pop();
            int u = cur.second;
            for(int i=0;i<edge[u].size();i++)
            {
                Node &node = edge[u][i];
                int v = node.to;
                if(node.cap>0 && dist[v]>dist[u]+node.cost)
                {
                    dist[v] = dist[u]+node.cost;
                    pv[v] = u;
                    pe[v] = i;
                    pq.push(P(dist[v],v));
                }
            }
        }
        if(dist[t]==INF) return -1;
        int flow = f;
        for(int i=t;i!=s;i=pv[i])
        {
            flow = min(flow,edge[pv[i]][pe[i]].cap);
        }
        f -= flow;
        res += flow*dist[t];
        for(int i=t;i!=s;i=pv[i])
        {
            Node &node = edge[pv[i]][pe[i]];
            node.cap -= flow;
            edge[i][node.rev].cap += flow;
        }
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
        for(int i=s;i<=t;i++)
            edge[i].clear();
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
