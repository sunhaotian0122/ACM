#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int w,h;
int dis[4][2]={-1,0,0,-1,1,0,0,1};//上下左右走
struct node{
    int x,y;
};
int matrix[35][35],dist[35][35],vis[35][35],nx[35][35],ny[35][35];
//matrix保存地图状态，0是草，-1是墓碑，1是洞
//dist[i][j]保存到i，j的最短时间，vis保存访问状态
//nx，ny保存洞的终点坐标
int t[35][35],inqueue_num[35][35];
//t保存洞的用时，inqueue_num保存入队次数

bool SPFA()
{
    bool flag=true;
    node p,next;
    queue<node>q;
	//起点入队
    p.x=p.y=0;
    dist[0][0]=0;
    vis[0][0]=1;
    inqueue_num[0][0]++;
    q.push(p);
    while(!q.empty())
    {
        p = q.front(),q.pop();
        vis[p.x][p.y]=0;
        if(p.x==w-1&&p.y==h-1) continue;  //到达终点之后就不用再入队松弛了
        if(matrix[p.x][p.y])  //有洞
        {
            next.x = nx[p.x][p.y];
            next.y = ny[p.x][p.y];
            if(dist[next.x][next.y]>dist[p.x][p.y]+t[p.x][p.y])  //如果能更新
            {
                dist[next.x][next.y]=dist[p.x][p.y]+t[p.x][p.y];  //松弛
                if(!vis[next.x][next.y])
                {
                    q.push(next);
                    inqueue_num[next.x][next.y]++;
                    if(inqueue_num[next.x][next.y]>=w*h) return flag=false;  //存在负权回路
                    vis[next.x][next.y]=1;
                }
            }
            continue;  //有洞必须到洞的终点
        }
        for(int i=0;i<4;i++)  //上下左右遍历
        {
            next.x = p.x+dis[i][0];
            next.y = p.y+dis[i][1];
			//超出地图范围或有墓碑
            if(next.x<0 || next.x>w-1 || next.y<0 || next.y>h-1 || matrix[next.x][next.y]==-1) continue;
            if(dist[next.x][next.y]>dist[p.x][p.y]+1)
            {
                dist[next.x][next.y]=dist[p.x][p.y]+1;
                if(!vis[next.x][next.y])
                {
                    q.push(next);
                    inqueue_num[next.x][next.y]++;
                    if(inqueue_num[next.x][next.y]>=w*h) return flag=false;
                    vis[next.x][next.y]=1;
                }
            }
        }
    }
    return flag;
}

int main()
{
    while(~scanf("%d%d",&w,&h)&&w!=0&&h!=0)
    {
        int num,x1,x2,y1,y2,tmp;
        memset(matrix,0,sizeof(matrix));
        memset(dist,INF,sizeof(dist));
        memset(vis,0,sizeof(vis));
        memset(inqueue_num,0,sizeof(inqueue_num));
        scanf("%d",&num);
        while(num--)
        {
            scanf("%d%d",&x1,&y1);
            matrix[x1][y1] = -1;
        }
        scanf("%d",&num);
        while(num--)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&tmp);
            matrix[x1][y1]=1;
            nx[x1][y1]=x2,ny[x1][y1]=y2;
            t[x1][y1]=tmp;
        }
        if(SPFA())
        {
            if(dist[w-1][h-1]==INF) printf("Impossible\n"); //不能到达终点
            else printf("%d\n",dist[w-1][h-1]);
        }
        else printf("Never\n");  //有负权回路
    }
    return 0;
}
