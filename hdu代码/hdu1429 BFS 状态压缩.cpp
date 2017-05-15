#include <bits/stdc++.h>
using namespace std;

char mp[25][25];
bool vis[25][25][1025];  //标记每个位置及其钥匙的状态是否已经出现
int dis[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,t;

struct node{
    int x,y,key,step;  //key保存钥匙状态
}st;

bool check(node tmp)
{
    if(tmp.x<0 || tmp.x>=n || tmp.y<0 || tmp.y>=m) return false;
    else if(mp[tmp.x][tmp.y]=='*' || vis[tmp.x][tmp.y][tmp.key]) return false;
    else return true;
}

void bfs()
{
    node tmp,next;
    memset(vis,false,sizeof(vis));
    queue<node>q;
    q.push(st);
    vis[st.x][st.y][st.key]=true;
    while(!q.empty())
    {
        tmp = q.front(),q.pop();
        for(int i=0;i<4;i++)
        {
            next=tmp;
            next.x += dis[i][0];
            next.y += dis[i][1];
            next.step++;
            if(next.step>=t)  //走到终点的时间>=t
            {
                printf("-1\n");
                return;
            }
            if(check(next))
            {
                if(mp[next.x][next.y]=='^')  //到达终点
                {
                    if(next.step<t)
                    {
                        printf("%d\n",next.step);
                        return;
                    }
                    else
                    {
                        printf("-1\n");
                        return;
                    }
                }
                else if(mp[next.x][next.y]=='.')
                {
                    vis[next.x][next.y][next.key]=true;
                    q.push(next);
                }
                else if(isupper(mp[next.x][next.y]))
                {
                    //看到达当前位置时是否有对应钥匙
                    int flag=(next.key>>(mp[next.x][next.y]-'A'))&1;
                    if(flag)
                    {
                        vis[next.x][next.y][next.key]=true;
                        q.push(next);
                    }
                }
                else
                {
                    //更新钥匙状态
                    next.key = next.key|(1<<(mp[next.x][next.y]-'a'));
                    if(!vis[next.x][next.y][next.key])
                    {
                        vis[next.x][next.y][next.key]=true;
                        q.push(next);
                    }
                }
            }
        }
    }
    printf("-1\n");  //不能搜到终点且搜索时间<t
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&t))
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%c",&mp[i][j]);
                if(mp[i][j]=='@')
                {
                    st.x=i;
                    st.y=j;
                    st.key=st.step=0;
                    //因为我上面没有考虑‘@’的情况，所以把它置为‘.’
                    mp[i][j]='.';
                }
            }
            getchar();
        }
        bfs();
    }
    return 0;
}
