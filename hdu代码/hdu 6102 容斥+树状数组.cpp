#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
int sz[maxn],tmp[maxn],v[maxn],n,m,l,r,num;
ll c[maxn];
vector<P> state[maxn];
vector<int> prime[maxn];
bool vis[maxn];
int ie[maxn];
vector<P> q[maxn];
ll ans[maxn];

void init()
{
    memset(vis,true,sizeof(vis));
    for(int i=0;i<maxn;i++)
    {
        prime[i].clear();
        state[i].clear();
    }
    for(int i=2;i<maxn;i++)
    {
        if(vis[i])
        {
            for(int j=i;j<maxn;j+=i)
            {
                prime[j].push_back(i);
                vis[j] = false;
            }
        }
    }
    for(int i=2;i<maxn;i++)
    {
        for(int j=0;j<(1<<prime[i].size());j++)
        {
            state[i].push_back(make_pair(1,1));
            for(int k=0;k<prime[i].size();k++)
            {
                if((j>>k)&1)
                {
                    state[i][j].first *= prime[i][k];
                    state[i][j].second *= -1;
                }
            }
        }
    }
}

void add(int x,int value)
{
    for(int i=0;i<state[x].size();i++)
    {
        ie[state[x][i].first] += value;
    }
}

int get(int x)
{
    int res = 0;
    for(int i=0;i<state[x].size();i++)
    {
        res += ie[state[x][i].first]*state[x][i].second;
    }
    return res;
}

int lowbit(int x)
{
    return x&(-x);
}

void update(int x,ll value)
{
    while(x<=n)
    {
        c[x] += value;
        x += lowbit(x);
    }
}

ll query(int x)
{
    ll res=0;
    while(x>0)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

int main()
{
    int t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        memset(v,INF,sizeof(v));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sz[i]);
            v[sz[i]] = i;
            q[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&l,&r);
            q[r].push_back(P(i,l));
        }
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            num=0;
            memset(ie,0,sizeof(0));
            for(int j=2*sz[i];j<maxn;j+=sz[i])
            {
                if(v[j]<i) tmp[++num] = v[j];
            }
            sort(tmp+1,tmp+num+1);
            tmp[0]=0;
            ll sum = 0;
            for(int j=num;j>0;j--)
            {
                sum += get(sz[tmp[j]]/sz[i])*sz[i];
                add(sz[tmp[j]]/sz[i],1);
                update(tmp[j-1]+1,sum);
                update(tmp[j]+1,-sum);
            }
            for(int j=num;j>0;j--) add(sz[tmp[j]]/sz[i],-1);
            for(int j=0;j<q[i].size();j++) ans[q[i][j].first] = query(q[i][j].second);
        }
        for(int i=1;i<=m;i++)
        {
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}
