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

int c[maxn][maxn],p[maxn],lev[maxn],gap[maxn],sz[maxn][15];
int m,n,s,t;
struct Node{
    int u,v,w;
    Node(){}
    Node(int u,int v,int w):u(u),v(v),w(w){}
};
vector<Node> ans;

int SAP()
{
    memset(lev,0,sizeof(lev));
    memset(gap,0,sizeof(gap));
    memset(p,-1,sizeof(p));
    gap[0] = t+1;
    int v,u=p[s]=s,res=0,tmp;
    while(lev[s]<t+1)
    {
        for(v=0;v<=t;v++)
        {
            if(c[u][v]>0 && lev[u]==lev[v]+1)
                break;
        }
        if(v<=t)
        {
            p[v] = u;
            u = v;
            if(v==t)
            {
                tmp = INF;
                for(int i=t;i!=s;i=p[i])
                {
                    if(c[p[i]][i]<tmp)
                    {
                        tmp = c[p[i]][i];
                    }
                }
                res += tmp;
                for(int i=t;i!=s;i=p[i])
                {
                    c[p[i]][i] -= tmp;
                    c[i][p[i]] += tmp;
                }
                u = s;
            }
        }
        else
        {
            int min_lev = t+1;
            for(v=0;v<=t;v++)
            {
                if(c[u][v]>0 && lev[v]<min_lev)
                    min_lev = lev[v];
            }
            gap[lev[u]]--;
            if(gap[lev[u]]==0) break;
            lev[u] = min_lev+1;
            gap[lev[u]]++;
            u = p[u];
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
        int max_flow=SAP();
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
