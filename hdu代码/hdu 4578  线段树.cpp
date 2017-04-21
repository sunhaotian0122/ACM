#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
const int MAX=1<<20;
const int maxn=1e5+5;
const int mod=10007;
struct segment_tree{
    int add,mul,val,sum1,sum2,sum3,left,right;
}tree[MAX];

void build_segment_tree(int i,int l,int r)
{
    tree[i].left=l;tree[i].right=r;
    tree[i].add=tree[i].val=tree[i].sum1=tree[i].sum2=tree[i].sum3=0;
    tree[i].mul=1;
    if(l==r) return;
    build_segment_tree(i*2,l,(l+r)/2);
    build_segment_tree(i*2+1,(l+r)/2+1,r);
}

void update_segment_tree(int i,int l,int r,int x,int judge)
{
    //cout<<"update "<<i<<" "<<l<<" "<<r<<endl;
    if(tree[i].left==l&&tree[i].right==r)
    {
        switch(judge)
        {
        case 1:
            tree[i].add=(tree[i].add+x)%mod;
            tree[i].sum3=(tree[i].sum3+3*tree[i].sum2%mod*x%mod+3*x%mod*x%mod*tree[i].sum1%mod+x*x%mod*x%mod*(r-l+1)%mod)%mod;
            tree[i].sum2=(tree[i].sum2+2*tree[i].sum1%mod*x%mod+x*x%mod*(r-l+1)%mod)%mod;
            tree[i].sum1=(tree[i].sum1+(r-l+1)*x%   mod)%mod;
            break;
        case 2:
            tree[i].mul=(tree[i].mul*x)%mod;
            tree[i].add=(tree[i].add*x)%mod;
            tree[i].sum3=tree[i].sum3*x%mod*x%mod*x%mod;
            tree[i].sum2=tree[i].sum2*x%mod*x%mod;
            tree[i].sum1=tree[i].sum1*x%mod;
            break;
        case 3:
            tree[i].val=x;
            tree[i].add=0;
            tree[i].mul=1;
            tree[i].sum3=x*x%mod*x%mod*(r-l+1)%mod;
            tree[i].sum2=x*x%mod*(r-l+1)%mod;
            tree[i].sum1=x*(r-l+1)%mod;
            break;
        }
        return;
    }
    int a=tree[i].add,b=tree[i].mul,c=tree[i].val;
    if(tree[i].val)
    {
        tree[i*2].mul=tree[i*2+1].mul=b;
        tree[i*2].add=tree[i*2+1].add=a;
        tree[i*2].val=tree[i*2+1].val=c;
        tree[i*2].sum3=(tree[i*2].right-tree[i*2].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2].sum2=(tree[i*2].right-tree[i*2].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2].sum1=(tree[i*2].right-tree[i*2].left+1)*(c*b%mod+a)%mod;
        tree[i*2+1].sum3=(tree[i*2+1].right-tree[i*2+1].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2+1].sum2=(tree[i*2+1].right-tree[i*2+1].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2+1].sum1=(tree[i*2+1].right-tree[i*2+1].left+1)*(c*b%mod+a)%mod;
        tree[i].val=tree[i].add=0;
        tree[i].mul=1;
    }
    else
    {
        tree[i*2].add=(tree[i*2].add*b+a)%mod;
        tree[i*2].mul=tree[i*2].mul*b%mod;
        tree[i*2+1].add=(tree[i*2+1].add*b+a)%mod;
        tree[i*2+1].mul=tree[i*2+1].mul*b%mod;
        tree[i*2].sum3=(b*b%mod*b%mod*tree[i*2].sum3%mod+3*b*b%mod*tree[i*2].sum2%mod*a%mod+3*a*a%mod*b%mod*tree[i*2].sum1%mod+a*a%mod*a%mod*(tree[i*2].right-tree[i*2].left+1)%mod)%mod;
        tree[i*2].sum2=(b*b%mod*tree[i*2].sum2%mod+2*b*a%mod*tree[i*2].sum1%mod+a*a%mod*(tree[i*2].right-tree[i*2].left+1)%mod)%mod;
        tree[i*2].sum1=(b*tree[i*2].sum1%mod+a*(tree[i*2].right-tree[i*2].left+1)%mod)%mod;
        tree[i*2+1].sum3=(b*b%mod*b%mod*tree[i*2+1].sum3%mod+3*b*b%mod*tree[i*2+1].sum2%mod*a%mod+3*a*a%mod*b%mod*tree[i*2+1].sum1%mod+a*a%mod*a%mod*(tree[i*2+1].right-tree[i*2+1].left+1)%mod)%mod;
        tree[i*2+1].sum2=(b*b%mod*tree[i*2+1].sum2%mod+2*b*a%mod*tree[i*2+1].sum1%mod+a*a%mod*(tree[i*2+1].right-tree[i*2+1].left+1)%mod)%mod;
        tree[i*2+1].sum1=(b*tree[i*2+1].sum1%mod+a*(tree[i*2+1].right-tree[i*2+1].left+1)%mod)%mod;
        tree[i].val=tree[i].add=0;
        tree[i].mul=1;
    }
    if(l<=tree[i*2].right)
    {
        if(r<=tree[i*2].right) update_segment_tree(i*2,l,r,x,judge);
        else
        {
            update_segment_tree(i*2,l,tree[i*2].right,x,judge);
            update_segment_tree(i*2+1,tree[i*2+1].left,r,x,judge);
        }
    }
    else update_segment_tree(i*2+1,l,r,x,judge);
    tree[i].sum1=(tree[i*2].sum1+tree[i*2+1].sum1)%mod;
    tree[i].sum2=(tree[i*2].sum2+tree[i*2+1].sum2)%mod;
    tree[i].sum3=(tree[i*2].sum3+tree[i*2+1].sum3)%mod;
}

int query_segment_tree(int i,int l,int r,int x)
{
    if(tree[i].right==r&&tree[i].left==l)
    {
        switch(x)
        {
        case 1: return tree[i].sum1;
        case 2: return tree[i].sum2;
        case 3: return tree[i].sum3;
        }
    }
    int a=tree[i].add,b=tree[i].mul,c=tree[i].val;
    if(tree[i].val)
    {
        tree[i*2].mul=tree[i*2+1].mul=b;
        tree[i*2].add=tree[i*2+1].add=a;
        tree[i*2].val=tree[i*2+1].val=c;
        tree[i*2].sum3=(tree[i*2].right-tree[i*2].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2].sum2=(tree[i*2].right-tree[i*2].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2].sum1=(tree[i*2].right-tree[i*2].left+1)*(c*b%mod+a)%mod;
        tree[i*2+1].sum3=(tree[i*2+1].right-tree[i*2+1].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2+1].sum2=(tree[i*2+1].right-tree[i*2+1].left+1)*(c*b%mod+a)%mod*(c*b%mod+a)%mod;
        tree[i*2+1].sum1=(tree[i*2+1].right-tree[i*2+1].left+1)*(c*b%mod+a)%mod;
        tree[i].val=tree[i].add=0;
        tree[i].mul=1;
    }
    else
    {
        tree[i*2].add=(tree[i*2].add*b%mod+a)%mod;
        tree[i*2].mul=tree[i*2].mul*b%mod;
        tree[i*2+1].add=(tree[i*2+1].add*b%mod+a)%mod;
        tree[i*2+1].mul=tree[i*2+1].mul*b%mod;
        tree[i*2].sum3=(b*b%mod*b%mod*tree[i*2].sum3%mod+3*b*b%mod*tree[i*2].sum2%mod*a%mod+3*a*a%mod*b%mod*tree[i*2].sum1%mod+a*a%mod*a%mod*(tree[i*2].right-tree[i*2].left+1)%mod)%mod;
        tree[i*2].sum2=(b*b%mod*tree[i*2].sum2%mod+2*b*a%mod*tree[i*2].sum1%mod+a*a%mod*(tree[i*2].right-tree[i*2].left+1)%mod)%mod;
        tree[i*2].sum1=(b*tree[i*2].sum1%mod+a*(tree[i*2].right-tree[i*2].left+1)%mod)%mod;
        tree[i*2+1].sum3=(b*b%mod*b%mod*tree[i*2+1].sum3%mod+3*b*b%mod*tree[i*2+1].sum2%mod*a%mod+3*a*a%mod*b%mod*tree[i*2+1].sum1%mod+a*a%mod*a%mod*(tree[i*2+1].right-tree[i*2+1].left+1)%mod)%mod;
        tree[i*2+1].sum2=(b*b%mod*tree[i*2+1].sum2%mod+2*b*a%mod*tree[i*2+1].sum1%mod+a*a%mod*(tree[i*2+1].right-tree[i*2+1].left+1)%mod)%mod;
        tree[i*2+1].sum1=(b*tree[i*2+1].sum1%mod+a*(tree[i*2+1].right-tree[i*2+1].left+1)%mod)%mod;
        tree[i].val=tree[i].add=0;
        tree[i].mul=1;
    }
    if(l<=tree[i*2].right)
    {
        if(r<=tree[i*2].right) return query_segment_tree(i*2,l,r,x);
        else return (query_segment_tree(i*2,l,tree[i*2].right,x)+query_segment_tree(i*2+1,tree[i*2+1].left,r,x))%mod;
    }
    else return query_segment_tree(i*2+1,l,r,x);
}

int main()
{
    int n,m,op,a,b,c;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        build_segment_tree(1,1,n);
        while(m--)
        {
            scanf("%d%d%d%d",&op,&a,&b,&c);
            if(op==4)
            {
                printf("%d\n",query_segment_tree(1,a,b,c));
            }
            else
            {
                update_segment_tree(1,a,b,c,op);
            }
        }
    }
    return 0;
}
