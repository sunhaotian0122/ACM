#include <bits/stdc++.h>
using namespace std;

char mp[35][35];
//标记数组包括位置和钥匙的状态
bool vis[35][35][1025];  //把10个钥匙的状态压缩成一个数，最大2^10-1。
int tunnel[10][2][2];  //记录隧道的两个坐标
int cave[10];  //记录每个隧道的钥匙状态
int dis[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,k;

struct node{
    int x,y,key,step;  //key表示钥匙状态，step表示步数
}st;

bool check(node tmp)  //判断是否能走
{
    if(tmp.x<0 || tmp.x>=n || tmp.y<0 || tmp.y>=m) return false;
    else if(mp[tmp.x][tmp.y]=='#' || vis[tmp.x][tmp.y][tmp.key]) return false;
    else return true;
}

void bfs()
{
    memset(vis,false,sizeof(vis));
    node tmp,next;
    queue<node>q;
    q.push(st);
    vis[st.x][st.y][st.key]=true;
    while(!q.empty())
    {
        tmp=q.front(),q.pop();
        for(int i=0;i<4;i++)
        {
            next=tmp;
            next.x += dis[i][0];
            next.y += dis[i][1];
            next.step++;
            if(check(next))
            {
                if(mp[next.x][next.y]=='Y')
                {
                    printf("%d\n",next.step);
                    return;
                }
                else
                {
                    vis[next.x][next.y][next.key]=true;
                    q.push(next);
                }
            }
        }
        int id = mp[tmp.x][tmp.y]-'A';
        if(id>=0 && id<k) //判断当前点是否为隧道
        {
            int flag=(tmp.key>>id)&1;  //是否有当前隧道的钥匙
            if(flag)
            {
                next=tmp;
                next.step++;
                next.key = next.key|cave[id]; //根据隧道中的钥匙更新钥匙状态
                //到隧道另一头
                if(next.x==tunnel[id][0][0]&&next.y == tunnel[id][0][1])
                {
                    next.x=tunnel[id][1][0];
                    next.y=tunnel[id][1][1];
                }
                else
                {
                    next.x=tunnel[id][0][0];
                    next.y=tunnel[id][0][1];
                }
                if(!vis[next.x][next.y][next.key])
                {
                    vis[next.x][next.y][next.key]=true;
                    q.push(next);
                }
            }
        }
    }
    printf("Unreachable\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        memset(tunnel,-1,sizeof(tunnel));
        memset(cave,0,sizeof(cave));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%s",mp[i]);
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='X') //初始st
                {
                    st.x=i;
                    st.y=j;
                    st.key=st.step=0;
                    mp[i][j]='.';
                }
                else if(mp[i][j]-'A'>=0 && mp[i][j]-'A'<k)  //记录隧道两头坐标
                {
                    int id=mp[i][j]-'A';
                    if(tunnel[id][0][0]==-1)
                    {
                        tunnel[id][0][0]=i;
                        tunnel[id][0][1]=j;
                    }
                    else
                    {
                        tunnel[id][1][0]=i;
                        tunnel[id][1][1]=j;
                    }
                }
            }
        }
        int num;
        char tmp;
        scanf("%d",&num);
        while(num--)
        {
            getchar();
            scanf("%c",&tmp);
            st.key = st.key|(1<<(tmp-'A')); //更新初始钥匙状态
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                getchar();
                scanf("%c",&tmp);
                cave[i] = cave[i]|(1<<(tmp-'A')); //每个隧道中钥匙状态
            }
        }
        printf("Case #%d: ",ca);
        bfs();
    }
    return 0;
}
