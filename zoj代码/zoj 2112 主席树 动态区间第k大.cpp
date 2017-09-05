#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e4+5;
const int maxm = 1e4+5;
int T[maxn],S[maxn],L[maxn*32],R[maxn*32],sum[maxn*32];
int sz[maxn],h[maxn];
int ul[maxn],ur[maxn];
int tot,num,n,q;

struct node{
    int l,r,k;
    bool flag;
}Q[maxm];

void build(int& rt,int l,int r)
{
    rt = ++tot;
    sum[rt]=0;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(L[rt],l,mid);
    build(R[rt],mid+1,r);
}

void update(int& rt,int pre,int l,int r,int x,int val)
{
    rt = ++tot;
    L[rt] = L[pre];
    R[rt] = R[pre];
    sum[rt] = sum[pre]+val;
    if(l==r) return;
    int mid = (l+r)>>1;
    if(x<=mid) update(L[rt],L[pre],l,mid,x,val);
    else update(R[rt],R[pre],mid+1,r,x,val);
}

int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int val)
{
    int res = lower_bound(h+1,h+1+num,sz[x])-h;
    while(x<=n)
    {
        update(S[x],S[x],1,num,res,val);
        x += lowbit(x);
    }
}

int Sum(int x,bool flag)
{
    int res=0;
    while(x>0)
    {
        if(flag) res += sum[L[ur[x]]];
        else res += sum[L[ul[x]]];
        x -= lowbit(x);
    }
    return res;
}

int query(int s,int e,int ts,int te,int l,int r,int k)
{
    if(l==r) return l;
    int mid = (l+r)>>1;
    int res = Sum(e,true)-Sum(s,false)+sum[L[te]]-sum[L[ts]];
    if(k<=res)
    {
        for(int i=e;i;i-=lowbit(i)) ur[i] = L[ur[i]];
        for(int i=s;i;i-=lowbit(i)) ul[i] = L[ul[i]];
        return query(s,e,L[ts],L[te],l,mid,k);
    }
    else
    {
        for(int i=e;i;i-=lowbit(i)) ur[i] = R[ur[i]];
        for(int i=s;i;i-=lowbit(i)) ul[i] = R[ul[i]];
        return query(s,e,R[ts],R[te],mid+1,r,k-res);
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[5];
        num=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%d",sz+i),h[++num]=sz[i];
        for(int i=1;i<=q;i++)
        {
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].k);
                Q[i].flag=true;
            }
            else
            {
                scanf("%d%d",&Q[i].l,&Q[i].r);
                Q[i].flag=false;
                h[++num]=Q[i].r;
            }
        }
        sort(h+1,h+1+num);
        int tmp = unique(h+1,h+1+num)-h-1;
        num = tmp;
        tot=0;
        build(T[0],1,num);
        for(int i=1;i<=n;i++) update(T[i],T[i-1],1,num,lower_bound(h+1,h+1+num,sz[i])-h,1);
        for(int i=1;i<=n;i++) S[i] = T[0];
        for(int i=1;i<=q;i++)
        {
            if(Q[i].flag)
            {
                for(int j=Q[i].r;j;j-=lowbit(j)) ur[j] = S[j];
                for(int j=Q[i].l-1;j;j-=lowbit(j)) ul[j] = S[j];
                printf("%d\n",h[query(Q[i].l-1,Q[i].r,T[Q[i].l-1],T[Q[i].r],1,num,Q[i].k)]);
            }
            else
            {
                add(Q[i].l,-1);
                sz[Q[i].l] = Q[i].r;
                add(Q[i].l,1);
            }
        }
    }
    return 0;
}
