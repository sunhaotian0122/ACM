#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 505;
const int maxn = 1005;
struct Edge{
    int to,next;
}edge[INF*INF];
int tot,head[maxn];
int mat[maxn],fa[maxn];
int n,s,ans;

void add_edge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void Hungarian()
{
    memset(mat,-1,sizeof(mat));
    memset(fa,-1,sizeof(fa));
    int pv[maxn];
    ans=0;
    for(int i=1;i<=n;i++)
    {
        if(mat[i]==-1)
        {
            queue<int> q;
            pv[i] = -1;
            q.push(i);
            bool flag = false;
            while(!q.empty() && !flag)
            {
                int u = q.front();q.pop();
                for(int j=head[u];~j && !flag;j=edge[j].next)
                {
                    int v = edge[j].to;
                    if(fa[v]!=i)
                    {
                        fa[v]=i;
                        q.push(mat[v]);
                        if(mat[v]==-1)
                        {
                            flag = true;
                            int d=u,e=v;
                            while(~d)
                            {
                                int t = mat[d];
                                mat[d] = e;
                                mat[e] = d;
                                d = pv[d];
                                e = t;
                            }
                        }
                        else
                        {
                            pv[mat[v]] = u;
                        }
                    }
                }
            }
            if(~mat[i]) ans++;
        }
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
        Hungarian();
        if(ans==n) puts("Yes");
        else puts("No");
    }
    return 0;
}
