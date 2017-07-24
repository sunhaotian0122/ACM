#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 505;
int n,m;
int dist[maxn],vis[maxn],inqueue_num[maxn];
struct Edge{
    int to,len;
};
vector<Edge> edge[maxn];

void init()
{
    memset(dist,INF,sizeof(dist));
    memset(vis,0,sizeof(vis));
    memset(inqueue_num,0,sizeof(inqueue_num));
    for(int i=0;i<=n;i++) edge[i].clear();
}

bool SPFA()
{
    int x;
    queue<int>q;
    dist[1]=0,vis[1]=1,inqueue_num[1]++;
    q.push(1);
    while(!q.empty())
    {
        x = q.front(),q.pop();
        vis[x]=0;
        for(int i=0;i<edge[x].size();i++)
        {
            int y=edge[x][i].to;
            int len=edge[x][i].len;
            if(dist[y]>dist[x]+len)
            {
                dist[y] = dist[x]+len;
                if(!vis[y])
                {
                    q.push(y);
                    vis[y]=1;
                    inqueue_num[y]++;
                    if(inqueue_num[y]>=n) return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int u,v,w;
    Edge tmp;
    init();
    scanf("%d%d",&n,&m);
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&w);
        tmp.to = v,tmp.len = w;
        edge[u].push_back(tmp);
        tmp.to = u,tmp.len = -w;
        edge[v].push_back(tmp);
    }
    if(SPFA())
    {
        int k=INF;
        for(int i=1;i<=n;i++) k = min(k,dist[i]);
        for(int i=1;i<=n;i++) printf("%d\n",dist[i]-k);
    }
    else printf("-1\n");
    return 0;
}
