#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int MAX=1<<19;
const int maxn=200005;
struct segment_tree{
    int left,right,value;
}tree[MAX];
int vis[maxn],ans;

void build_segment_tree(int i,int l,int r)
{
    tree[i].left=l;
    tree[i].right=r;
    tree[i].value=0;
    if(l==r)
    {
        vis[l]=i;
        return;
    }
    build_segment_tree(i*2,l,(r+l)/2);
    build_segment_tree(i*2+1,(r+l)/2+1,r);
}

void update_segment_tree(int i)
{
    if(i==1) return;
    int p=i/2;
    tree[p].value=max(tree[p*2].value,tree[p*2+1].value);
    update_segment_tree(p);
}

void query_segment_tree(int i,int l,int r)
{
    if(tree[i].left==l&&tree[i].right==r)
    {
        ans = max(tree[i].value,ans);
        return;
    }
    if(l<=tree[i*2].right)
    {
        if(r<=tree[i*2].right) query_segment_tree(i*2,l,r);
        else
        {
            query_segment_tree(i*2,l,tree[i*2].right);
            query_segment_tree(i*2+1,tree[i*2+1].left,r);
        }
    }
    else query_segment_tree(i*2+1,l,r);
}

int main()
{
    int n,m,a,b;
    char op;
    build_segment_tree(1,1,200000);
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&tree[vis[i]].value);
            update_segment_tree(vis[i]);
        }
        while(m--)
        {
            getchar();
            scanf("%c%d%d",&op,&a,&b);
            switch(op)
            {
            case 'U':
                tree[vis[a]].value=b;
                update_segment_tree(vis[a]);
                break;
            case 'Q':
                ans=-1;
                query_segment_tree(1,a,b);
                printf("%d\n",ans);
                break;
            }
        }
    }
    return 0;
}
