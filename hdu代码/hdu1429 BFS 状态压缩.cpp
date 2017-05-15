#include <bits/stdc++.h>
using namespace std;

char mp[25][25];
bool vis[25][25][1025];  //���ÿ��λ�ü���Կ�׵�״̬�Ƿ��Ѿ�����
int dis[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,t;

struct node{
    int x,y,key,step;  //key����Կ��״̬
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
            if(next.step>=t)  //�ߵ��յ��ʱ��>=t
            {
                printf("-1\n");
                return;
            }
            if(check(next))
            {
                if(mp[next.x][next.y]=='^')  //�����յ�
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
                    //�����ﵱǰλ��ʱ�Ƿ��ж�ӦԿ��
                    int flag=(next.key>>(mp[next.x][next.y]-'A'))&1;
                    if(flag)
                    {
                        vis[next.x][next.y][next.key]=true;
                        q.push(next);
                    }
                }
                else
                {
                    //����Կ��״̬
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
    printf("-1\n");  //�����ѵ��յ�������ʱ��<t
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
                    //��Ϊ������û�п��ǡ�@������������԰�����Ϊ��.��
                    mp[i][j]='.';
                }
            }
            getchar();
        }
        bfs();
    }
    return 0;
}
