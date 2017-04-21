#include<bits/stdc++.h>
using namespace std;

const int maxn=40005;
bool vis[maxn];
int dis[maxn],ans[205],root[maxn],n;
vector<int>v[maxn],w[maxn],num[maxn],quest[maxn];

int find_root(int a)
{
    return a==root[a] ? a : root[a]=find_root(root[a]);
}

void munion(int a,int b)
{
    a = find_root(a);
    b = find_root(b);
    if(a==b) return;
    root[b]=a;
}

void init()
{
    for(int i=1;i<=n;i++)
    {
        v[i].clear();
        w[i].clear();
        num[i].clear();
        quest[i].clear();
        vis[i]=false;
        dis[i]=0;
        root[i]=i;
    }
}

void Tarjan(int cnt,int value)
{
    vis[cnt]=true;
    dis[cnt]=value;
    for(int i=0;i<v[cnt].size();i++)
    {
        int tmp=v[cnt][i];
        if(vis[tmp]) continue;
        Tarjan(tmp,value+w[cnt][i]);
        munion(cnt,tmp);
    }
    for(int i=0;i<quest[cnt].size();i++)
    {
        int tmp=quest[cnt][i];
        if(!vis[tmp]) continue;
        ans[num[cnt][i]]=dis[cnt]+dis[tmp]-2*dis[find_root(tmp)];
    }
}

int main()
{
    int T,a,b,m,k;
    scanf("%d",&T);
    while(T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&k);
            v[a].push_back(b);
            w[a].push_back(k);
            v[b].push_back(a);
            w[b].push_back(k);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            quest[a].push_back(b);
            quest[b].push_back(a);
            num[a].push_back(i);
            num[b].push_back(i);
        }
        Tarjan(1,0);
        for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}
