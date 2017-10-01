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

int c[maxn][maxn],f[maxn][maxn],p[maxn],a[maxn],sz[maxn][15];
int m,n,s,t;
struct Node{
    int u,v,w;
    Node(){}
    Node(int u,int v,int w):u(u),v(v),w(w){}
};
vector<Node> ans;

int bfs()
{
    queue<int> q;
    memset(p,-1,sizeof(p));
    memset(a,0,sizeof(a));
    a[s] = INF;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();q.pop();
        for(int i=1;i<=t;i++)
        {
            if(!a[i] && c[u][i]>f[u][i])
            {
                p[i] = u;
                q.push(i);
                a[i] = min(a[u],c[u][i]-f[u][i]);
            }
        }
        if(a[t]) break;
    }
    if(!a[t]) return 0;
    for(int u=t;u!=s;u=p[u])
    {
        f[p[u]][u] += a[t];
        f[u][p[u]] -= a[t];
    }
    return a[t];
}

int Edmonds_Karp()
{
    int res = 0;
    while(true)
    {
        int tmp = bfs();
        if(tmp==0) return res;
        res += tmp;
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
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
        int max_flow=Edmonds_Karp();
        ans.clear();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i!=j && f[i+n][j]>0)
                {
                    ans.PB(Node(i,j,f[i+n][j]));
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
