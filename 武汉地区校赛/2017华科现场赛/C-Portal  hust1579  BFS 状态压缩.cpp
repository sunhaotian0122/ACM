#include <bits/stdc++.h>
using namespace std;

char mp[35][35];
//����������λ�ú�Կ�׵�״̬
bool vis[35][35][1025];  //��10��Կ�׵�״̬ѹ����һ���������2^10-1��
int tunnel[10][2][2];  //��¼�������������
int cave[10];  //��¼ÿ�������Կ��״̬
int dis[4][2]={-1,0,0,-1,1,0,0,1};
int n,m,k;

struct node{
    int x,y,key,step;  //key��ʾԿ��״̬��step��ʾ����
}st;

bool check(node tmp)  //�ж��Ƿ�����
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
        if(id>=0 && id<k) //�жϵ�ǰ���Ƿ�Ϊ���
        {
            int flag=(tmp.key>>id)&1;  //�Ƿ��е�ǰ�����Կ��
            if(flag)
            {
                next=tmp;
                next.step++;
                next.key = next.key|cave[id]; //��������е�Կ�׸���Կ��״̬
                //�������һͷ
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
                if(mp[i][j]=='X') //��ʼst
                {
                    st.x=i;
                    st.y=j;
                    st.key=st.step=0;
                    mp[i][j]='.';
                }
                else if(mp[i][j]-'A'>=0 && mp[i][j]-'A'<k)  //��¼�����ͷ����
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
            st.key = st.key|(1<<(tmp-'A')); //���³�ʼԿ��״̬
        }
        for(int i=0;i<k;i++)
        {
            scanf("%d",&num);
            while(num--)
            {
                getchar();
                scanf("%c",&tmp);
                cave[i] = cave[i]|(1<<(tmp-'A')); //ÿ�������Կ��״̬
            }
        }
        printf("Case #%d: ",ca);
        bfs();
    }
    return 0;
}
