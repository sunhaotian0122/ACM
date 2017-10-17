#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAX = 505;
const int maxn = 1005;
struct Edge{
    int to,cap,next;
    Edge(){}
    Edge(int to,int cap,int next):to(to),cap(cap),next(next){}
}edge[MAX*MAX*2];
int tot,head[maxn];
int n,s,ans,S,T;
bool vis[maxn];

void add_edge(int u,int v)
{
    edge[tot] = Edge(v,1,head[u]);
    head[u] = tot++;
    edge[tot] = Edge(u,0,head[v]);
    head[v] = tot++;
}

int dfs(int s,int t,int f)
{
    if(s==t) return f;
    vis[s]=true;
    for(int i=head[s];~i;i=edge[i].next)
    {
        Edge &cur = edge[i];
        if(!vis[cur.to] && cur.cap>0)
        {
            int tmp = dfs(cur.to,t,min(f,cur.cap));
            if(tmp>0)
            {
                cur.cap -= tmp;
                edge[i^1].cap += tmp;
                return tmp;
            }
        }
    }
    return 0;
}

int Ford_Fulkerson()
{
    int res = 0;
    while(true)
    {
        memset(vis,false,sizeof(vis));
        int flow = dfs(S,T,INF);
        if(flow==0) return res;
        res += flow;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int t;
    cin>>t;
    for(int ca=1;ca<=t;ca++)
    {
        cin>>n>>s;
        tot=0;
        memset(head,-1,sizeof(head));
        printf("Case #%d: ",ca);
        if(s<n) swap(s,n);
        if(n>MAX)
        {
            puts("No");
            continue;
        }
        S = 0, T = n<<1|1;
        for(int i=1;i<=n;i++)
        {
            add_edge(S,i);
            add_edge(n+i,T);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((s+j)%i==0)
                    add_edge(i,n+j);
            }
        }
        ans = Ford_Fulkerson();
        if(ans==n) puts("Yes");
        else puts("No");
    }
    return 0;
}
