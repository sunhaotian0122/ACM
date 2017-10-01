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
const int maxn = 405;

int c[maxn][maxn],dep[maxn];
int n,f,d,s,t;

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
    while(~scanf("%d%d%d",&n,&f,&d))
    {
        memset(c,0,sizeof(c));
        s = 0; t = f+n+n+d+1;
        for(int i=1;i<=f;i++) c[s][i]=1;
        for(int i=1;i<=d;i++) c[f+n+n+i][t]=1;
        int a,b,x;
        for(int i=1;i<=n;i++)
        {
            c[f+i][f+n+i] = 1;
            scanf("%d%d",&a,&b);
            for(int j=1;j<=a;j++)
            {
                scanf("%d",&x);
                c[x][f+i]=1;
            }
            for(int j=1;j<=b;j++)
            {
                scanf("%d",&x);
                c[f+n+i][f+n+n+x]=1;
            }
        }
        printf("%d\n",Dinic());
    }
    return 0;
}
