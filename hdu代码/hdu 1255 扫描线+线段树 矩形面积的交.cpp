#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e3+5;
int n;
double X[maxn];
struct Node{
    double l,r,h;
    int f;
    Node(){}
    Node(double l,double r,double h,int f):l(l),r(r),h(h),f(f){}
    bool operator <(const Node b)const
    {
        return h<b.h;
    }
}node[maxn];

struct Tree{
    int l,r,cnt;
    double len1,len2;
}tree[maxn<<2];

void push_up(int rt)
{
    if(tree[rt].cnt>=2)
        tree[rt].len1=tree[rt].len2=X[tree[rt].r+1]-X[tree[rt].l];
    else if(tree[rt].cnt==1)
    {
        tree[rt].len1 = X[tree[rt].r+1]-X[tree[rt].l];
        if(tree[rt].l==tree[rt].r)
            tree[rt].len2=0;
        else
            tree[rt].len2 = tree[rt<<1].len1+tree[rt<<1|1].len1;
    }
    else
    {
        if(tree[rt].l==tree[rt].r)
            tree[rt].len1=tree[rt].len2=0;
        else
        {
            tree[rt].len1 = tree[rt<<1].len1+tree[rt<<1|1].len1;
            tree[rt].len2 = tree[rt<<1].len2+tree[rt<<1|1].len2;
        }
    }
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    tree[rt].cnt=0;
    if(l==r)
    {
        tree[rt].len1=tree[rt].len2=0;
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double x1,x2,y1,y2;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            node[i] = Node(x1,x2,y1,1);
            node[i+n] = Node(x1,x2,y2,-1);
            X[i] = x1, X[i+n] = x2;
        }
        n <<= 1;
        sort(X+1,X+1+n);
        sort(node+1,node+1+n);
        int m = unique(X+1,X+1+n)-X-1;
        build(1,1,m-1);
        double ans=0;
        for(int i=1;i<n;i++)
        {
            int l = lower_bound(X+1,X+1+m,node[i].l)-X;
            int r = lower_bound(X+1,X+1+m,node[i].r)-X-1;
            update(1,l,r,node[i].f);
            ans += (node[i+1].h-node[i].h)*tree[1].len2;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
