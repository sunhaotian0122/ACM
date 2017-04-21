#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX=1<<19;
const int maxn=1e5+5;
struct segment_tree{
    long long left,right,add,sum;
}tree[MAX];
long long value[maxn];

void build_segment_tree(long long i,long long l,long long r)
{
    tree[i].left=l;
    tree[i].right=r;
    tree[i].add=0;
    if(l==r)
    {
        tree[i].sum=value[l];
        return;
    }
    build_segment_tree(i*2,l,(l+r)/2);
    build_segment_tree(i*2+1,(l+r)/2+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
}

void update_segment_tree(long long i,long long l,long long r,long long x)
{
    tree[i].sum+=(r-l+1)*x;
    if(tree[i].left==l&&tree[i].right==r)
    {
        tree[i].add+=x;
        return;
    }
    if(tree[i].add)
    {
        tree[i*2].add+=tree[i].add;
        tree[i*2+1].add+=tree[i].add;
        tree[i*2].sum+=(tree[i*2].right-tree[i*2].left+1)*tree[i].add;
        tree[i*2+1].sum+=(tree[i*2+1].right-tree[i*2+1].left+1)*tree[i].add;
        tree[i].add=0;
    }
    i<<=1;
    if(l<=tree[i].right)
    {
        if(r<=tree[i].right) update_segment_tree(i,l,r,x);
        else
        {
            update_segment_tree(i,l,tree[i].right,x);
            update_segment_tree(i+1,tree[i+1].left,r,x);
        }
    }
    else update_segment_tree(i+1,l,r,x);
}

long long query_segment_tree(long long i,long long l,long long r)
{
    if(tree[i].left==l&&tree[i].right==r)
    {
        return tree[i].sum;
    }
    if(tree[i].add)
    {
        tree[i*2].add+=tree[i].add;
        tree[i*2+1].add+=tree[i].add;
        tree[i*2].sum+=(tree[i*2].right-tree[i*2].left+1)*tree[i].add;
        tree[i*2+1].sum+=(tree[i*2+1].right-tree[i*2+1].left+1)*tree[i].add;
        tree[i].add=0;
    }
    i<<=1;
    if(l<=tree[i].right)
    {
        if(r<=tree[i].right) return query_segment_tree(i,l,r);
        else
        {
            return query_segment_tree(i,l,tree[i].right)+query_segment_tree(i+1,tree[i+1].left,r);
        }
    }
    else return query_segment_tree(i+1,l,r);
}

int main()
{
    long long n,q,a,b,c,i;
    char op;
    scanf("%lld%lld",&n,&q);
        for(i=1;i<=n;i++) scanf("%lld",&value[i]);
        build_segment_tree(1,1,n);
        while(q--)
        {
            getchar();
            scanf("%c%lld%lld",&op,&a,&b);
            switch(op)
            {
            case 'C':
                scanf("%lld",&c);
                update_segment_tree(1,a,b,c);
                break;
            case 'Q':
                printf("%lld\n",query_segment_tree(1,a,b));
                break;
            }
        }
    return 0;
}
