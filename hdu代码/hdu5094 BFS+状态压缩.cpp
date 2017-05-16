#include <bits/stdc++.h>
using namespace std;

int mp[55][55];
bool vis[55][55][1025];
int door[55][55][55][55]; //两个位置之间的状态，-1代表可以走，0代表墙，>0代表门
int dis[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,p,k,s;

struct node{
    int x,y,key,step;
}st;

bool check(int a,int b,node tmp)
{
    if(tmp.x<1 || tmp.x>n || tmp.y<1 || tmp.y>m) return false;
    else if(vis[tmp.x][tmp.y][tmp.key] || door[a][b][tmp.x][tmp.y]==0) return false;
    else return true;
}

void bfs()
{
    node tmp,next;
    memset(vis,false,sizeof(vis));
    queue<node>q;
    vis[st.x][st.y][st.key]=true;
    q.push(st);
    while(!q.empty())
    {
        tmp=q.front(),q.pop();
        if(mp[tmp.x][tmp.y])
        {
            //先看看当前位置有没有钥匙，有的话更新钥匙状态
            tmp.key=tmp.key|mp[tmp.x][tmp.y];
            vis[tmp.x][tmp.y][tmp.key]=true;
        }
        for(int i=0;i<4;i++)
        {
            next=tmp;
            next.x += dis[i][0];
            next.y += dis[i][1];
            next.step++;
            if(check(tmp.x,tmp.y,next))
            {
                if(next.x==n&&next.y==m)
                {
                    printf("%d\n",next.step);
                    return;
                }
                int id=door[tmp.x][tmp.y][next.x][next.y];
                if(id>0) //两个位置之间有门
                {
                    int flag=(next.key>>id)&1; //看看有没有对应钥匙
                    if(flag)
                    {
                        vis[next.x][next.y][next.key]=true;
                        q.push(next);
                    }
                }
                else
                {
                    vis[next.x][next.y][next.key]=true;
                    q.push(next);
                }
            }
        }
    }
    printf("-1\n");
}

int main()
{
    int x1,x2,y1,y2,g;
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        memset(mp,0,sizeof(mp));
        memset(door,-1,sizeof(door));
        scanf("%d",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
            door[x1][y1][x2][y2]=g;
            door[x2][y2][x1][y1]=g;
        }
        scanf("%d",&s);
        for(int i=0;i<s;i++)
        {
            scanf("%d%d%d",&x1,&y1,&g);
            mp[x1][y1]=mp[x1][y1]|(1<<g);
        }
        st.x=st.y=1,st.key=st.step=0;
        bfs();
    }
    return 0;
}
