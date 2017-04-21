#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;
int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};
map<string,int>mp;

struct node{
    char sz[3][3];
    int step,x,y;
};

int main()
{
    string start,finally,tmp;
    node n,x;
    int ans=INF,num=0;
    cin>>start>>finally;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            n.sz[i][j] = start[num++];
            if(n.sz[i][j]=='.')
            {
                n.x = i;
                n.y = j;
            }
        }
    n.step=0;
    queue<node>q;
    q.push(n);
    mp[start]++;
    while(!q.empty())
    {
        n=q.front(),q.pop();
        for(int i=0;i<4;i++)
        {
            x = n;
            x.x = n.x+xx[i];
            x.y = n.y+yy[i];
            if(x.x<0 || x.x>2 || x.y<0 || x.y>2) continue;
            x.step = n.step+1;
            x.sz[n.x][n.y] = x.sz[x.x][x.y];
            x.sz[x.x][x.y] = '.';
            tmp = "";
            for(int j=0;j<3;j++)
            {
                for(int k=0;k<3;k++)
                {
                    tmp += x.sz[j][k];
                }
            }
            if(tmp==finally)
            {
                if(x.step<ans) ans=x.step;
                continue;
            }
            if(!mp[tmp])
            {
                mp[tmp]++;
                q.push(x);
            }
        }
    }
    if(ans==INF) printf("-1\n");
    else printf("%d\n",ans);
    return 0;
}
