#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 100005;
int ans[maxn][5][5];

struct node{
    int s[6],op2,op3,step;
};

int munion(node x)
{
    int num=0;
    for(int i=1;i<=4;i++)
    {
        num += x.s[i];
        num *= 10;
    }
    num += x.s[5];
    return num;
}

void bfs()
{
    node a,b,tmp;
    int t;
    memset(ans,INF,sizeof(ans));
    for(int i=1;i<=5;i++) a.s[i] = i;
    a.op2=3,a.op3=2,a.step=0;
    t = munion(a);
    ans[t][3][2]=0;
    queue<node>q;
    q.push(a);
    while(!q.empty())
    {
        b = q.front();q.pop();
        for(int i=2;i<=5;i++)
        {
            tmp = b;
            swap(tmp.s[i],tmp.s[i-1]);
            t = munion(tmp);
            tmp.step++;
            if(tmp.step>=ans[t][tmp.op2][tmp.op3]) continue;
            ans[t][tmp.op2][tmp.op3] = tmp.step;
            q.push(tmp);
        }
        if(b.op2>0)
        {
            for(int i=1;i<=5;i++)
            {
                tmp = b;
                tmp.s[i] = (tmp.s[i]+1)%10;
                tmp.op2--;
                tmp.step++;
                t = munion(tmp);
                if(tmp.step>=ans[t][tmp.op2][tmp.op3]) continue;
                ans[t][tmp.op2][tmp.op3] = tmp.step;
                q.push(tmp);
            }
        }
        if(b.op3>0)
        {
            for(int i=1;i<=5;i++)
            {
                tmp = b;
                tmp.s[i] = (tmp.s[i]*2)%10;
                tmp.op3--;
                tmp.step++;
                t = munion(tmp);
                if(tmp.step>=ans[t][tmp.op2][tmp.op3]) continue;
                ans[t][tmp.op2][tmp.op3] = tmp.step;
                q.push(tmp);
            }
        }
    }
}

int main()
{
    int n,fans;
    bfs();
    while(~scanf("%d",&n))
    {
        fans = INF;
        for(int i=0;i<=3;i++)
        {
            for(int j=0;j<=2;j++)
            {
                fans = min(fans,ans[n][i][j]);
            }
        }
        if(fans==INF) printf("-1\n");
        else printf("%d\n",fans);
    }
    return 0;
}
