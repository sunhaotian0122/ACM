#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
int t,s,d;

struct Edge{
    int to,len; //存储边信息，to是到的点，len是时间
};
vector<Edge> edge[maxn];  //edge[i]记录与i点相连的边
//把i点和dist[i]打包放入优先队列。
//这里要注意pair是按照第一个元素的大小排序，如果相同才按照第二个，所以我们要把dist[i]包装在第一个元素上。
typedef pair<int,int> P;  
int dist[maxn];  //dist[i]记录从源点到i点的最短时间

void init()  //初始化
{
    for(int i=0;i<maxn;i++) edge[i].clear();
    memset(dist,INF,sizeof(dist));
}

void Dijkstra()
{
    priority_queue<P,vector<P>,greater<P> >pq;
    P p;
    Edge tmp;
    dist[0]=0;  //源点dist置0
    pq.push(P(0,0)); //源点加入队列
    while(!pq.empty())
    {
        p = pq.top(),pq.pop();
        int u = p.second; //得到当前节点
        for(int i=0;i<edge[u].size();i++)  //遍历与当前节点相连的节点
        {
            tmp = edge[u][i];
            if(dist[tmp.to]>dist[u]+tmp.len)
            {
                dist[tmp.to] = dist[u]+tmp.len;  //更新
                pq.push(P(dist[tmp.to],tmp.to));  
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d%d",&t,&s,&d))
    {
        init();
        int a,b,c;
        Edge tmp;
        while(t--)
        {
            scanf("%d%d%d",&a,&b,&c);
			//建边
            tmp.to = b,tmp.len = c;
            edge[a].push_back(tmp);
            tmp.to = a,tmp.len = c;
            edge[b].push_back(tmp);
        }
        while(s--)
        {
            scanf("%d",&a);
			//源点（家）和车站相连
            tmp.to = a,tmp.len = 0;
            edge[0].push_back(tmp);
            tmp.to = 0,tmp.len = 0;
            edge[a].push_back(tmp);
        }
        Dijkstra();
        int ans = INF;
        while(d--)
        {
            scanf("%d",&a);
            if(dist[a]<ans) ans = dist[a];  //得到所有终点的最短时间
        }
        printf("%d\n",ans);
    }
    return 0;
}
