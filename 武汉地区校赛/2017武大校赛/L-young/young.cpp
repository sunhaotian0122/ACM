#include <bits/stdc++.h>
#define MOD 1000000007
#define N 100005
#define max(x, y) ((x) > (y) ? (x) : (y))
using namespace std;
int n,q,M,MAXN,a[N],sum_v,Ans[N],value[N],val[4*N];
typedef vector<int> vc;
vc G[N],query[N],vec[20];
map<int,int> son[N];
struct thing
{
        int l,r,x;
        vc num;
}ask[N];
void Update(int p, int v)
{
    p += M;
    val[p] = v;
    while(p > 1)
	{
        p >>= 1;
        val[p] = max(val[p<<1], val[p<<1|1]);
    }
}
int Query(int l, int r) //[l, r]
{
    int ans = 0;
    for(l = l + M - 1, r = r + M + 1; l^r^1; l >>= 1, r >>= 1)
	{
        if(~l&1) ans = max(val[l^1], ans); //l为偶数
        if(r&1) ans = max(val[r^1], ans); //r为奇数
    }
    return ans;
}
vc deal(int x)
{
        int l = 0;
        vc t;
        if(x == 1)
        {
                t.push_back(1);
                return t;
        }
        for(int i = 2;i <= sqrt(x)+1;i++)
         if(x % i == 0)
         {
                 while(x % i == 0) x /= i;
                 t.push_back(i);
         }
        if(x != 1) t.push_back(x);
        return t;
}
void Insert(vc t,int lab)
{
        int l = t.size(),u = 1;
        if(t[0] == 1)
        {
                query[1].push_back(lab);
                return;
        }
        for(int i = 1;i <= l;i++)
        {
                if(!son[u][t[i-1]])
                {
                        son[u][t[i-1]] = ++sum_v;
                        value[sum_v] = t[i-1];
                }
                u = son[u][t[i-1]];
        }
        query[u].push_back(lab);
}
void dfs(int u,int pre,int deep)
{
        for(int i = 0;i < query[u].size();i++)
        {
                int num = query[u][i];
                int ans = Query(ask[num].l,ask[num].r);
                Ans[num] = ans ? ans : -1;
        }
        map<int,int> :: iterator it = son[u].begin();
        for(;it != son[u].end();it++)
        {
                int v = it->second;
                for(int j = 1;j*value[v] <= MAXN;j++)
                 if(__gcd(j*value[v],pre) == 1)
                 {
                         for(int k = 0;k < G[j*value[v]].size();k++)
                         {
                                 int pos = G[j*value[v]][k];
                                 Update(pos,0);
                                 vec[deep].push_back(pos);
                         }
                 }
                dfs(v,pre*value[v],deep+1);
              	for(int i = 0;i < vec[deep].size();i++) Update(vec[deep][i],a[vec[deep][i]]);
              	vec[deep].clear();
        }
}
int main()
{
	    MAXN = 0;
        scanf("%d%d",&n,&q);
        for(M = 1; M < n + 2; M <<= 1);
        for(int i = 1;i <= n;i++)
        {
                scanf("%d",&a[i]);
                G[a[i]].push_back(i);
                MAXN = max(a[i],MAXN);
        }
        sum_v = 1;
        for(int i = 1;i <= q;i++)
        {
        		scanf("%d%d%d",&ask[i].l,&ask[i].r,&ask[i].x);
                ask[i].num = deal(ask[i].x);
                Insert(ask[i].num,i);
        }
        for(int i = 1;i <= n;i++) Update(i,a[i]);
        dfs(1,1,1);
        for(int i = 1;i <= q;i++) cout<<Ans[i]<<endl;
}