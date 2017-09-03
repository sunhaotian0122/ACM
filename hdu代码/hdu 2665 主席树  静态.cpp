#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int rt[maxn*20],ls[maxn*20],rs[maxn*20],sum[maxn*20];
int a[maxn],b[maxn];
int n,q,ql,qr,k,cnt;

void build(int& root,int l,int r)
{
    root = cnt++;
    sum[root] = 0;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(ls[root],l,mid);
    build(rs[root],mid+1,r);
}

void update(int& root,int l,int r,int last,int x)
{
    root = cnt++;
    ls[root]=ls[last];
    rs[root]=rs[last];
    sum[root] = sum[last]+1;
    if(l==r) return;
    int mid = (l+r)>>1;
    if(x<=mid) update(ls[root],l,mid,ls[last],x);
    else update(rs[root],mid+1,r,rs[last],x);
}

int query(int s,int e,int l,int r,int k)
{
    if(l==r) return l;
    int mid = (l+r)>>1;
    int res = sum[ls[e]]-sum[ls[s]];
    if(k<=res) return query(ls[s],ls[e],l,mid,k);
    else return query(rs[s],rs[e],mid+1,r,k-res);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++) scanf("%d",a+i),b[i]=a[i];
        sort(b,b+n);
        int sz = unique(b,b+n)-b;
        cnt=1;
        build(rt[0],1,sz);
        for(int i=0;i<n;i++)
        {
            a[i] = upper_bound(b,b+sz,a[i])-b;
            update(rt[i+1],1,sz,rt[i],a[i]);
        }
        while(q--)
        {
            scanf("%d%d%d",&ql,&qr,&k);
            int ans = query(rt[ql-1],rt[qr],1,sz,k);
            printf("%d\n",b[ans-1]);
        }
    }
    return 0;
}
