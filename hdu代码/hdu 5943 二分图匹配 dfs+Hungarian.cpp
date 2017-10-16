#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 505;
const int maxn = 1005;
struct Edge{
    int to,next;
}edge[INF*INF];
int tot,head[maxn];
int mat[maxn];
bool vis[maxn];

void add_edge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

bool dfs(int u)
{
    for(int i=head[u];~i;i=edge[i].next)
    {
        int v = edge[i].to;
        if(!vis[v])
        {
            vis[v]=true;
            if(mat[v]==-1 || dfs(mat[v]))
            {
                mat[v] = u;
                mat[u] = v;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    int t,n,s;
    cin>>t;
    for(int ca=1;ca<=t;ca++)
    {
        cin>>n>>s;
        tot=0;
        memset(head,-1,sizeof(head));
        memset(mat,-1,sizeof(mat));
        printf("Case #%d: ",ca);
        if(s<n) swap(s,n);
        if(n>INF)
        {
            puts("No");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((s+j)%i==0)
                    add_edge(i,n+j);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            memset(vis,false,sizeof(vis));
            if(dfs(i)) ans++;
        }
        if(ans==n) puts("Yes");
        else puts("No");
    }
    return 0;
}
