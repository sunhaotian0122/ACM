#include <bits/stdc++.h>
using namespace std;

const int maxn = 8e5+5;
const int maxm = 4e5+5;
int T[maxn],L[maxn*20],R[maxn*20],sum[maxn*20];
int sz[maxm],h[maxn];
int tot,num;

struct node{
    int l,r,x,k1,k2;
}Q[maxm];

void build(int& rt,int l,int r)
{
    rt = ++tot;
    sum[rt] = 0;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(L[rt],l,mid);
    build(R[rt],mid+1,r);
}

void update(int& rt,int pre,int x,int l,int r)
{
    rt = ++tot;
    L[rt] = L[pre];
    R[rt] = R[pre];
    sum[rt] = sum[pre]+1;
    if(l==r) return;
    int mid = (l+r)>>1;
    if(x<=mid) update(L[rt],L[pre],x,l,mid);
    else update(R[rt],R[pre],x,mid+1,r);
}

int query(int s,int e,int l,int r,int k)
{
    if(l==r) return l;
    int res = sum[L[e]]-sum[L[s]];
    int mid = (l+r)>>1;
    if(k<=res) return query(L[s],L[e],l,mid,k);
    else query(R[s],R[e],mid+1,r,k-res);
}

int query_num(int x,int s,int e,int l,int r)
{
    if(r<=x) return sum[e]-sum[s];
    else if(x<l) return 0;
    else
    {
        int mid = (l+r)>>1;
        return query_num(x,L[s],L[e],l,mid)+query_num(x,R[s],R[e],mid+1,r);
    }
}

int main()
{
    int n,m;
    num=tot=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",sz+i),h[++num]=sz[i];
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d%d%d",&Q[i].l,&Q[i].r,&Q[i].x,&Q[i].k1,&Q[i].k2);
        h[++num] = Q[i].x;
    }
    sort(h+1,h+1+num);
    int tmp = unique(h+1,h+1+num)-h-1;
    num = tmp;
    build(T[0],1,num);
    for(int i=1;i<=n;i++) update(T[i],T[i-1],lower_bound(h+1,h+1+num,sz[i])-h,1,num);
    int ans,cnt;
    for(int i=1;i<=m;i++)
    {
        cnt=query_num(lower_bound(h+1,h+1+num,Q[i].x)-h,T[Q[i].l-1],T[Q[i].r],1,num);
        printf("%d ",Q[i].k1<=cnt ? h[query(T[Q[i].l-1],T[Q[i].r],1,num,Q[i].k1)] : -1);
        int tmp = sum[T[Q[i].r]]-sum[T[Q[i].l-1]]-cnt;
        printf("%d\n",Q[i].k2<=tmp ? h[query(T[Q[i].l-1],T[Q[i].r],1,num,cnt+Q[i].k2)] : -1);
    }
    return 0;
}
