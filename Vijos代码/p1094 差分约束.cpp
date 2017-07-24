#include <bits/stdc++.h>
using namespace std;

const int INF = -0x3f3f3f3f;
const int maxn = 1e3+5;
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
    dist[0]=0,vis[0]=1,inqueue_num[0]++;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        x = q.front(),q.pop();
        vis[x]=0;
        for(int i=0;i<edge[x].size();i++)
        {
            int y=edge[x][i].to;
            int len=edge[x][i].len;
            if(dist[y]<dist[x]+len)
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
    init();
    scanf("%d%d",&n,&m);
    int u,v,c;
    Edge tmp;
    while(m--)
    {
        scanf("%d%d%d",&u,&v,&c);
        if(c==1)
        {
            tmp.to=u,tmp.len=1;
            edge[v].push_back(tmp);
        }
        else if(c==0)
        {
            tmp.to=v,tmp.len=0;
            edge[u].push_back(tmp);
            tmp.to=u,tmp.len=0;
            edge[v].push_back(tmp);
        }
        else
        {
            tmp.to=v,tmp.len=1;
            edge[u].push_back(tmp);
        }
    }
    for(int i=1;i<=n;i++)
    {
        tmp.to=i,tmp.len=0;
        edge[0].push_back(tmp);
    }
    if(SPFA())
    {
        int ans=INF;
        for(int i=1;i<=n;i++) ans = max(ans,dist[i]);
        printf("%d\n",ans);
    }
    else printf("NO\n");
    return 0;
}
