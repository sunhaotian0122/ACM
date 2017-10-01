#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

#define PB push_back
const int INF = 0x3f3f3f3f;
const int maxn = 105;

int c[maxn][maxn],dep[maxn],sz[maxn][15];
int m,n,s,t;
struct Node{
    int u,v,w;
    Node(){}
    Node(int u,int v,int w):u(u),v(v),w(w){}
};
vector<Node> ans;

bool bfs()
{
    queue<int> q;
    memset(dep,-1,sizeof(dep));
    dep[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int v=1;v<=t;v++)
        {
            if(c[u][v]>0 && dep[v]==-1)
            {
                dep[v] = dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[t] != -1;
}

int dfs(int u,int flow)
{
    if(u==t) return flow;
    int tmp;
    for(int v=1;v<=t;v++)
    {
        if(c[u][v]>0 && dep[v]==dep[u]+1 && (tmp=dfs(v,min(flow,c[u][v]))))
        {
            c[u][v] -= tmp;
            c[v][u] += tmp;
            return tmp;
        }
    }
    return 0;
}

int Dinic()
{
    int res = 0,tmp;
    while(bfs())
    {
        while((tmp=dfs(s,INF)))
        {
            res += tmp;
        }
    }
    return res;
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(c,0,sizeof(c));
        s = 0; t = n<<1|1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&c[i][i+n]);
            bool flag=true;
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&sz[i][j]);
                if(sz[i][j]==1) flag=false;
            }
            if(flag) c[s][i] = INF;
            flag=true;
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&sz[i+n][j]);
                if(sz[i+n][j]!=1) flag=false;
            }
            if(flag) c[i+n][t] = INF;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=n+1;j<t;j++)
            {
                if(j==i+n) continue;
                bool flag=true;
                for(int k=1;k<=m;k++)
                {
                    if(sz[j][k]+sz[i][k]==1)
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag) c[j][i] = INF;
            }
        }
        int max_flow=Dinic();
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j && c[i][j+n]>0)
                {
                    ans.PB(Node(j,i,c[i][j+n]));
                }
            }
        }
        printf("%d %d\n",max_flow,ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%d %d %d\n",ans[i].u,ans[i].v,ans[i].w);
        }
    }
    return 0;
}
