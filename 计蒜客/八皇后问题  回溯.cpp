#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int sz[10][10],vis[3][20],ans,cnt;

void dfs(int x,int sum)
{
    if(x==8)
    {
        for(int i=1;i<=8;i++)
        {
            if(!vis[0][i] && !vis[1][x+i] && !vis[2][x-i+8])
            {
                sum += sz[x][i];
                if(sum>ans) ans=sum;
                //cnt++;
                return;
            }
        }
    }
    else
    {
        for(int i=1;i<=8;i++)
        {
            if(!vis[0][i] && !vis[1][x+i] && !vis[2][x-i+8])
            {
                vis[0][i]=vis[1][x+i]=vis[2][x-i+8]=1;
                dfs(x+1,sum+sz[x][i]);
                vis[0][i]=vis[1][x+i]=vis[2][x-i+8]=0;
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=1;i<=8;i++)
            for(int j=1;j<=8;j++)
                scanf("%d",&sz[i][j]);
        ans=-1;
        cnt=0;
        memset(vis,0,sizeof(vis));
        dfs(1,0);
        printf("%d\n",ans);
        //printf("%d\n",cnt);
    }
    return 0;
}
