#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e4+5;
int n,X[maxn];
struct Node{
    int l,r,h,f;
    Node(){}
    Node(int l,int r,int h,int f):l(l),r(r),h(h),f(f){}
    bool operator <(const Node b)const
    {
        return h<b.h;
    }
}node[maxn];

struct Tree{
    int l,r,cnt,sum,num;
    bool ld,rd;
}tree[maxn<<2];

void push_up(int rt)
{
    if(tree[rt].cnt)
    {
        tree[rt].ld=tree[rt].rd=true;
        tree[rt].sum = X[tree[rt].r+1]-X[tree[rt].l];
        tree[rt].num = 2;
    }
    else if(tree[rt].r==tree[rt].l)
    {
        tree[rt].sum=tree[rt].num=0;
        tree[rt].rd=tree[rt].ld=false;
    }
    else
    {
        tree[rt].ld = tree[rt<<1].ld;
        tree[rt].rd = tree[rt<<1|1].rd;
        tree[rt].sum = tree[rt<<1].sum+tree[rt<<1|1].sum;
        tree[rt].num = tree[rt<<1].num+tree[rt<<1|1].num;
        if(tree[rt<<1].rd && tree[rt<<1|1].ld) tree[rt].num -= 2;
    }
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].cnt=0;
    if(l==r)
    {
        tree[rt].sum=tree[rt].num=0;
        tree[rt].ld=tree[rt].rd=false;
        return;
    }
    int mid = (l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt);
}

void update(int rt,int l,int r,int val)
{
    if(tree[rt].l==l && tree[rt].r==r)
    {
        tree[rt].cnt += val;
        push_up(rt);
        return;
    }
    rt <<= 1;
    if(l<=tree[rt].r)
    {
        if(r<=tree[rt].r) update(rt,l,r,val);
        else
        {
            update(rt,l,tree[rt].r,val);
            update(rt+1,tree[rt+1].l,r,val);
        }
    }
    else update(rt+1,l,r,val);
    rt >>= 1;
    push_up(rt);
}

int main()
{
    while(~scanf("%d",&n))
    {
        int x1,x2,y1,y2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            node[i] = Node(x1,x2,y1,1);
            node[i+n] = Node(x1,x2,y2,-1);
            X[i] = x1, X[i+n] = x2;
        }
        n <<= 1;
        sort(X+1,X+1+n);
        sort(node+1,node+1+n);
        int m = unique(X+1,X+1+n)-X-1;
        build(1,1,m-1);
        int ans=0,last=0;
        for(int i=1;i<=n;i++)
        {
            int l = lower_bound(X+1,X+1+m,node[i].l)-X;
            int r = lower_bound(X+1,X+1+m,node[i].r)-X-1;
            update(1,l,r,node[i].f);
            ans += tree[1].num*(node[i+1].h-node[i].h);
            ans += abs(tree[1].sum-last);
            last = tree[1].sum;
        }
        printf("%d\n",ans);
    }
    return 0;
}
