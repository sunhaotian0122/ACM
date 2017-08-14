#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

ll n,m;
ll dis[maxn];
struct Node{
    ll l,r;
}tmp[maxn],node[maxn];

bool cmp(Node a,Node b)
{
    if(a.l==b.l) return a.r<b.r;
    else return a.l<b.l;
}


int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        for(int i=0;i<n;i++) scanf("%lld%lld",&tmp[i].l,&tmp[i].r);
        sort(tmp,tmp+n,cmp);
        int num=1;
        node[num] = tmp[0];
        for(int i=1;i<n;i++)
        {
            if(tmp[i].l<=node[num].r+1) node[num].r = max(node[num].r,tmp[i].r);
            else node[++num] = tmp[i];
        }
        for(int i=1;i<num;i++) dis[i] = node[i+1].l-node[i].r-1;
        ll res=0,ans=-1;
        int cnt=1;
        for(int i=1;i<num;i++)
        {
            res += dis[i];
            while(res>m) res -= dis[cnt++];
            ans = max(ans,node[i+1].r-node[cnt].l+1+m-res);
        }
        ans = max(ans,node[1].r-node[1].l+1+m);
        printf("%lld\n",ans);
    }
    return 0;
}
