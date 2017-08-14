#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

const int maxn=1e6+5;
const double eps = 1e-8;

int n,a[maxn],last[maxn];

struct segment{
    int l,r;
    double ans,add;
}tree[maxn<<1];

void buildtree(int root,int l,int r,double x)
{
    tree[root].l=l;
    tree[root].r=r;
    if(l==r)
    {
        tree[root].ans = x*l;
        tree[root].add = 0;
        return;
    }
    int mid=(l+r)>>1;
    buildtree(root*2,l,mid,x);
    buildtree(root*2+1,mid+1,r,x);
    tree[root].ans = min(tree[root*2].ans,tree[root*2+1].ans);
    tree[root].add = 0;
}

void updatetree(int root,int l,int r,int x)
{
    if(tree[root].l==l&&tree[root].r==r)
    {
        tree[root].ans += x;
        tree[root].add += x;
        return;
    }
    if(tree[root].add>eps)
    {
        tree[root*2].ans += tree[root].add;
        tree[root*2+1].ans += tree[root].add;
        tree[root*2].add += tree[root].add;
        tree[root*2+1].add += tree[root].add;
        tree[root].add  = 0;
    }
    if(l<=tree[root*2].r)
    {
        if(r<=tree[root*2].r) updatetree(root*2,l,r,x);
        else
        {
            updatetree(root*2,l,tree[root*2].r,x);
            updatetree(root*2+1,tree[root*2+1].l,r,x);
        }
    }
    else updatetree(root*2+1,l,r,x);
    tree[root].ans = min(tree[root*2].ans,tree[root*2+1].ans);
}

double querytree(int root,int l,int r)
{
    if(tree[root].l==l&&tree[root].r==r)
    {
        return tree[root].ans;
    }
    if(tree[root].add>=eps)
    {
        tree[root*2].ans += tree[root].add;
        tree[root*2+1].ans += tree[root].add;
        tree[root*2].add += tree[root].add;
        tree[root*2+1].add += tree[root].add;
        tree[root].add  = 0;
    }
    if(l<=tree[root*2].r)
    {
        if(r<=tree[root*2].r) return querytree(root*2,l,r);
        else
        {
            return min(querytree(root*2,l,tree[root*2].r),querytree(root*2+1,tree[root*2+1].l,r));
        }
    }
    else return querytree(root*2+1,l,r);
}

bool check(double x)
{
    buildtree(1,1,n,x);
    memset(last,0,sizeof(last));
    for(int i=1;i<=n;i++)
    {
        updatetree(1,last[a[i]]+1,i,1);
        last[a[i]]=i;
        if(querytree(1,1,i)<=x*(i+1)) return true;
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        double l=0,r=1.0,mid;
        for(int i=0;i<20;i++)
        {
            mid = (l+r)/2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        printf("%.8f\n",r);
    }
    return 0;
}
