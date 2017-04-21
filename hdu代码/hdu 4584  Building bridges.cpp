#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char sz[45][45];
int ans[4],n,m,x0,y0,vis[45][45],num,dir[4][2]={-1,0,0,-1,0,1,1,0};

void dfs(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m || vis[x][y]) return;
    if(sz[x][y]=='H' && !(x==x0&&y==y0)) return;
    vis[x][y]=1;
    if(sz[x][y]=='C')
    {
        int tmp=abs(x-x0)+abs(y-y0);
        if(tmp<num)
        {
            ans[0]=x0;
            ans[1]=y0;
            ans[2]=x;
            ans[3]=y;
            num=tmp;
            return;
        }
        else if(tmp==num)
        {
            if(x0<ans[0]) {ans[0]=x0;ans[1]=y0;ans[2]=x;ans[3]=y;}
            if(x0==ans[0]&&y0<ans[1]) {ans[0]=x0;ans[1]=y0;ans[2]=x;ans[3]=y;}
            if(x0==ans[0]&&y0==ans[1]&&x<ans[2]) {ans[0]=x0;ans[1]=y0;ans[2]=x;ans[3]=y;}
            if(x0==ans[0]&&y0==ans[1]&&x==ans[2]&&y<ans[3]) {ans[0]=x0;ans[1]=y0;ans[2]=x;ans[3]=y;}
            return;
        }
        else return;
    }
    int xx,yy;
    for(int i=0;i<4;i++)
    {
        xx=x+dir[i][0];
        yy=y+dir[i][1];
        dfs(xx,yy);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&m&&n)
    {
        for(x0=0;x0<n;x0++) scanf("%s",sz[x0]);
        num=0x3f3f3f3f;
        for(x0=0;x0<n;x0++)
        {
            for(y0=0;y0<m;y0++)
            {
                if(sz[x0][y0]=='H')
                {
                    memset(vis,0,sizeof(vis));
                    dfs(x0,y0);
                }
            }
        }
        printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
    }
    return 0;
}
