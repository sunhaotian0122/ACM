#include <cstdio>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
typedef long long ll;

const int maxn = 1e3+5;
const int maxm = 1e5+5;
int n,m,s,t,k,ans,head[maxn],A_head[maxn],dist[maxn],cnt1,cnt2;

struct Edge{
    int to,w,next;
}edge1[maxm],edge2[maxm];

struct A_Node{
    int p,g,h;
    bool operator < (A_Node tmp) const
    {
        return tmp.g+tmp.h < g+h;
    }
};

typedef pair<int,int> P;

void init()
{
    memset(head,-1,sizeof(head));
    memset(A_head,-1,sizeof(A_head));
    memset(dist,INF,sizeof(dist));
    cnt1=cnt2=0;
}

void add_edge(int from,int to,int w,bool flag)
{
    if(flag)
    {
        edge1[cnt1].to = to;
        edge1[cnt1].w = w;
        edge1[cnt1].next = head[from];
        head[from] = cnt1++;
    }
    else
    {
        edge2[cnt2].to = to;
        edge2[cnt2].w = w;
        edge2[cnt2].next = A_head[from];
        A_head[from] = cnt2++;
    }
}

void Dijkstra()
{
    priority_queue<P,vector<P>,greater<P> >pq;
    P p;
    dist[t] = 0;
    pq.push(P(0,t));
    while(!pq.empty())
    {
        p = pq.top(),pq.pop();
        int u = p.second;
        for(int i=head[u];i!=-1;i=edge1[i].next)
        {
            if(dist[edge1[i].to] > dist[u] + edge1[i].w)
            {
                dist[edge1[i].to] = dist[u]+edge1[i].w;
                pq.push(P(dist[edge1[i].to],edge1[i].to));
            }
        }
    }
}

void A_stra()
{
    A_Node cur,next;
    int num=0;
    priority_queue<A_Node>pq;
    if(s==t) k++;
    if(dist[s]==INF)
    {
        ans=-1;
        return;
    }
    cur.p = s;
    cur.g = 0;
    cur.h = dist[s];
    pq.push(cur);
    while(!pq.empty())
    {
        cur = pq.top(),pq.pop();
        if(cur.p==t) num++;
        if(num==k)
        {
            ans = cur.g;
            return;
        }
        for(int i=A_head[cur.p];i!=-1;i=edge2[i].next)
        {
            next.p = edge2[i].to;
            next.g = cur.g+edge2[i].w;
            next.h = dist[next.p];
            pq.push(next);
        }
    }
    ans = -1;
    return;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int u,v,w;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            add_edge(v,u,w,true);
            add_edge(u,v,w,false);
        }
        scanf("%d%d%d",&s,&t,&k);
        Dijkstra();
        A_stra();
        printf("%d\n",ans);
    }
    return 0;
}
